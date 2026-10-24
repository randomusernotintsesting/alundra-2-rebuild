#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <dwrite_1.h>
#include <wincodec.h>
#include "text_raster.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cwchar>
#include <climits>

template<class T> struct Com {
    T *p = nullptr;
    ~Com() { if (p) p->Release(); }
    T *operator->() const { return p; }
    T **put() { return &p; }
    Com() = default;
    Com(const Com &) = delete;
    Com &operator=(const Com &) = delete;
};
struct Apartment {
    HRESULT status = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    ~Apartment() { if (SUCCEEDED(status)) CoUninitialize(); }
    bool valid() const { return SUCCEEDED(status) || status == RPC_E_CHANGED_MODE; }
};
static wchar_t *wide(const char *s) {
    if (!s || std::strlen(s) >= INT_MAX) return nullptr;
    int n = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, s, -1, nullptr, 0);
    if (!n) return nullptr;
    wchar_t *result = static_cast<wchar_t *>(std::malloc(static_cast<size_t>(n) * sizeof(wchar_t)));
    if (result && !MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, s, -1, result, n)) {
        std::free(result); return nullptr;
    }
    return result;
}

class Renderer final : public IDWriteTextRenderer {
    IDWriteBitmapRenderTarget *target;
    IDWriteRenderingParams *params;
public:
    unsigned missing = 0;
    Renderer(IDWriteBitmapRenderTarget *t, IDWriteRenderingParams *p) : target(t), params(p) {}
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void **out) override {
        if (!out) return E_POINTER;
        *out = nullptr;
        if (iid != __uuidof(IUnknown) && iid != __uuidof(IDWritePixelSnapping) &&
            iid != __uuidof(IDWriteTextRenderer)) return E_NOINTERFACE;
        *out = static_cast<IDWriteTextRenderer *>(this); AddRef(); return S_OK;
    }
    ULONG STDMETHODCALLTYPE AddRef() override { return 1; }
    ULONG STDMETHODCALLTYPE Release() override { return 1; }
    HRESULT STDMETHODCALLTYPE IsPixelSnappingDisabled(void *, BOOL *disabled) override {
        *disabled = FALSE; return S_OK;
    }
    HRESULT STDMETHODCALLTYPE GetCurrentTransform(void *, DWRITE_MATRIX *matrix) override {
        *matrix = DWRITE_MATRIX{1, 0, 0, 1, 0, 0}; return S_OK;
    }
    HRESULT STDMETHODCALLTYPE GetPixelsPerDip(void *, FLOAT *value) override {
        *value = 1; return S_OK;
    }
    HRESULT STDMETHODCALLTYPE DrawGlyphRun(void *, FLOAT x, FLOAT y, DWRITE_MEASURING_MODE mode,
        const DWRITE_GLYPH_RUN *run, const DWRITE_GLYPH_RUN_DESCRIPTION *, IUnknown *) override {
        for (UINT32 i = 0; i < run->glyphCount; ++i) if (!run->glyphIndices[i]) ++missing;
        return target->DrawGlyphRun(x, y, mode, run, params, RGB(255, 255, 255), nullptr);
    }
    HRESULT line(FLOAT x, FLOAT y, FLOAT width, FLOAT offset, FLOAT thickness) {
        RECT rect = {static_cast<LONG>(std::floor(x)), static_cast<LONG>(std::floor(y + offset)),
            static_cast<LONG>(std::ceil(x + width)), static_cast<LONG>(std::ceil(y + offset + thickness))};
        return FillRect(target->GetMemoryDC(), &rect, static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH))) ? S_OK : E_FAIL;
    }
    HRESULT STDMETHODCALLTYPE DrawUnderline(void *, FLOAT x, FLOAT y,
        const DWRITE_UNDERLINE *u, IUnknown *) override {
        return line(x, y, u->width, u->offset, u->thickness);
    }
    HRESULT STDMETHODCALLTYPE DrawStrikethrough(void *, FLOAT x, FLOAT y,
        const DWRITE_STRIKETHROUGH *s, IUnknown *) override {
        return line(x, y, s->width, s->offset, s->thickness);
    }
    HRESULT STDMETHODCALLTYPE DrawInlineObject(void *context, FLOAT x, FLOAT y,
        IDWriteInlineObject *object, BOOL sideways, BOOL rtl, IUnknown *effect) override {
        return object->Draw(context, this, x, y, sideways, rtl, effect);
    }
};

