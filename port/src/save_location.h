#ifndef A2_SAVE_LOCATION_H
#define A2_SAVE_LOCATION_H
/* SCPS-10115 GAME00 800EEF10: display names for the original card browser.
 * The scene loader uses the checkpoint's map and coordinates independently. */
#define A2_SAVE_FREE_LOCATION 0xffffu
static const unsigned short a2_save_locations[40] = {
    14,20,10,24,59,331,28,297,106,121,418,422,185,142,152,89,163,174,472,222,
    286,350,414,490,178,450,412,472,118,424,430,75,243,311,489,305,271,232,281,271
};
static inline unsigned a2_save_location_index(unsigned scene) {
    for(unsigned i=0;i<40;i++)if(a2_save_locations[i]==scene)return i;
    return A2_SAVE_FREE_LOCATION;
}
static inline int a2_save_location_valid(unsigned index,unsigned scene) {
    /* GAME00 loads three-digit map resource names. Zero is the title. */
    return scene>0 && scene<1000 &&
        (index==A2_SAVE_FREE_LOCATION || (index<40 && a2_save_locations[index]==scene));
}
#endif
