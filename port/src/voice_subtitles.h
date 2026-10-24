#ifndef A2_VOICE_SUBTITLES_H
#define A2_VOICE_SUBTITLES_H
#include <stdint.h>
/* Spoken US English, indexed by exact native voice name and source time.
 * Immutable UTF-8, at most two lines. Gaps and unavailable cues return NULL. */
const char *a2_english_subtitle(const char *name,uint32_t milliseconds);
/* language0 is the Russian translation of this same English recording;
 * language2 is its English transcript. Other languages return NULL. */
const char *a2_voice_subtitle(const char *name,uint32_t milliseconds,int language);
/* Independent English-audio setting0 follows text (RU=>RU, otherwise EN),
 * 1 forces Russian, 2 forces English. */
int a2_voice_subtitle_language(int setting,int text_language);
#endif