static int rasterize(const char *s, double size, int width, int bold, bool title, A2TextRaster *out) {
    if (!s || !out || !std::isfinite(size) || size < 6 || size > 128 ||
        width < 0 || width > 4096 || std::strlen(s) > 16384) return 0;
    wchar_t *text = wide(s);
    if (!text) return 0;
    Com<IDWriteFactory> factory;
    Com<IDWriteTextFormat> format;
    Com<IDWriteTextLayout> layout;
    HRESULT hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory),
        reinterpret_cast<IUnknown **>(factory.put()));
    if (SUCCEEDED(hr)) hr = factory->CreateTextFormat(title ? L"Georgia" : L"Segoe UI", nullptr,
        bold ? DWRITE_FONT_WEIGHT_BOLD : DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL,
        DWRITE_FONT_STRETCH_NORMAL, static_cast<FLOAT>(size), L"", format.put());
    if (SUCCEEDED(hr)) hr = format->SetWordWrapping(width ? DWRITE_WORD_WRAPPING_WRAP : DWRITE_WORD_WRAPPING_NO_WRAP);
    if (SUCCEEDED(hr)) hr = factory->CreateTextLayout(text, static_cast<UINT32>(std::wcslen(text)),
        format.p, static_cast<FLOAT>(width ? (width > 4 ? width - 4 : width) : 4092), 4092, layout.put());
    std::free(text);
    DWRITE_TEXT_METRICS metrics = {};
    if (FAILED(hr) || FAILED(layout->GetMetrics(&metrics)) || metrics.height > 4092 ||
        (!width && metrics.widthIncludingTrailingWhitespace > 4092)) return 0;
    A2TextRaster result = {};
    result.width = width ? width : static_cast<int>(std::ceil(metrics.widthIncludingTrailingWhitespace)) + 4;
    result.height = static_cast<int>(std::ceil(metrics.height)) + 4;
    result.advance = metrics.widthIncludingTrailingWhitespace;
    Com<IDWriteGdiInterop> interop;
    Com<IDWriteBitmapRenderTarget> bitmap;
    Com<IDWriteRenderingParams> params;
    if (FAILED(factory->GetGdiInterop(interop.put())) ||
        FAILED(interop->CreateBitmapRenderTarget(nullptr, result.width, result.height, bitmap.put())) ||
        FAILED(factory->CreateRenderingParams(params.put())) || FAILED(bitmap->SetPixelsPerDip(1))) return 0;
    Com<IDWriteBitmapRenderTarget1> grayscale;
    if (SUCCEEDED(bitmap->QueryInterface(__uuidof(IDWriteBitmapRenderTarget1), reinterpret_cast<void **>(grayscale.put()))))
        grayscale->SetTextAntialiasMode(DWRITE_TEXT_ANTIALIAS_MODE_GRAYSCALE);
    HDC dc = bitmap->GetMemoryDC();
    if (!PatBlt(dc, 0, 0, result.width, result.height, BLACKNESS)) return 0;
    Renderer renderer(bitmap.p, params.p);
    if (FAILED(layout->Draw(nullptr, &renderer, 2, 2))) return 0;
    GdiFlush();
    DIBSECTION dib = {};
    if (!GetObjectW(GetCurrentObject(dc, OBJ_BITMAP), sizeof dib, &dib) ||
        !dib.dsBm.bmBits || dib.dsBm.bmBitsPixel != 32 || dib.dsBm.bmWidthBytes < result.width * 4) return 0;
    result.pixels = static_cast<uint32_t *>(std::malloc(static_cast<size_t>(result.width) * result.height * 4));
    if (!result.pixels) return 0;
    for (int y = 0; y < result.height; ++y) {
        /* DirectWrite GetMemoryDC guarantees a 32-bit top-down DIB. */
        const unsigned char *src = static_cast<const unsigned char *>(dib.dsBm.bmBits) +
            static_cast<size_t>(y) * dib.dsBm.bmWidthBytes;
        for (int x = 0; x < result.width; ++x) {
            unsigned alpha = src[x * 4];
            if (src[x * 4 + 1] > alpha) alpha = src[x * 4 + 1];
            if (src[x * 4 + 2] > alpha) alpha = src[x * 4 + 2];
            result.pixels[static_cast<size_t>(y) * result.width + x] = (alpha << 24) | 0xffffffu;
        }
    }
    result.missing_glyphs = renderer.missing;
    *out = result; return 1;
}
int a2_text_rasterize(const char *s, double size, int width, int bold, A2TextRaster *out) {
    return rasterize(s, size, width, bold, false, out);
}
int a2_text_rasterize_title(const char *s, double size, int width, int bold, A2TextRaster *out) {
    return rasterize(s, size, width, bold, true, out);
}
void a2_text_raster_free(A2TextRaster *r) {
    if (r) { std::free(r->pixels); std::memset(r, 0, sizeof *r); }
}

