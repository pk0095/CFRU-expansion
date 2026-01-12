#include "global.h"
#include "constants/event_objects.h"
#include "constants/species.h"
#include "new/character_customization.h"

extern const struct SpritePalette gObjectEventSpritePalettes13[];
extern const struct SpritePalette gObjectEventSpritePalettes15[];
extern const struct SpritePalette gObjectEventSpritePalettes17[];

static const struct SpritePalette* const sObjectEventSpritePalettesTables[] = {
    gObjectEventSpritePalettes13,
    gObjectEventSpritePalettes15,
    gObjectEventSpritePalettes17,
};