int a2_image_raster_load(const char *path, A2TextRaster *out) {
    if (!out) return 0;
    wchar_t *filename = wide(path);
    if (!filename) return 0;
    Apartment apartment;
    Com<IWICImagingFactory> factory;
    Com<IWICBitmapDecoder> decoder;
    Com<IWICBitmapFrameDecode> frame;
    Com<IWICFormatConverter> converter;
    HRESULT hr = apartment.valid() ? CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER,
        __uuidof(IWICImagingFactory), reinterpret_cast<void **>(factory.put())) : E_FAIL;
    if (SUCCEEDED(hr)) hr = factory->CreateDecoderFromFilename(filename, nullptr, GENERIC_READ,
        WICDecodeMetadataCacheOnDemand, decoder.put());
    std::free(filename);
    UINT width = 0, height = 0;
    if (FAILED(hr) || FAILED(decoder->GetFrame(0, frame.put())) || FAILED(frame->GetSize(&width, &height)) ||
        !width || !height || width > 8192 || height > 8192 ||
        FAILED(factory->CreateFormatConverter(converter.put())) ||
        FAILED(converter->Initialize(frame.p, GUID_WICPixelFormat32bppBGRA, WICBitmapDitherTypeNone,
            nullptr, 0, WICBitmapPaletteTypeCustom))) return 0;
    A2TextRaster result = {};
    result.width = static_cast<int>(width); result.height = static_cast<int>(height);
    UINT bytes = width * height * 4;
    result.pixels = static_cast<uint32_t *>(std::malloc(bytes));
    if (!result.pixels) return 0;
    if (FAILED(converter->CopyPixels(nullptr, width * 4, bytes, reinterpret_cast<BYTE *>(result.pixels)))) {
        a2_text_raster_free(&result); return 0;
    }
    *out = result; return 1;
}
int a2_image_raster_write_png(const char *path, const uint32_t *pixels, int width, int height, int pitch) {
    if (!pixels || width < 1 || height < 1 || width > 8192 || height > 8192 || pitch < width || pitch > INT_MAX / 4)
        return 0;
    wchar_t *filename = wide(path);
    if (!filename) return 0;
    Apartment apartment;
    Com<IWICImagingFactory> factory;
    Com<IWICStream> stream;
    Com<IWICBitmapEncoder> encoder;
    Com<IWICBitmapFrameEncode> frame;
    HRESULT hr = apartment.valid() ? CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER,
        __uuidof(IWICImagingFactory), reinterpret_cast<void **>(factory.put())) : E_FAIL;
    if (SUCCEEDED(hr)) hr = factory->CreateStream(stream.put());
    if (SUCCEEDED(hr)) hr = stream->InitializeFromFilename(filename, GENERIC_WRITE);
    std::free(filename);
    if (FAILED(hr) || FAILED(factory->CreateEncoder(GUID_ContainerFormatPng, nullptr, encoder.put())) ||
        FAILED(encoder->Initialize(stream.p, WICBitmapEncoderNoCache)) ||
        FAILED(encoder->CreateNewFrame(frame.put(), nullptr)) || FAILED(frame->Initialize(nullptr)) ||
        FAILED(frame->SetSize(width, height))) return 0;
    WICPixelFormatGUID format = GUID_WICPixelFormat32bppBGRA;
    if (FAILED(frame->SetPixelFormat(&format)) || format != GUID_WICPixelFormat32bppBGRA) return 0;
    for (int y = 0; y < height; ++y)
        if (FAILED(frame->WritePixels(1, width * 4, width * 4,
            reinterpret_cast<BYTE *>(const_cast<uint32_t *>(pixels + static_cast<size_t>(y) * pitch))))) return 0;
    return SUCCEEDED(frame->Commit()) && SUCCEEDED(encoder->Commit());
}
