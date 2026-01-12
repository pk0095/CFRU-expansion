#include "defines.h"
#include "defines_battle.h"
#include "../include/dynamic_placeholder_text_util.h"
#include "../include/event_object_movement.h"
#include "../include/field_effect_helpers.h"
#include "../include/field_player_avatar.h"
#include "../include/link.h"
#include "../include/random.h"
#include "../include/sprite.h"
#include "../include/trainer_pokemon_sprites.h"
#include "../include/constants/character_customization.h"
#include "../include/constants/event_object_movement_constants.h"
#include "../include/constants/event_objects.h"
#include "../include/constants/trainers.h"

#include "../include/new/character_customization.h"
#include "../include/new/follow_me.h"
#include "../include/new/frontier.h"
#include "../include/new/multi.h"
#include "../include/new/util.h"

/*
character_customization.c
	functions for altering the player's sprite based on the current sprite/palette selections

tables to edit:
	gOverworldTableSwitcher
	sPlayerAvatarGfxIds

*/

#ifdef UNBOUND
//extern const u16 MalePlayer_Trainer_Outfit_RedPal[];
extern const u16 MalePlayer_Trainer_Outfit_BlackPal[];
extern const u16 MalePlayer_Trainer_Outfit_BluePal[];
extern const u16 MalePlayer_Trainer_Outfit_GrayPal[];
extern const u16 MalePlayer_Trainer_Outfit_PurplePal[];
extern const u16 MalePlayer_Trainer_Outfit_YellowPal[];
extern const u16 MalePlayer_Trainer_Outfit_GreenPal[];
extern const u16 MalePlayer_Trainer_Outfit_TealPal[];
extern const u16 MalePlayer_Trainer_Outfit_BrownPal[];
extern const u16 MalePlayer_Trainer_Outfit_OrangePal[];
extern const u16 MalePlayer_Trainer_Outfit_PinkPal[];

//extern const u16 MalePlayer_Trainer_Trim_GoldPal[];
extern const u16 MalePlayer_Trainer_Trim_BlackPal[];
extern const u16 MalePlayer_Trainer_Trim_BluePal[];
extern const u16 MalePlayer_Trainer_Trim_BrownPal[];
extern const u16 MalePlayer_Trainer_Trim_BrownOrangePal[];
extern const u16 MalePlayer_Trainer_Trim_GreenPal[];
extern const u16 MalePlayer_Trainer_Trim_LightBluePal[];
extern const u16 MalePlayer_Trainer_Trim_LightGreenPal[];
extern const u16 MalePlayer_Trainer_Trim_LightPinkPal[];
extern const u16 MalePlayer_Trainer_Trim_LightRedPal[];
extern const u16 MalePlayer_Trainer_Trim_OrangePal[];
extern const u16 MalePlayer_Trainer_Trim_PinkPal[];
extern const u16 MalePlayer_Trainer_Trim_PurplePal[];
extern const u16 MalePlayer_Trainer_Trim_Purple2Pal[];
extern const u16 MalePlayer_Trainer_Trim_RedPal[];
extern const u16 MalePlayer_Trainer_Trim_TealPal[];
extern const u16 MalePlayer_Trainer_Trim_WhitePal[];
extern const u16 MalePlayer_Trainer_Trim_YellowPal[];

//extern const u16 MalePlayer_Trainer_Hair_BrownPal[];
extern const u16 MalePlayer_Trainer_Hair_BlondePal[];
extern const u16 MalePlayer_Trainer_Hair_LBlondePal[];
extern const u16 MalePlayer_Trainer_Hair_BlackPal[];
extern const u16 MalePlayer_Trainer_Hair_RedPal[];
extern const u16 MalePlayer_Trainer_Hair_GreenPal[];
extern const u16 MalePlayer_Trainer_Hair_PurplePal[];
extern const u16 MalePlayer_Trainer_Hair_BluePal[];
extern const u16 MalePlayer_Trainer_Hair_TealPal[];
extern const u16 MalePlayer_Trainer_Hair_PinkPal[];
extern const u16 MalePlayer_Trainer_Hair_SilverPal[];
extern const u16 MalePlayer_Trainer_Hair_GreyPal[];
extern const u16 MalePlayer_Trainer_Hair_WhitePal[];
extern const u16 MalePlayer_Trainer_Hair_OrangePal[];
extern const u16 MalePlayer_Trainer_Hair_LightBrownPal[];
extern const u16 MalePlayer_Trainer_Hair_DarkBrownPal[];

//extern const u16 MalePlayer_Trainer_Skin_LightPal[];
extern const u16 MalePlayer_Trainer_Skin_LBrownPal[];
extern const u16 MalePlayer_Trainer_Skin_BrownPal[];
extern const u16 MalePlayer_Trainer_Skin_DarkBrownPal[];
extern const u16 MalePlayer_Trainer_Skin_YellowPal[];

//extern const u16 MalePlayer_Champion_RedPal[];
extern const u16 MalePlayer_Champion_RedPal[];
extern const u16 MalePlayer_Champion_BluePal[];
extern const u16 MalePlayer_Champion_TealPal[];
extern const u16 MalePlayer_Champion_LimePal[];
extern const u16 MalePlayer_Champion_GreenPal[];
extern const u16 MalePlayer_Champion_YellowPal[];
extern const u16 MalePlayer_Champion_BlackPal[];
extern const u16 MalePlayer_Champion_GrayPal[];
extern const u16 MalePlayer_Champion_WhitePal[];
extern const u16 MalePlayer_Champion_PurplePal[];
extern const u16 MalePlayer_Champion_PinkPal[];
extern const u16 MalePlayer_Champion_BrownPal[];
extern const u16 MalePlayer_Champion_OrangePal[];

//extern const u16 MalePlayer_Champion_Trim_LightOrangePal[];
extern const u16 MalePlayer_Champion_Trim_RedPal[];
extern const u16 MalePlayer_Champion_Trim_BluePal[];
extern const u16 MalePlayer_Champion_Trim_TealPal[];
extern const u16 MalePlayer_Champion_Trim_LimePal[];
extern const u16 MalePlayer_Champion_Trim_GreenPal[];
extern const u16 MalePlayer_Champion_Trim_YellowPal[];
extern const u16 MalePlayer_Champion_Trim_BlackPal[];
extern const u16 MalePlayer_Champion_Trim_GrayPal[];
extern const u16 MalePlayer_Champion_Trim_WhitePal[];
extern const u16 MalePlayer_Champion_Trim_PurplePal[];
extern const u16 MalePlayer_Champion_Trim_PinkPal[];
extern const u16 MalePlayer_Champion_Trim_BrownPal[];
extern const u16 MalePlayer_Champion_Trim_OrangePal[];

//extern const u16 MalePlayer_Marlon_RedPal[];
extern const u16 MalePlayer_Marlon_BluePal[];
extern const u16 MalePlayer_Marlon_TealPal[];
extern const u16 MalePlayer_Marlon_GreenPal[];
extern const u16 MalePlayer_Marlon_LimePal[];
extern const u16 MalePlayer_Marlon_YellowPal[];
extern const u16 MalePlayer_Marlon_BlackPal[];
extern const u16 MalePlayer_Marlon_WhitePal[];
extern const u16 MalePlayer_Marlon_PurplePal[];
extern const u16 MalePlayer_Marlon_PinkPal[];
extern const u16 MalePlayer_Marlon_BrownPal[];
extern const u16 MalePlayer_Marlon_OrangePal[];
extern const u16 MalePlayer_Marlon_BrightRedPal[];
	
static const u16* sPlayerOutfitColours[] =
{
	NULL /*MalePlayer_Trainer_Outfit_RedPal*/, //Defaults are loaded from elsewhere
	MalePlayer_Trainer_Outfit_BlackPal,
	MalePlayer_Trainer_Outfit_BluePal,
	MalePlayer_Trainer_Outfit_TealPal,
	MalePlayer_Trainer_Outfit_GrayPal,
	MalePlayer_Trainer_Outfit_GreenPal,
	MalePlayer_Trainer_Outfit_YellowPal,
	MalePlayer_Trainer_Outfit_OrangePal,
	MalePlayer_Trainer_Outfit_BrownPal,
	MalePlayer_Trainer_Outfit_PurplePal,
	MalePlayer_Trainer_Outfit_PinkPal,
};

static const u16* sPlayerTrimColours[] =
{
	NULL /*MalePlayer_Trainer_Trim_GoldPal*/,
	MalePlayer_Trainer_Trim_RedPal,
	MalePlayer_Trainer_Trim_LightRedPal,
	MalePlayer_Trainer_Trim_OrangePal,
	MalePlayer_Trainer_Trim_YellowPal,
	MalePlayer_Trainer_Trim_GreenPal,
	MalePlayer_Trainer_Trim_LightGreenPal,
	MalePlayer_Trainer_Trim_BrownPal,
	MalePlayer_Trainer_Trim_BrownOrangePal,
	MalePlayer_Trainer_Trim_BlackPal,
	MalePlayer_Trainer_Trim_WhitePal,
	MalePlayer_Trainer_Trim_BluePal,
	MalePlayer_Trainer_Trim_TealPal,
	MalePlayer_Trainer_Trim_LightBluePal,
	MalePlayer_Trainer_Trim_PinkPal,
	MalePlayer_Trainer_Trim_LightPinkPal,
	MalePlayer_Trainer_Trim_Purple2Pal,
	MalePlayer_Trainer_Trim_PurplePal,
};

static const u16* sPlayerHairColours[] =
{
	NULL /*MalePlayer_Trainer_Hair_BrownPal*/,
	MalePlayer_Trainer_Hair_LBlondePal,
	MalePlayer_Trainer_Hair_BlondePal,
	MalePlayer_Trainer_Hair_BlackPal,
	MalePlayer_Trainer_Hair_RedPal,
	MalePlayer_Trainer_Hair_GreenPal,
	MalePlayer_Trainer_Hair_PurplePal,
	MalePlayer_Trainer_Hair_BluePal,
	MalePlayer_Trainer_Hair_PinkPal,
	MalePlayer_Trainer_Hair_SilverPal,
	MalePlayer_Trainer_Hair_GreyPal,
	MalePlayer_Trainer_Hair_WhitePal,
	MalePlayer_Trainer_Hair_TealPal,
	MalePlayer_Trainer_Hair_OrangePal,
	MalePlayer_Trainer_Hair_LightBrownPal,
	MalePlayer_Trainer_Hair_DarkBrownPal,
};

static const u16* sPlayerSkinColours[] =
{
    NULL /*MalePlayer_Trainer_Skin_LightPal*/,
    MalePlayer_Trainer_Skin_LBrownPal,
    MalePlayer_Trainer_Skin_BrownPal,
    MalePlayer_Trainer_Skin_DarkBrownPal,
    MalePlayer_Trainer_Skin_YellowPal,
};

static const u16* sPlayerChampionOutfitColours[] =
{
	NULL /*MalePlayer_Champion_ReddishOrangePal*/, //Defaults are loaded from elsewhere
	MalePlayer_Champion_RedPal,
	MalePlayer_Champion_BluePal,
	MalePlayer_Champion_TealPal,
	MalePlayer_Champion_LimePal,
	MalePlayer_Champion_GreenPal,
	MalePlayer_Champion_YellowPal,
	MalePlayer_Champion_BlackPal,
	MalePlayer_Champion_GrayPal,
	MalePlayer_Champion_WhitePal,
	MalePlayer_Champion_PinkPal,
	MalePlayer_Champion_PurplePal,
	MalePlayer_Champion_BrownPal,
	MalePlayer_Champion_OrangePal,
};

static const u16* sPlayerChampionTrimColours[] =
{
	NULL /*MalePlayer_Champion_Trim_LightOrangePal*/, //Defaults are loaded from elsewhere
	MalePlayer_Champion_Trim_RedPal,
	MalePlayer_Champion_Trim_BluePal,
	MalePlayer_Champion_Trim_TealPal,
	MalePlayer_Champion_Trim_LimePal,
	MalePlayer_Champion_Trim_GreenPal,
	MalePlayer_Champion_Trim_YellowPal,
	MalePlayer_Champion_Trim_BlackPal,
	MalePlayer_Champion_Trim_GrayPal,
	MalePlayer_Champion_Trim_WhitePal,
	MalePlayer_Champion_Trim_PinkPal,
	MalePlayer_Champion_Trim_PurplePal,
	MalePlayer_Champion_Trim_BrownPal,
	MalePlayer_Champion_Trim_OrangePal,
};

static const u16* sPlayerMarlonOutfitColours[] =
{
	NULL /*MalePlayer_Marlon_RedPal*/, //Defaults are loaded from elsewhere
	MalePlayer_Marlon_BluePal,
	MalePlayer_Marlon_TealPal,
	MalePlayer_Marlon_LimePal,
	MalePlayer_Marlon_GreenPal,
	MalePlayer_Marlon_YellowPal,
	MalePlayer_Marlon_BlackPal,
	MalePlayer_Marlon_WhitePal,
	MalePlayer_Marlon_PurplePal,
	MalePlayer_Marlon_PinkPal,
	MalePlayer_Marlon_BrownPal,
	MalePlayer_Marlon_OrangePal,
	MalePlayer_Marlon_BrightRedPal,
};
#endif

#ifdef EXISTING_OW_TABLE_ADDRESS
	#define gOverworldTableSwitcher ((struct EventObjectGraphicsInfo***) EXISTING_OW_TABLE_ADDRESS)
#elif defined UNBOUND //For Pokemon Unbound
	const struct EventObjectGraphicsInfo** const gOverworldTableSwitcher[] =
	{
		(NPCPtr*) 0x88110E0,
		(NPCPtr*) 0x88B2720,
		(NPCPtr*) 0x88B2B20,
	};

#else //Modify this

extern const struct EventObjectGraphicsInfo gFollowerMonGfxTable0[];
extern const struct EventObjectGraphicsInfo gFollowerMonGfxTable1[];
extern const struct EventObjectGraphicsInfo gFollowerMonGfxTable2[];

static NPCPtr sOverworldTable2[] =
{
	&gFollowerMonGfxTable0[0],
	&gFollowerMonGfxTable0[1],
	&gFollowerMonGfxTable0[2],
	&gFollowerMonGfxTable0[3],
	&gFollowerMonGfxTable0[4],
	&gFollowerMonGfxTable0[5],
	&gFollowerMonGfxTable0[6],
	&gFollowerMonGfxTable0[7],
	&gFollowerMonGfxTable0[8],
	&gFollowerMonGfxTable0[9],
	&gFollowerMonGfxTable0[10],
	&gFollowerMonGfxTable0[11],
	&gFollowerMonGfxTable0[12],
	&gFollowerMonGfxTable0[13],
	&gFollowerMonGfxTable0[14],
	&gFollowerMonGfxTable0[15],
	&gFollowerMonGfxTable0[16],
	&gFollowerMonGfxTable0[17],
	&gFollowerMonGfxTable0[18],
	&gFollowerMonGfxTable0[19],
	&gFollowerMonGfxTable0[20],
	&gFollowerMonGfxTable0[21],
	&gFollowerMonGfxTable0[22],
	&gFollowerMonGfxTable0[23],
	&gFollowerMonGfxTable0[24],
	&gFollowerMonGfxTable0[25],
	&gFollowerMonGfxTable0[26],
	&gFollowerMonGfxTable0[27],
	&gFollowerMonGfxTable0[28],
	&gFollowerMonGfxTable0[29],
	&gFollowerMonGfxTable0[30],
	&gFollowerMonGfxTable0[31],
	&gFollowerMonGfxTable0[32],
	&gFollowerMonGfxTable0[33],
	&gFollowerMonGfxTable0[34],
	&gFollowerMonGfxTable0[35],
	&gFollowerMonGfxTable0[36],
	&gFollowerMonGfxTable0[37],
	&gFollowerMonGfxTable0[38],
	&gFollowerMonGfxTable0[39],
	&gFollowerMonGfxTable0[40],
	&gFollowerMonGfxTable0[41],
	&gFollowerMonGfxTable0[42],
	&gFollowerMonGfxTable0[43],
	&gFollowerMonGfxTable0[44],
	&gFollowerMonGfxTable0[45],
	&gFollowerMonGfxTable0[46],
	&gFollowerMonGfxTable0[47],
	&gFollowerMonGfxTable0[48],
	&gFollowerMonGfxTable0[49],
	&gFollowerMonGfxTable0[50],
	&gFollowerMonGfxTable0[51],
	&gFollowerMonGfxTable0[52],
	&gFollowerMonGfxTable0[53],
	&gFollowerMonGfxTable0[54],
	&gFollowerMonGfxTable0[55],
	&gFollowerMonGfxTable0[56],
	&gFollowerMonGfxTable0[57],
	&gFollowerMonGfxTable0[58],
	&gFollowerMonGfxTable0[59],
	&gFollowerMonGfxTable0[60],
	&gFollowerMonGfxTable0[61],
	&gFollowerMonGfxTable0[62],
	&gFollowerMonGfxTable0[63],
	&gFollowerMonGfxTable0[64],
	&gFollowerMonGfxTable0[65],
	&gFollowerMonGfxTable0[66],
	&gFollowerMonGfxTable0[67],
	&gFollowerMonGfxTable0[68],
	&gFollowerMonGfxTable0[69],
	&gFollowerMonGfxTable0[70],
	&gFollowerMonGfxTable0[71],
	&gFollowerMonGfxTable0[72],
	&gFollowerMonGfxTable0[73],
	&gFollowerMonGfxTable0[74],
	&gFollowerMonGfxTable0[75],
	&gFollowerMonGfxTable0[76],
	&gFollowerMonGfxTable0[77],
	&gFollowerMonGfxTable0[78],
	&gFollowerMonGfxTable0[79],
	&gFollowerMonGfxTable0[80],
	&gFollowerMonGfxTable0[81],
	&gFollowerMonGfxTable0[82],
	&gFollowerMonGfxTable0[83],
	&gFollowerMonGfxTable0[84],
	&gFollowerMonGfxTable0[85],
	&gFollowerMonGfxTable0[86],
	&gFollowerMonGfxTable0[87],
	&gFollowerMonGfxTable0[88],
	&gFollowerMonGfxTable0[89],
	&gFollowerMonGfxTable0[90],
	&gFollowerMonGfxTable0[91],
	&gFollowerMonGfxTable0[92],
	&gFollowerMonGfxTable0[93],
	&gFollowerMonGfxTable0[94],
	&gFollowerMonGfxTable0[95],
	&gFollowerMonGfxTable0[96],
	&gFollowerMonGfxTable0[97],
	&gFollowerMonGfxTable0[98],
	&gFollowerMonGfxTable0[99],
	&gFollowerMonGfxTable0[100],
	&gFollowerMonGfxTable0[101],
	&gFollowerMonGfxTable0[102],
	&gFollowerMonGfxTable0[103],
	&gFollowerMonGfxTable0[104],
	&gFollowerMonGfxTable0[105],
	&gFollowerMonGfxTable0[106],
	&gFollowerMonGfxTable0[107],
	&gFollowerMonGfxTable0[108],
	&gFollowerMonGfxTable0[109],
	&gFollowerMonGfxTable0[110],
	&gFollowerMonGfxTable0[111],
	&gFollowerMonGfxTable0[112],
	&gFollowerMonGfxTable0[113],
	&gFollowerMonGfxTable0[114],
	&gFollowerMonGfxTable0[115],
	&gFollowerMonGfxTable0[116],
	&gFollowerMonGfxTable0[117],
	&gFollowerMonGfxTable0[118],
	&gFollowerMonGfxTable0[119],
	&gFollowerMonGfxTable0[120],
	&gFollowerMonGfxTable0[121],
	&gFollowerMonGfxTable0[122],
	&gFollowerMonGfxTable0[123],
	&gFollowerMonGfxTable0[124],
	&gFollowerMonGfxTable0[125],
	&gFollowerMonGfxTable0[126],
	&gFollowerMonGfxTable0[127],
	&gFollowerMonGfxTable0[128],
	&gFollowerMonGfxTable0[129],
	&gFollowerMonGfxTable0[130],
	&gFollowerMonGfxTable0[131],
	&gFollowerMonGfxTable0[132],
	&gFollowerMonGfxTable0[133],
	&gFollowerMonGfxTable0[134],
	&gFollowerMonGfxTable0[135],
	&gFollowerMonGfxTable0[136],
	&gFollowerMonGfxTable0[137],
	&gFollowerMonGfxTable0[138],
	&gFollowerMonGfxTable0[139],
	&gFollowerMonGfxTable0[140],
	&gFollowerMonGfxTable0[141],
	&gFollowerMonGfxTable0[142],
	&gFollowerMonGfxTable0[143],
	&gFollowerMonGfxTable0[144],
	&gFollowerMonGfxTable0[145],
	&gFollowerMonGfxTable0[146],
	&gFollowerMonGfxTable0[147],
	&gFollowerMonGfxTable0[148],
	&gFollowerMonGfxTable0[149],
	&gFollowerMonGfxTable0[150],
    &gFollowerMonGfxTable0[151], // Chikorita
    &gFollowerMonGfxTable0[152], // Bayleef
    &gFollowerMonGfxTable0[153], // Meganium
    &gFollowerMonGfxTable0[154], // Cyndaquil
    &gFollowerMonGfxTable0[155], // Quilava
    &gFollowerMonGfxTable0[156], // Typhlosion
    &gFollowerMonGfxTable0[157], // Totodile
    &gFollowerMonGfxTable0[158], // Croconaw
    &gFollowerMonGfxTable0[159], // Feraligatr
    &gFollowerMonGfxTable0[160], // Sentret
    &gFollowerMonGfxTable0[161], // Furret
    &gFollowerMonGfxTable0[162], // Hoothoot
    &gFollowerMonGfxTable0[163], // Noctowl
    &gFollowerMonGfxTable0[164], // Ledyba
    &gFollowerMonGfxTable0[165], // Ledian
    &gFollowerMonGfxTable0[166], // Spinarak
    &gFollowerMonGfxTable0[167], // Ariados
    &gFollowerMonGfxTable0[168], // Crobat
    &gFollowerMonGfxTable0[169], // Chinchou
    &gFollowerMonGfxTable0[170], // Lanturn
    &gFollowerMonGfxTable0[171], // Pichu
    &gFollowerMonGfxTable0[172], // Cleffa
    &gFollowerMonGfxTable0[173], // Igglybuff
    &gFollowerMonGfxTable0[174], // Togepi
    &gFollowerMonGfxTable0[175], // Togetic
    &gFollowerMonGfxTable0[176], // Natu
    &gFollowerMonGfxTable0[177], // Xatu
    &gFollowerMonGfxTable0[178], // Mareep
    &gFollowerMonGfxTable0[179], // Flaaffy
    &gFollowerMonGfxTable0[180], // Ampharos
    &gFollowerMonGfxTable0[181], // Bellossom
    &gFollowerMonGfxTable0[182], // Marill
    &gFollowerMonGfxTable0[183], // Azumarill
    &gFollowerMonGfxTable0[184], // Sudowoodo
    &gFollowerMonGfxTable0[185], // Politoed
    &gFollowerMonGfxTable0[186], // Hoppip
    &gFollowerMonGfxTable0[187], // Skiploom
    &gFollowerMonGfxTable0[188], // Jumpluff
    &gFollowerMonGfxTable0[189], // Aipom
    &gFollowerMonGfxTable0[190], // Sunkern
    &gFollowerMonGfxTable0[191], // Sunflora
    &gFollowerMonGfxTable0[192], // Yanma
    &gFollowerMonGfxTable0[193], // Wooper
    &gFollowerMonGfxTable0[194], // Quagsire
    &gFollowerMonGfxTable0[195], // Espeon
    &gFollowerMonGfxTable0[196], // Umbreon
    &gFollowerMonGfxTable0[197], // Murkrow
    &gFollowerMonGfxTable0[198], // Slowking
    &gFollowerMonGfxTable0[199], // Misdreavus
    &gFollowerMonGfxTable0[200], // Unown
    &gFollowerMonGfxTable0[201], // Wobbuffet
    &gFollowerMonGfxTable0[202], // Girafarig
    &gFollowerMonGfxTable0[203], // Pineco
    &gFollowerMonGfxTable0[204], // Forretress
    &gFollowerMonGfxTable0[205], // Dunsparce
    &gFollowerMonGfxTable0[206], // Gligar
    &gFollowerMonGfxTable0[207], // Steelix
    &gFollowerMonGfxTable0[208], // Snubbull
    &gFollowerMonGfxTable0[209], // Granbull
    &gFollowerMonGfxTable0[210], // Qwilfish
    &gFollowerMonGfxTable0[211], // Scizor
    &gFollowerMonGfxTable0[212], // Shuckle
    &gFollowerMonGfxTable0[213], // Heracross
    &gFollowerMonGfxTable0[214], // Sneasel
    &gFollowerMonGfxTable0[215], // Teddiursa
    &gFollowerMonGfxTable0[216], // Ursaring
    &gFollowerMonGfxTable0[217], // Slugma
    &gFollowerMonGfxTable0[218], // Magcargo
    &gFollowerMonGfxTable0[219], // Swinub
    &gFollowerMonGfxTable0[220], // Piloswine
    &gFollowerMonGfxTable0[221], // Corsola
    &gFollowerMonGfxTable0[222], // Remoraid
    &gFollowerMonGfxTable0[223], // Octillery
    &gFollowerMonGfxTable0[224], // Delibird
    &gFollowerMonGfxTable0[225], // Mantine
    &gFollowerMonGfxTable0[226], // Skarmory
    &gFollowerMonGfxTable0[227], // Houndour
    &gFollowerMonGfxTable0[228], // Houndoom
    &gFollowerMonGfxTable0[229], // Kingdra
    &gFollowerMonGfxTable0[230], // Phanpy
    &gFollowerMonGfxTable0[231], // Donphan
    &gFollowerMonGfxTable0[232], // Porygon2
    &gFollowerMonGfxTable0[233], // Stantler
    &gFollowerMonGfxTable0[234], // Smeargle
    &gFollowerMonGfxTable0[235], // Tyrogue
    &gFollowerMonGfxTable0[236], // Hitmontop
    &gFollowerMonGfxTable0[237], // Smoochum
    &gFollowerMonGfxTable0[238], // Elekid
    &gFollowerMonGfxTable0[239], // Magby
};

static NPCPtr sOverworldTable3[] =
{
	&gFollowerMonGfxTable1[0],   // Miltank
	&gFollowerMonGfxTable1[1],   // Blissey
	&gFollowerMonGfxTable1[2],   // Raikou
	&gFollowerMonGfxTable1[3],   // Entei
	&gFollowerMonGfxTable1[4],   // Suicune
	&gFollowerMonGfxTable1[5],   // Larvitar
	&gFollowerMonGfxTable1[6],   // Pupitar
	&gFollowerMonGfxTable1[7],   // Tyranitar
	&gFollowerMonGfxTable1[8],   // Lugia
	&gFollowerMonGfxTable1[9],   // HoOh
	&gFollowerMonGfxTable1[10],  // Celebi
	&gFollowerMonGfxTable1[11],  // Treecko
	&gFollowerMonGfxTable1[12],  // Grovyle
	&gFollowerMonGfxTable1[13],  // Sceptile
	&gFollowerMonGfxTable1[14],  // Torchic
	&gFollowerMonGfxTable1[15],  // Combusken
	&gFollowerMonGfxTable1[16],  // Blaziken
	&gFollowerMonGfxTable1[17],  // Mudkip
	&gFollowerMonGfxTable1[18],  // Marshtomp
	&gFollowerMonGfxTable1[19],  // Swampert
	&gFollowerMonGfxTable1[20],  // Poochyena
	&gFollowerMonGfxTable1[21],  // Mightyena
	&gFollowerMonGfxTable1[22],  // Zigzagoon
	&gFollowerMonGfxTable1[23],  // Linoone
	&gFollowerMonGfxTable1[24],  // Wurmple
	&gFollowerMonGfxTable1[25],  // Silcoon
	&gFollowerMonGfxTable1[26],  // Beautifly
	&gFollowerMonGfxTable1[27],  // Cascoon
	&gFollowerMonGfxTable1[28],  // Dustox
	&gFollowerMonGfxTable1[29],  // Lotad
	&gFollowerMonGfxTable1[30],  // Lombre
	&gFollowerMonGfxTable1[31],  // Ludicolo
	&gFollowerMonGfxTable1[32],  // Seedot
	&gFollowerMonGfxTable1[33],  // Nuzleaf
	&gFollowerMonGfxTable1[34],  // Shiftry
	&gFollowerMonGfxTable1[35],  // Nincada
	&gFollowerMonGfxTable1[36],  // Ninjask
	&gFollowerMonGfxTable1[37],  // Shedinja
	&gFollowerMonGfxTable1[38],  // Taillow
	&gFollowerMonGfxTable1[39],  // Swellow
	&gFollowerMonGfxTable1[40],  // Shroomish
	&gFollowerMonGfxTable1[41],  // Breloom
	&gFollowerMonGfxTable1[42],  // Spinda
	&gFollowerMonGfxTable1[43],  // Wingull
	&gFollowerMonGfxTable1[44],  // Pelipper
	&gFollowerMonGfxTable1[45],  // Surskit
	&gFollowerMonGfxTable1[46],  // Masquerain
	&gFollowerMonGfxTable1[47],  // Wailmer
	&gFollowerMonGfxTable1[48],  // Wailord
	&gFollowerMonGfxTable1[49],  // Skitty
	&gFollowerMonGfxTable1[50],  // Delcatty
	&gFollowerMonGfxTable1[51],  // Kecleon
	&gFollowerMonGfxTable1[52],  // Baltoy
	&gFollowerMonGfxTable1[53],  // Claydol
	&gFollowerMonGfxTable1[54],  // Nosepass
	&gFollowerMonGfxTable1[55],  // Torkoal
	&gFollowerMonGfxTable1[56],  // Sableye
	&gFollowerMonGfxTable1[57],  // Barboach
	&gFollowerMonGfxTable1[58],  // Whiscash
	&gFollowerMonGfxTable1[59],  // Luvdisc
	&gFollowerMonGfxTable1[60],  // Corphish
	&gFollowerMonGfxTable1[61],  // Crawdaunt
	&gFollowerMonGfxTable1[62],  // Feebas
	&gFollowerMonGfxTable1[63],  // Milotic
	&gFollowerMonGfxTable1[64],  // Carvanha
	&gFollowerMonGfxTable1[65],  // Sharpedo
	&gFollowerMonGfxTable1[66],  // Trapinch
	&gFollowerMonGfxTable1[67],  // Vibrava
	&gFollowerMonGfxTable1[68],  // Flygon
	&gFollowerMonGfxTable1[69],  // Makuhita
	&gFollowerMonGfxTable1[70],  // Hariyama
	&gFollowerMonGfxTable1[71],  // Electrike
	&gFollowerMonGfxTable1[72],  // Manectric
	&gFollowerMonGfxTable1[73],  // Numel
	&gFollowerMonGfxTable1[74],  // Camerupt
	&gFollowerMonGfxTable1[75],  // Spheal
	&gFollowerMonGfxTable1[76],  // Sealeo
	&gFollowerMonGfxTable1[77],  // Walrein
	&gFollowerMonGfxTable1[78],  // Cacnea
	&gFollowerMonGfxTable1[79],  // Cacturne
	&gFollowerMonGfxTable1[80],  // Snorunt
	&gFollowerMonGfxTable1[81],  // Glalie
	&gFollowerMonGfxTable1[82],  // Lunatone
	&gFollowerMonGfxTable1[83],  // Solrock
	&gFollowerMonGfxTable1[84],  // Azurill
	&gFollowerMonGfxTable1[85],  // Spoink
	&gFollowerMonGfxTable1[86],  // Grumpig
	&gFollowerMonGfxTable1[87],  // Plusle
	&gFollowerMonGfxTable1[88],  // Minun
	&gFollowerMonGfxTable1[89],  // Mawile
	&gFollowerMonGfxTable1[90],  // Meditite
	&gFollowerMonGfxTable1[91],  // Medicham
	&gFollowerMonGfxTable1[92],  // Swablu
	&gFollowerMonGfxTable1[93],  // Altaria
	&gFollowerMonGfxTable1[94],  // Wynaut
	&gFollowerMonGfxTable1[95],  // Duskull
	&gFollowerMonGfxTable1[96],  // Dusclops
	&gFollowerMonGfxTable1[97],  // Roselia
	&gFollowerMonGfxTable1[98],  // Slakoth
	&gFollowerMonGfxTable1[99],  // Vigoroth
	&gFollowerMonGfxTable1[100], // Slaking
	&gFollowerMonGfxTable1[101], // Gulpin
	&gFollowerMonGfxTable1[102], // Swalot
	&gFollowerMonGfxTable1[103], // Tropius
	&gFollowerMonGfxTable1[104], // Whismur
	&gFollowerMonGfxTable1[105], // Loudred
	&gFollowerMonGfxTable1[106], // Exploud
	&gFollowerMonGfxTable1[107], // Clamperl
	&gFollowerMonGfxTable1[108], // Huntail
	&gFollowerMonGfxTable1[109], // Gorebyss
	&gFollowerMonGfxTable1[110], // Absol
	&gFollowerMonGfxTable1[111], // Shuppet
	&gFollowerMonGfxTable1[112], // Banette
	&gFollowerMonGfxTable1[113], // Seviper
	&gFollowerMonGfxTable1[114], // Zangoose
	&gFollowerMonGfxTable1[115], // Relicanth
	&gFollowerMonGfxTable1[116], // Aron
	&gFollowerMonGfxTable1[117], // Lairon
	&gFollowerMonGfxTable1[118], // Aggron
	&gFollowerMonGfxTable1[119], // Castform
	&gFollowerMonGfxTable1[120], // Volbeat
	&gFollowerMonGfxTable1[121], // Illumise
	&gFollowerMonGfxTable1[122], // Lileep
	&gFollowerMonGfxTable1[123], // Cradily
	&gFollowerMonGfxTable1[124], // Anorith
	&gFollowerMonGfxTable1[125], // Armaldo
	&gFollowerMonGfxTable1[126], // Ralts
	&gFollowerMonGfxTable1[127], // Kirlia
	&gFollowerMonGfxTable1[128], // Gardevoir
	&gFollowerMonGfxTable1[129], // Bagon
	&gFollowerMonGfxTable1[130], // Shelgon
	&gFollowerMonGfxTable1[131], // Salamence
	&gFollowerMonGfxTable1[132], // Beldum
	&gFollowerMonGfxTable1[133], // Metang
	&gFollowerMonGfxTable1[134], // Metagross
	&gFollowerMonGfxTable1[135], // Regirock
	&gFollowerMonGfxTable1[136], // Regice
	&gFollowerMonGfxTable1[137], // Registeel
	&gFollowerMonGfxTable1[138], // Kyogre
	&gFollowerMonGfxTable1[139], // Groudon
	&gFollowerMonGfxTable1[140], // Rayquaza
	&gFollowerMonGfxTable1[141], // Latias
	&gFollowerMonGfxTable1[142], // Latios
	&gFollowerMonGfxTable1[143], // Jirachi
	&gFollowerMonGfxTable1[144], // Deoxys
	&gFollowerMonGfxTable1[145], // Chimecho
	// Gen 4
	&gFollowerMonGfxTable1[146], // Turtwig
	&gFollowerMonGfxTable1[147], // Grotle
	&gFollowerMonGfxTable1[148], // Torterra
	&gFollowerMonGfxTable1[149], // Chimchar
	&gFollowerMonGfxTable1[150], // Monferno
	&gFollowerMonGfxTable1[151], // Infernape
	&gFollowerMonGfxTable1[152], // Piplup
	&gFollowerMonGfxTable1[153], // Prinplup
	&gFollowerMonGfxTable1[154], // Empoleon
	&gFollowerMonGfxTable1[155], // Starly
	&gFollowerMonGfxTable1[156], // Staravia
	&gFollowerMonGfxTable1[157], // Staraptor
	&gFollowerMonGfxTable1[158], // Bidoof
	&gFollowerMonGfxTable1[159], // Bibarel
	&gFollowerMonGfxTable1[160], // Kricketot
	&gFollowerMonGfxTable1[161], // Kricketune
	&gFollowerMonGfxTable1[162], // Shinx
	&gFollowerMonGfxTable1[163], // Luxio
	&gFollowerMonGfxTable1[164], // Luxray
	&gFollowerMonGfxTable1[165], // Budew
	&gFollowerMonGfxTable1[166], // Roserade
	&gFollowerMonGfxTable1[167], // Cranidos
	&gFollowerMonGfxTable1[168], // Rampardos
	&gFollowerMonGfxTable1[169], // Shieldon
	&gFollowerMonGfxTable1[170], // Bastiodon
	&gFollowerMonGfxTable1[171], // Burmy
	&gFollowerMonGfxTable1[172], // Wormadam
	&gFollowerMonGfxTable1[173], // Mothim
	&gFollowerMonGfxTable1[174], // Combee
	&gFollowerMonGfxTable1[175], // Vespiquen
	&gFollowerMonGfxTable1[176], // Pachirisu
	&gFollowerMonGfxTable1[177], // Buizel
	&gFollowerMonGfxTable1[178], // Floatzel
	&gFollowerMonGfxTable1[179], // Cherubi
	&gFollowerMonGfxTable1[180], // Cherrim
	&gFollowerMonGfxTable1[181], // Shellos
	&gFollowerMonGfxTable1[182], // Gastrodon
	&gFollowerMonGfxTable1[183], // Ambipom
	&gFollowerMonGfxTable1[184], // Drifloon
	&gFollowerMonGfxTable1[185], // Drifblim
	&gFollowerMonGfxTable1[186], // Buneary
	&gFollowerMonGfxTable1[187], // Lopunny
	&gFollowerMonGfxTable1[188], // Mismagius
	&gFollowerMonGfxTable1[189], // Honchkrow
	&gFollowerMonGfxTable1[190], // Glameow
	&gFollowerMonGfxTable1[191], // Purugly
	&gFollowerMonGfxTable1[192], // Chingling
	&gFollowerMonGfxTable1[193], // Stunky
	&gFollowerMonGfxTable1[194], // Skuntank
	&gFollowerMonGfxTable1[195], // Bronzor
	&gFollowerMonGfxTable1[196], // Bronzong
	&gFollowerMonGfxTable1[197], // Bonsly
	&gFollowerMonGfxTable1[198], // MimeJr
	&gFollowerMonGfxTable1[199], // Happiny
	&gFollowerMonGfxTable1[200], // Chatot
	&gFollowerMonGfxTable1[201], // Spiritomb
	&gFollowerMonGfxTable1[202], // Gible
	&gFollowerMonGfxTable1[203], // Gabite
	&gFollowerMonGfxTable1[204], // Garchomp
	&gFollowerMonGfxTable1[205], // Munchlax
	&gFollowerMonGfxTable1[206], // Riolu
	&gFollowerMonGfxTable1[207], // Lucario
	&gFollowerMonGfxTable1[208], // Hippopotas
	&gFollowerMonGfxTable1[209], // Hippowdon
	&gFollowerMonGfxTable1[210], // Skorupi
	&gFollowerMonGfxTable1[211], // Drapion
	&gFollowerMonGfxTable1[212], // Croagunk
	&gFollowerMonGfxTable1[213], // Toxicroak
	&gFollowerMonGfxTable1[214], // Carnivine
	&gFollowerMonGfxTable1[215], // Finneon
	&gFollowerMonGfxTable1[216], // Lumineon
	&gFollowerMonGfxTable1[217], // Mantyke
	&gFollowerMonGfxTable1[218], // Snover
	&gFollowerMonGfxTable1[219], // Abomasnow
	&gFollowerMonGfxTable1[220], // Weavile
	&gFollowerMonGfxTable1[221], // Magnezone
	&gFollowerMonGfxTable1[222], // Lickilicky
	&gFollowerMonGfxTable1[223], // Rhyperior
	&gFollowerMonGfxTable1[224], // Tangrowth
	&gFollowerMonGfxTable1[225], // Electivire
	&gFollowerMonGfxTable1[226], // Magmortar
	&gFollowerMonGfxTable1[227], // Togekiss
	&gFollowerMonGfxTable1[228], // Yanmega
	&gFollowerMonGfxTable1[229], // Leafeon
	&gFollowerMonGfxTable1[230], // Glaceon
	&gFollowerMonGfxTable1[231], // Gliscor
	&gFollowerMonGfxTable1[232], // Mamoswine
	&gFollowerMonGfxTable1[233], // PorygonZ
	&gFollowerMonGfxTable1[234], // Gallade
	&gFollowerMonGfxTable1[235], // Probopass
	&gFollowerMonGfxTable1[236], // Dusknoir
	&gFollowerMonGfxTable1[237], // Froslass
	&gFollowerMonGfxTable1[238], // Rotom
	&gFollowerMonGfxTable1[239], // Uxie
};

static NPCPtr sOverworldTable4[] =
{
	&gFollowerMonGfxTable2[0], // Mesprit
	&gFollowerMonGfxTable2[1], // Azelf
	&gFollowerMonGfxTable2[2], // Dialga
	&gFollowerMonGfxTable2[3], // Palkia
	&gFollowerMonGfxTable2[4], // Heatran
	&gFollowerMonGfxTable2[5], // Regigigas
	&gFollowerMonGfxTable2[6], // Giratina
	&gFollowerMonGfxTable2[7], // Cresselia
	&gFollowerMonGfxTable2[8], // Phione
	&gFollowerMonGfxTable2[9], // Manaphy
	&gFollowerMonGfxTable2[10], // Darkrai
	&gFollowerMonGfxTable2[11], // Shaymin
	&gFollowerMonGfxTable2[12], // Arceus
	&gFollowerMonGfxTable2[13], // Victini
	// Gen 5
	&gFollowerMonGfxTable2[14], // Snivy
	&gFollowerMonGfxTable2[15], // Servine
	&gFollowerMonGfxTable2[16], // Serperior
	&gFollowerMonGfxTable2[17], // Tepig
	&gFollowerMonGfxTable2[18], // Pignite
	&gFollowerMonGfxTable2[19], // Emboar
	&gFollowerMonGfxTable2[20], // Oshawott
	&gFollowerMonGfxTable2[21], // Dewott
	&gFollowerMonGfxTable2[22], // Samurott
	&gFollowerMonGfxTable2[23], // Patrat
	&gFollowerMonGfxTable2[24], // Watchog
	&gFollowerMonGfxTable2[25], // Lillipup
	&gFollowerMonGfxTable2[26], // Herdier
	&gFollowerMonGfxTable2[27], // Stoutland
	&gFollowerMonGfxTable2[28], // Purrloin
	&gFollowerMonGfxTable2[29], // Liepard
	&gFollowerMonGfxTable2[30], // Pansage
	&gFollowerMonGfxTable2[31], // Simisage
	&gFollowerMonGfxTable2[32], // Pansear
	&gFollowerMonGfxTable2[33], // Simisear
	&gFollowerMonGfxTable2[34], // Panpour
	&gFollowerMonGfxTable2[35], // Simipour
	&gFollowerMonGfxTable2[36], // Munna
	&gFollowerMonGfxTable2[37], // Musharna
	&gFollowerMonGfxTable2[38], // Pidove
	&gFollowerMonGfxTable2[39], // Tranquill
	&gFollowerMonGfxTable2[40], // Unfezant
	&gFollowerMonGfxTable2[41], // Blitzle
	&gFollowerMonGfxTable2[42], // Zebstrika
	&gFollowerMonGfxTable2[43], // Roggenrola
	&gFollowerMonGfxTable2[44], // Boldore
	&gFollowerMonGfxTable2[45], // Gigalith
	&gFollowerMonGfxTable2[46], // Woobat
	&gFollowerMonGfxTable2[47], // Swoobat
	&gFollowerMonGfxTable2[48], // Drilbur
	&gFollowerMonGfxTable2[49], // Excadrill
	&gFollowerMonGfxTable2[50], // Audino
	&gFollowerMonGfxTable2[51], // Timburr
	&gFollowerMonGfxTable2[52], // Gurdurr
	&gFollowerMonGfxTable2[53], // Conkeldurr
	&gFollowerMonGfxTable2[54], // Tympole
	&gFollowerMonGfxTable2[55], // Palpitoad
	&gFollowerMonGfxTable2[56], // Seismitoad
	&gFollowerMonGfxTable2[57], // Throh
	&gFollowerMonGfxTable2[58], // Sawk
	&gFollowerMonGfxTable2[59], // Sewaddle
	&gFollowerMonGfxTable2[60], // Swadloon
	&gFollowerMonGfxTable2[61], // Leavanny
	&gFollowerMonGfxTable2[62], // Venipede
	&gFollowerMonGfxTable2[63], // Whirlipede
	&gFollowerMonGfxTable2[64], // Scolipede
	&gFollowerMonGfxTable2[65], // Cottonee
	&gFollowerMonGfxTable2[66], // Whimsicott
	&gFollowerMonGfxTable2[67], // Petilil
	&gFollowerMonGfxTable2[68], // Lilligant
	&gFollowerMonGfxTable2[69], // BasculinRed
	&gFollowerMonGfxTable2[70], // Sandile
	&gFollowerMonGfxTable2[71], // Krokorok
	&gFollowerMonGfxTable2[72], // Krookodile
	&gFollowerMonGfxTable2[73], // Darumaka
	&gFollowerMonGfxTable2[74], // Darmanitan
	&gFollowerMonGfxTable2[75], // Maractus
	&gFollowerMonGfxTable2[76], // Dwebble
	&gFollowerMonGfxTable2[77], // Crustle
	&gFollowerMonGfxTable2[78], // Scraggy
	&gFollowerMonGfxTable2[79], // Scrafty
	&gFollowerMonGfxTable2[80], // Sigilyph
	&gFollowerMonGfxTable2[81], // Yamask
	&gFollowerMonGfxTable2[82], // Cofagrigus
	&gFollowerMonGfxTable2[83], // Tirtouga
	&gFollowerMonGfxTable2[84], // Carracosta
	&gFollowerMonGfxTable2[85], // Archen
	&gFollowerMonGfxTable2[86], // Archeops
	&gFollowerMonGfxTable2[87], // Trubbish
	&gFollowerMonGfxTable2[88], // Garbodor
	&gFollowerMonGfxTable2[89], // Zorua
	&gFollowerMonGfxTable2[90], // Zoroark
	&gFollowerMonGfxTable2[91], // Minccino
	&gFollowerMonGfxTable2[92], // Cinccino
	&gFollowerMonGfxTable2[93], // Gothita
	&gFollowerMonGfxTable2[94], // Gothorita
	&gFollowerMonGfxTable2[95], // Gothitelle
	&gFollowerMonGfxTable2[96], // Solosis
	&gFollowerMonGfxTable2[97], // Duosion
	&gFollowerMonGfxTable2[98], // Reuniclus
	&gFollowerMonGfxTable2[99], // Ducklett
	&gFollowerMonGfxTable2[100], // Swanna
	&gFollowerMonGfxTable2[101], // Vanillite
	&gFollowerMonGfxTable2[102], // Vanillish
	&gFollowerMonGfxTable2[103], // Vanilluxe
	&gFollowerMonGfxTable2[104], // Deerling
	&gFollowerMonGfxTable2[105], // Sawsbuck
	&gFollowerMonGfxTable2[106], // Emolga
	&gFollowerMonGfxTable2[107], // Karrablast
	&gFollowerMonGfxTable2[108], // Escavalier
	&gFollowerMonGfxTable2[109], // Foongus
	&gFollowerMonGfxTable2[110], // Amoonguss
	&gFollowerMonGfxTable2[111], // Frillish
	&gFollowerMonGfxTable2[112], // Jellicent
	&gFollowerMonGfxTable2[113], // Alomomola
	&gFollowerMonGfxTable2[114], // Joltik
	&gFollowerMonGfxTable2[115], // Galvantula
	&gFollowerMonGfxTable2[116], // Ferroseed
	&gFollowerMonGfxTable2[117], // Ferrothorn
	&gFollowerMonGfxTable2[118], // Klink
	&gFollowerMonGfxTable2[119], // Klang
	&gFollowerMonGfxTable2[120], // Klinklang
	&gFollowerMonGfxTable2[121], // Tynamo
	&gFollowerMonGfxTable2[122], // Eelektrik
	&gFollowerMonGfxTable2[123], // Eelektross
	&gFollowerMonGfxTable2[124], // Elgyem
	&gFollowerMonGfxTable2[125], // Beheeyem
	&gFollowerMonGfxTable2[126], // Litwick
	&gFollowerMonGfxTable2[127], // Lampent
	&gFollowerMonGfxTable2[128], // Chandelure
	&gFollowerMonGfxTable2[129], // Axew
	&gFollowerMonGfxTable2[130], // Fraxure
	&gFollowerMonGfxTable2[131], // Haxorus
	&gFollowerMonGfxTable2[132], // Cubchoo
	&gFollowerMonGfxTable2[133], // Beartic
	&gFollowerMonGfxTable2[134], // Cryogonal
	&gFollowerMonGfxTable2[135], // Shelmet
	&gFollowerMonGfxTable2[136], // Accelgor
	&gFollowerMonGfxTable2[137], // Stunfisk
	&gFollowerMonGfxTable2[138], // Mienfoo
	&gFollowerMonGfxTable2[139], // Mienshao
	&gFollowerMonGfxTable2[140], // Druddigon
	&gFollowerMonGfxTable2[141], // Golett
	&gFollowerMonGfxTable2[142], // Golurk
	&gFollowerMonGfxTable2[143], // Pawniard
	&gFollowerMonGfxTable2[144], // Bisharp
	&gFollowerMonGfxTable2[145], // Bouffalant
	&gFollowerMonGfxTable2[146], // Rufflet
	&gFollowerMonGfxTable2[147], // Braviary
	&gFollowerMonGfxTable2[148], // Vullaby
	&gFollowerMonGfxTable2[149], // Mandibuzz
	&gFollowerMonGfxTable2[150], // Heatmor
	&gFollowerMonGfxTable2[151], // Durant
	&gFollowerMonGfxTable2[152], // Deino
	&gFollowerMonGfxTable2[153], // Zweilous
	&gFollowerMonGfxTable2[154], // Hydreigon
	&gFollowerMonGfxTable2[155], // Larvesta
	&gFollowerMonGfxTable2[156], // Volcarona
	&gFollowerMonGfxTable2[157], // Cobalion
	&gFollowerMonGfxTable2[158], // Terrakion
	&gFollowerMonGfxTable2[159], // Virizion
	&gFollowerMonGfxTable2[160], // Tornadus
	&gFollowerMonGfxTable2[161], // Thundurus
	&gFollowerMonGfxTable2[162], // Reshiram
	&gFollowerMonGfxTable2[163], // Zekrom
	&gFollowerMonGfxTable2[164], // Landorus
	&gFollowerMonGfxTable2[165], // Kyurem
	&gFollowerMonGfxTable2[166], // Keldeo
	&gFollowerMonGfxTable2[167], // Meloetta
	&gFollowerMonGfxTable2[168], // Genesect
	&gFollowerMonGfxTable2[169], // Unfezant_F
	&gFollowerMonGfxTable2[170], // Frillish_F
	&gFollowerMonGfxTable2[171], // Jellicent_F
	&gFollowerMonGfxTable2[172], // Shellos_East
	&gFollowerMonGfxTable2[173], // Gastrodon_East
	&gFollowerMonGfxTable2[174], // RotomHeat
	&gFollowerMonGfxTable2[175], // RotomWash
	&gFollowerMonGfxTable2[176], // RotomFrost
	&gFollowerMonGfxTable2[177], // RotomFan
	&gFollowerMonGfxTable2[178], // RotomMow
	&gFollowerMonGfxTable2[179], // Giratine_origin
	&gFollowerMonGfxTable2[180], // Shaymin_sky
};

	// create 255 OW tables
	const struct EventObjectGraphicsInfo** const gOverworldTableSwitcher[255] =
	{
		(NPCPtr*) 0x839FDB0,
		sOverworldTable2,
		sOverworldTable3,
		sOverworldTable4,
		// etc...
		// please note that this method makes compatability with OW Manager challenging
	};
	
	const struct SpritePalette gObjectEventSpritePalettes11[] = {
		{gObjectEventPallete_1, 0x1100},
		{gObjectEventPallete_2, 0x1101},
		{gObjectEventPallete_3, 0x1102},
		{gObjectEventPallete_4, 0x1103},
		{gObjectEventPallete_5, 0x1104},
		{gObjectEventPallete_6, 0x1105},
		{gObjectEventPallete_7, 0x1106},
		{gObjectEventPallete_8, 0x1107},
		{gObjectEventPallete_9, 0x1108},
		{gObjectEventPallete_10, 0x1109},
		{gObjectEventPallete_11, 0x110A},
		{gObjectEventPallete_12, 0x110B},
		{gObjectEventPallete_13, 0x110C},
		{gObjectEventPallete_14, 0x1110},
		{gObjectEventPallete_15, 0x1111},
		{gObjectEventPallete_16, 0x1113},
		{gObjectEventPallete_17, 0x1115},
		{gObjectEventPallete_18, 0x1114},
		{gObjectEventPallete_19, 0x1116},
		{gObjectEventPallete_20, 0x1117},
		{gObjectEventPallete_21, 0x1118},
		{gObjectEventPallete_22, 0x1119},
		{gObjectEventPallete_23, 0x111A},
		{gObjectEventPallete_24, 0x111B},
		{gObjectEventPallete_25, 0x111C},
		{gObjectEventPallete_26, 0x111D},
		{gObjectEventPallete_27, 0x111E},
		{gObjectEventPallete_28, 0x111F},
		{gObjectEventPallete_29, 0x1120},
		{gObjectEventPallete_30, 0x1121},
		{gObjectEventPallete_31, 0x1122},
		{gObjectEventPallete_32, 0x1123},
		{gObjectEventPallete_33, 0x1124},
		{gObjectEventPallete_34, 0x1125},
		{gObjectEventPallete_35, 0x1126},
		{gObjectEventPallete_36, 0x1127},
		{gObjectEventPallete_37, 0x1128},
		{gObjectEventPallete_38, 0x1129},
		{gObjectEventPallete_39, 0x112A},
		{gObjectEventPallete_40, 0x112B},
		{gObjectEventPallete_41, 0x112C},
		{gObjectEventPallete_42, 0x112D},
		{gObjectEventPallete_43, 0x112E},
		{gObjectEventPallete_44, 0x112F},
		{gObjectEventPallete_45, 0x1130},
		{gObjectEventPallete_46, 0x1131},
		{gObjectEventPallete_47, 0x1132},
		{gObjectEventPallete_48, 0x1133},
		{gObjectEventPallete_49, 0x1134},
		{gObjectEventPallete_50, 0x1135},
		{gObjectEventPallete_51, 0x1136},
		{gObjectEventPallete_52, 0x1137},
		{gObjectEventPallete_53, 0x1138},
		{gObjectEventPallete_54, 0x1139},
		{gObjectEventPallete_55, 0x113A},
		{gObjectEventPallete_56, 0x113B},
		{gObjectEventPallete_57, 0x113C},
		{gObjectEventPallete_58, 0x113D},
		{gObjectEventPallete_59, 0x113E},
		{gObjectEventPallete_60, 0x113F},
		{gObjectEventPallete_61, 0x1140},
		{gObjectEventPallete_62, 0x1141},
		{gObjectEventPallete_63, 0x1142},
		{gObjectEventPallete_64, 0x1143},
		{gObjectEventPallete_65, 0x1144},
		{gObjectEventPallete_66, 0x1145},
		{gObjectEventPallete_67, 0x1146},
		{gObjectEventPallete_68, 0x1147},
		{gObjectEventPallete_69, 0x1148},
		{gObjectEventPallete_70, 0x1149},
		{gObjectEventPallete_71, 0x114A},
		{gObjectEventPallete_72, 0x114B},
		{gObjectEventPallete_73, 0x114C},
		{gObjectEventPallete_74, 0x114D},
		{gObjectEventPallete_75, 0x114E},
		{NULL, 0x11FF}
	};

	const struct SpritePalette gObjectEventSpritePalettes12[] = {
		{gFollowerMonPic0001_BulbasaurPal, 0x1200},
		{gFollowerMonPic0002_IvysaurPal, 0x1201},
		{gFollowerMonPic0003_VenusaurPal, 0x1202},
		{gFollowerMonPic0004_CharmanderPal, 0x1203},
		{gFollowerMonPic0005_CharmeleonPal, 0x1204},
		{gFollowerMonPic0006_CharizardPal, 0x1205},
		{gFollowerMonPic0007_SquirtlePal, 0x1206},
		{gFollowerMonPic0008_WartortlePal, 0x1207},
		{gFollowerMonPic0009_BlastoisePal, 0x1208},
		{gFollowerMonPic0010_CaterpiePal, 0x1209},
		{gFollowerMonPic0011_MetapodPal, 0x120A},
		{gFollowerMonPic0012_ButterfreePal, 0x120B},
		{gFollowerMonPic0013_WeedlePal, 0x120C},
		{gFollowerMonPic0014_KakunaPal, 0x120D},
		{gFollowerMonPic0015_BeedrillPal, 0x120E},
		{gFollowerMonPic0016_PidgeyPal, 0x120F},
		{gFollowerMonPic0017_PidgeottoPal, 0x1210},
		{gFollowerMonPic0018_PidgeotPal, 0x1211},
		{gFollowerMonPic0019_RattataPal, 0x1212},
		{gFollowerMonPic0020_RaticatePal, 0x1213},
		{gFollowerMonPic0021_SpearowPal, 0x1214},
		{gFollowerMonPic0022_FearowPal, 0x1215},
		{gFollowerMonPic0023_EkansPal, 0x1216},
		{gFollowerMonPic0024_ArbokPal, 0x1217},
		{gFollowerMonPic0025_PikachuPal, 0x1218},
		{gFollowerMonPic0026_RaichuPal, 0x1219},
		{gFollowerMonPic0027_SandshrewPal, 0x121A},
		{gFollowerMonPic0028_SandslashPal, 0x121B},
		{gFollowerMonPic0029_NidoranFPal, 0x121C},
		{gFollowerMonPic0030_NidorinaPal, 0x121D},
		{gFollowerMonPic0031_NidoqueenPal, 0x121E},
		{gFollowerMonPic0032_NidoranMPal, 0x121F},
		{gFollowerMonPic0033_NidorinoPal, 0x1220},
		{gFollowerMonPic0034_NidokingPal, 0x1221},
		{gFollowerMonPic0035_ClefairyPal, 0x1222},
		{gFollowerMonPic0036_ClefablePal, 0x1223},
		{gFollowerMonPic0037_VulpixPal, 0x1224},
		{gFollowerMonPic0038_NinetalesPal, 0x1225},
		{gFollowerMonPic0039_JigglypuffPal, 0x1226},
		{gFollowerMonPic0040_WigglytuffPal, 0x1227},
		{gFollowerMonPic0041_ZubatPal, 0x1228},
		{gFollowerMonPic0042_GolbatPal, 0x1229},
		{gFollowerMonPic0043_OddishPal, 0x122A},
		{gFollowerMonPic0044_GloomPal, 0x122B},
		{gFollowerMonPic0045_VileplumePal, 0x122C},
		{gFollowerMonPic0046_ParasPal, 0x122D},
		{gFollowerMonPic0047_ParasectPal, 0x122E},
		{gFollowerMonPic0048_VenonatPal, 0x122F},
		{gFollowerMonPic0049_VenomothPal, 0x1230},
		{gFollowerMonPic0050_DiglettPal, 0x1231},
		{gFollowerMonPic0051_DugtrioPal, 0x1232},
		{gFollowerMonPic0052_MeowthPal, 0x1233},
		{gFollowerMonPic0053_PersianPal, 0x1234},
		{gFollowerMonPic0054_PsyduckPal, 0x1235},
		{gFollowerMonPic0055_GolduckPal, 0x1236},
		{gFollowerMonPic0056_MankeyPal, 0x1237},
		{gFollowerMonPic0057_PrimeapePal, 0x1238},
		{gFollowerMonPic0058_GrowlithePal, 0x1239},
		{gFollowerMonPic0059_ArcaninePal, 0x123A},
		{gFollowerMonPic0060_PoliwagPal, 0x123B},
		{gFollowerMonPic0061_PoliwhirlPal, 0x123C},
		{gFollowerMonPic0062_PoliwrathPal, 0x123D},
		{gFollowerMonPic0063_AbraPal, 0x123E},
		{gFollowerMonPic0064_KadabraPal, 0x123F},
		{gFollowerMonPic0065_AlakazamPal, 0x1240},
		{gFollowerMonPic0066_MachopPal, 0x1241},
		{gFollowerMonPic0067_MachokePal, 0x1242},
		{gFollowerMonPic0068_MachampPal, 0x1243},
		{gFollowerMonPic0069_BellsproutPal, 0x1244},
		{gFollowerMonPic0070_WeepinbellPal, 0x1245},
		{gFollowerMonPic0071_VictreebelPal, 0x1246},
		{gFollowerMonPic0072_TentacoolPal, 0x1247},
		{gFollowerMonPic0073_TentacruelPal, 0x1248},
		{gFollowerMonPic0074_GeodudePal, 0x1249},
		{gFollowerMonPic0075_GravelerPal, 0x124A},
		{gFollowerMonPic0076_GolemPal, 0x124B},
		{gFollowerMonPic0077_PonytaPal, 0x124C},
		{gFollowerMonPic0078_RapidashPal, 0x124D},
		{gFollowerMonPic0079_SlowpokePal, 0x124E},
		{gFollowerMonPic0080_SlowbroPal, 0x124F},
		{gFollowerMonPic0081_MagnemitePal, 0x1250},
		{gFollowerMonPic0082_MagnetonPal, 0x1251},
		{gFollowerMonPic0083_FarfetchdPal, 0x1252},
		{gFollowerMonPic0084_DoduoPal, 0x1253},
		{gFollowerMonPic0085_DodrioPal, 0x1254},
		{gFollowerMonPic0086_SeelPal, 0x1255},
		{gFollowerMonPic0087_DewgongPal, 0x1256},
		{gFollowerMonPic0088_GrimerPal, 0x1257},
		{gFollowerMonPic0089_MukPal, 0x1258},
		{gFollowerMonPic0090_ShellderPal, 0x1259},
		{gFollowerMonPic0091_CloysterPal, 0x125A},
		{gFollowerMonPic0092_GastlyPal, 0x125B},
		{gFollowerMonPic0093_HaunterPal, 0x125C},
		{gFollowerMonPic0094_GengarPal, 0x125D},
		{gFollowerMonPic0095_OnixPal, 0x125E},
		{gFollowerMonPic0096_DrowzeePal, 0x125F},
		{gFollowerMonPic0097_HypnoPal, 0x1260},
		{gFollowerMonPic0098_KrabbyPal, 0x1261},
		{gFollowerMonPic0099_KinglerPal, 0x1262},
		{gFollowerMonPic0100_VoltorbPal, 0x1263},
		{gFollowerMonPic0101_ElectrodePal, 0x1264},
		{gFollowerMonPic0102_ExeggcutePal, 0x1265},
		{gFollowerMonPic0103_ExeggutorPal, 0x1266},
		{gFollowerMonPic0104_CubonePal, 0x1267},
		{gFollowerMonPic0105_MarowakPal, 0x1268},
		{gFollowerMonPic0106_HitmonleePal, 0x1269},
		{gFollowerMonPic0107_HitmonchanPal, 0x126A},
		{gFollowerMonPic0108_LickitungPal, 0x126B},
		{gFollowerMonPic0109_KoffingPal, 0x126C},
		{gFollowerMonPic0110_WeezingPal, 0x126D},
		{gFollowerMonPic0111_RhyhornPal, 0x126E},
		{gFollowerMonPic0112_RhydonPal, 0x126F},
		{gFollowerMonPic0113_ChanseyPal, 0x1270},
		{gFollowerMonPic0114_TangelaPal, 0x1271},
		{gFollowerMonPic0115_KangaskhanPal, 0x1272},
		{gFollowerMonPic0116_HorseaPal, 0x1273},
		{gFollowerMonPic0117_SeadraPal, 0x1274},
		{gFollowerMonPic0118_GoldeenPal, 0x1275},
		{gFollowerMonPic0119_SeakingPal, 0x1276},
		{gFollowerMonPic0120_StaryuPal, 0x1277},
		{gFollowerMonPic0121_StarmiePal, 0x1278},
		{gFollowerMonPic0122_MrMimePal, 0x1279},
		{gFollowerMonPic0123_ScytherPal, 0x127A},
		{gFollowerMonPic0124_JynxPal, 0x127B},
		{gFollowerMonPic0125_ElectabuzzPal, 0x127C},
		{gFollowerMonPic0126_MagmarPal, 0x127D},
		{gFollowerMonPic0127_PinsirPal, 0x127E},
		{gFollowerMonPic0128_TaurosPal, 0x127F},
		{gFollowerMonPic0129_MagikarpPal, 0x1280},
		{gFollowerMonPic0130_GyaradosPal, 0x1281},
		{gFollowerMonPic0131_LaprasPal, 0x1282},
		{gFollowerMonPic0132_DittoPal, 0x1283},
		{gFollowerMonPic0133_EeveePal, 0x1284},
		{gFollowerMonPic0134_VaporeonPal, 0x1285},
		{gFollowerMonPic0135_JolteonPal, 0x1286},
		{gFollowerMonPic0136_FlareonPal, 0x1287},
		{gFollowerMonPic0137_PorygonPal, 0x1288},
		{gFollowerMonPic0138_OmanytePal, 0x1289},
		{gFollowerMonPic0139_OmastarPal, 0x128A},
		{gFollowerMonPic0140_KabutoPal, 0x128B},
		{gFollowerMonPic0141_KabutopsPal, 0x128C},
		{gFollowerMonPic0142_AerodactylPal, 0x128D},
		{gFollowerMonPic0143_SnorlaxPal, 0x128E},
		{gFollowerMonPic0144_ArticunoPal, 0x128F},
		{gFollowerMonPic0145_ZapdosPal, 0x1290},
		{gFollowerMonPic0146_MoltresPal, 0x1291},
		{gFollowerMonPic0147_DratiniPal, 0x1292},
		{gFollowerMonPic0148_DragonairPal, 0x1293},
		{gFollowerMonPic0149_DragonitePal, 0x1294},
		{gFollowerMonPic0150_MewtwoPal, 0x1295},
		{gFollowerMonPic0151_MewPal, 0x1296},
        {gFollowerMonPic0152_ChikoritaPal, 0x1297},
        {gFollowerMonPic0153_BayleefPal,  0x1298},
        {gFollowerMonPic0154_MeganiumPal, 0x1299},
        {gFollowerMonPic0155_CyndaquilPal, 0x129A},
        {gFollowerMonPic0156_QuilavaPal,  0x129B},
        {gFollowerMonPic0157_TyphlosionPal, 0x129C},
        {gFollowerMonPic0158_TotodilePal, 0x129D},
        {gFollowerMonPic0159_CroconawPal, 0x129E},
        {gFollowerMonPic0160_FeraligatrPal, 0x129F},
        {gFollowerMonPic0161_SentretPal,  0x12A0},
        {gFollowerMonPic0162_FurretPal,   0x12A1},
        {gFollowerMonPic0163_HoothootPal, 0x12A2},
        {gFollowerMonPic0164_NoctowlPal,  0x12A3},
        {gFollowerMonPic0165_LedybaPal,   0x12A4},
        {gFollowerMonPic0166_LedianPal,   0x12A5},
        {gFollowerMonPic0167_SpinarakPal, 0x12A6},
        {gFollowerMonPic0168_AriadosPal,  0x12A7},
        {gFollowerMonPic0169_CrobatPal,   0x12A8},
        {gFollowerMonPic0170_ChinchouPal, 0x12A9},
        {gFollowerMonPic0171_LanturnPal,  0x12AA},
        {gFollowerMonPic0172_PichuPal,    0x12AB},
        {gFollowerMonPic0173_CleffaPal,   0x12AC},
        {gFollowerMonPic0174_IgglybuffPal, 0x12AD},
        {gFollowerMonPic0175_TogepiPal,   0x12AE},
        {gFollowerMonPic0176_TogeticPal,  0x12AF},
        {gFollowerMonPic0177_NatuPal,     0x12B0},
        {gFollowerMonPic0178_XatuPal,     0x12B1},
        {gFollowerMonPic0179_MareepPal,   0x12B2},
        {gFollowerMonPic0180_FlaaffyPal,  0x12B3},
        {gFollowerMonPic0181_AmpharosPal, 0x12B4},
        {gFollowerMonPic0182_BellossomPal, 0x12B5},
        {gFollowerMonPic0183_MarillPal,   0x12B6},
        {gFollowerMonPic0184_AzumarillPal, 0x12B7},
        {gFollowerMonPic0185_SudowoodoPal, 0x12B8},
        {gFollowerMonPic0186_PolitoedPal, 0x12B9},
        {gFollowerMonPic0187_HoppipPal,   0x12BA},
        {gFollowerMonPic0188_SkiploomPal, 0x12BB},
        {gFollowerMonPic0189_JumpluffPal, 0x12BC},
        {gFollowerMonPic0190_AipomPal,    0x12BD},
        {gFollowerMonPic0191_SunkernPal,  0x12BE},
        {gFollowerMonPic0192_SunfloraPal, 0x12BF},
        {gFollowerMonPic0193_YanmaPal,    0x12C0},
        {gFollowerMonPic0194_WooperPal,   0x12C1},
        {gFollowerMonPic0195_QuagsirePal, 0x12C2},
        {gFollowerMonPic0196_EspeonPal,   0x12C3},
        {gFollowerMonPic0197_UmbreonPal,  0x12C4},
        {gFollowerMonPic0198_MurkrowPal,  0x12C5},
        {gFollowerMonPic0199_SlowkingPal, 0x12C6},
        {gFollowerMonPic0200_MisdreavusPal, 0x12C7},
        {gFollowerMonPic0201_UnownPal,    0x12C8},
        {gFollowerMonPic0202_WobbuffetPal, 0x12C9},
        {gFollowerMonPic0203_GirafarigPal, 0x12CA},
        {gFollowerMonPic0204_PinecoPal,   0x12CB},
        {gFollowerMonPic0205_ForretressPal, 0x12CC},
        {gFollowerMonPic0206_DunsparcePal, 0x12CD},
        {gFollowerMonPic0207_GligarPal,   0x12CE},
        {gFollowerMonPic0208_SteelixPal,  0x12CF},
        {gFollowerMonPic0209_SnubbullPal, 0x12D0},
        {gFollowerMonPic0210_GranbullPal, 0x12D1},
        {gFollowerMonPic0211_QwilfishPal, 0x12D2},
        {gFollowerMonPic0212_ScizorPal,   0x12D3},
        {gFollowerMonPic0213_ShucklePal,  0x12D4},
        {gFollowerMonPic0214_HeracrossPal, 0x12D5},
        {gFollowerMonPic0215_SneaselPal,  0x12D6},
        {gFollowerMonPic0216_TeddiursaPal, 0x12D7},
        {gFollowerMonPic0217_UrsaringPal, 0x12D8},
        {gFollowerMonPic0218_SlugmaPal,   0x12D9},
        {gFollowerMonPic0219_MagcargoPal, 0x12DA},
        {gFollowerMonPic0220_SwinubPal,   0x12DB},
        {gFollowerMonPic0221_PiloswinePal, 0x12DC},
        {gFollowerMonPic0222_CorsolaPal,  0x12DD},
        {gFollowerMonPic0223_RemoraidPal, 0x12DE},
        {gFollowerMonPic0224_OctilleryPal, 0x12DF},
        {gFollowerMonPic0225_DelibirdPal, 0x12E0},
        {gFollowerMonPic0226_MantinePal,  0x12E1},
        {gFollowerMonPic0227_SkarmoryPal, 0x12E2},
        {gFollowerMonPic0228_HoundourPal, 0x12E3},
        {gFollowerMonPic0229_HoundoomPal, 0x12E4},
        {gFollowerMonPic0230_KingdraPal,  0x12E5},
        {gFollowerMonPic0231_PhanpyPal,   0x12E6},
        {gFollowerMonPic0232_DonphanPal,  0x12E7},
        {gFollowerMonPic0233_Porygon2Pal, 0x12E8},
        {gFollowerMonPic0234_StantlerPal, 0x12E9},
        {gFollowerMonPic0235_SmearglePal, 0x12EA},
        {gFollowerMonPic0236_TyroguePal,  0x12EB},
        {gFollowerMonPic0237_HitmontopPal, 0x12EC},
        {gFollowerMonPic0238_SmoochumPal, 0x12ED},
        {gFollowerMonPic0239_ElekidPal,   0x12EE},
        {gFollowerMonPic0240_MagbyPal,    0x12EF},
        {gFollowerMonPic0241_MiltankPal,  0x12F0},
        {gFollowerMonPic0242_BlisseyPal,  0x12F1},
        {gFollowerMonPic0243_RaikouPal,   0x12F2},
        {gFollowerMonPic0244_EnteiPal,    0x12F3},
        {gFollowerMonPic0245_SuicunePal,  0x12F4},
        {gFollowerMonPic0246_LarvitarPal, 0x12F5},
        {gFollowerMonPic0247_PupitarPal,  0x12F6},
        {gFollowerMonPic0248_TyranitarPal, 0x12F7},
        {gFollowerMonPic0249_LugiaPal,    0x12F8},
        {gFollowerMonPic0250_HoOhPal,     0x12F9},
        {gFollowerMonPic0251_CelebiPal,   0x12FA},
	};
	const struct SpritePalette gObjectEventSpritePalettes13[] = 	
	{
		{gFollowerMonPic2001_BulbasaurShinyPal, 0x1300},
		{gFollowerMonPic2002_IvysaurShinyPal, 0x1301},
		{gFollowerMonPic2003_VenusaurShinyPal, 0x1302},
		{gFollowerMonPic2004_CharmanderShinyPal, 0x1303},
		{gFollowerMonPic2005_CharmeleonShinyPal, 0x1304},
		{gFollowerMonPic2006_CharizardShinyPal, 0x1305},
		{gFollowerMonPic2007_SquirtleShinyPal, 0x1306},
		{gFollowerMonPic2008_WartortleShinyPal, 0x1307},
		{gFollowerMonPic2009_BlastoiseShinyPal, 0x1308},
		{gFollowerMonPic2010_CaterpieShinyPal, 0x1309},
		{gFollowerMonPic2011_MetapodShinyPal, 0x130A},
		{gFollowerMonPic2012_ButterfreeShinyPal, 0x130B},
		{gFollowerMonPic2013_WeedleShinyPal, 0x130C},
		{gFollowerMonPic2014_KakunaShinyPal, 0x130D},
		{gFollowerMonPic2015_BeedrillShinyPal, 0x130E},
		{gFollowerMonPic2016_PidgeyShinyPal, 0x130F},
		{gFollowerMonPic2017_PidgeottoShinyPal, 0x1310},
		{gFollowerMonPic2018_PidgeotShinyPal, 0x1311},
		{gFollowerMonPic2019_RattataShinyPal, 0x1312},
		{gFollowerMonPic2020_RaticateShinyPal, 0x1313},
		{gFollowerMonPic2021_SpearowShinyPal, 0x1314},
		{gFollowerMonPic2022_FearowShinyPal, 0x1315},
		{gFollowerMonPic2023_EkansShinyPal, 0x1316},
		{gFollowerMonPic2024_ArbokShinyPal, 0x1317},
		{gFollowerMonPic2025_PikachuShinyPal, 0x1318},
		{gFollowerMonPic2026_RaichuShinyPal, 0x1319},
		{gFollowerMonPic2027_SandshrewShinyPal, 0x131A},
		{gFollowerMonPic2028_SandslashShinyPal, 0x131B},
		{gFollowerMonPic2029_NidoranFShinyPal, 0x131C},
		{gFollowerMonPic2030_NidorinaShinyPal, 0x131D},
		{gFollowerMonPic2031_NidoqueenShinyPal, 0x131E},
		{gFollowerMonPic2032_NidoranMShinyPal, 0x131F},
		{gFollowerMonPic2033_NidorinoShinyPal, 0x1320},
		{gFollowerMonPic2034_NidokingShinyPal, 0x1321},
		{gFollowerMonPic2035_ClefairyShinyPal, 0x1322},
		{gFollowerMonPic2036_ClefableShinyPal, 0x1323},
		{gFollowerMonPic2037_VulpixShinyPal, 0x1324},
		{gFollowerMonPic2038_NinetalesShinyPal, 0x1325},
		{gFollowerMonPic2039_JigglypuffShinyPal, 0x1326},
		{gFollowerMonPic2040_WigglytuffShinyPal, 0x1327},
		{gFollowerMonPic2041_ZubatShinyPal, 0x1328},
		{gFollowerMonPic2042_GolbatShinyPal, 0x1329},
		{gFollowerMonPic2043_OddishShinyPal, 0x132A},
		{gFollowerMonPic2044_GloomShinyPal, 0x132B},
		{gFollowerMonPic2045_VileplumeShinyPal, 0x132C},
		{gFollowerMonPic2046_ParasShinyPal, 0x132D},
		{gFollowerMonPic2047_ParasectShinyPal, 0x132E},
		{gFollowerMonPic2048_VenonatShinyPal, 0x132F},
		{gFollowerMonPic2049_VenomothShinyPal, 0x1330},
		{gFollowerMonPic2050_DiglettShinyPal, 0x1331},
		{gFollowerMonPic2051_DugtrioShinyPal, 0x1332},
		{gFollowerMonPic2052_MeowthShinyPal, 0x1333},
		{gFollowerMonPic2053_PersianShinyPal, 0x1334},
		{gFollowerMonPic2054_PsyduckShinyPal, 0x1335},
		{gFollowerMonPic2055_GolduckShinyPal, 0x1336},
		{gFollowerMonPic2056_MankeyShinyPal, 0x1337},
		{gFollowerMonPic2057_PrimeapeShinyPal, 0x1338},
		{gFollowerMonPic2058_GrowlitheShinyPal, 0x1339},
		{gFollowerMonPic2059_ArcanineShinyPal, 0x133A},
		{gFollowerMonPic2060_PoliwagShinyPal, 0x133B},
		{gFollowerMonPic2061_PoliwhirlShinyPal, 0x133C},
		{gFollowerMonPic2062_PoliwrathShinyPal, 0x133D},
		{gFollowerMonPic2063_AbraShinyPal, 0x133E},
		{gFollowerMonPic2064_KadabraShinyPal, 0x133F},
		{gFollowerMonPic2065_AlakazamShinyPal, 0x1340},
		{gFollowerMonPic2066_MachopShinyPal, 0x1341},
		{gFollowerMonPic2067_MachokeShinyPal, 0x1342},
		{gFollowerMonPic2068_MachampShinyPal, 0x1343},
		{gFollowerMonPic2069_BellsproutShinyPal, 0x1344},
		{gFollowerMonPic2070_WeepinbellShinyPal, 0x1345},
		{gFollowerMonPic2071_VictreebelShinyPal, 0x1346},
		{gFollowerMonPic2072_TentacoolShinyPal, 0x1347},
		{gFollowerMonPic2073_TentacruelShinyPal, 0x1348},
		{gFollowerMonPic2074_GeodudeShinyPal, 0x1349},
		{gFollowerMonPic2075_GravelerShinyPal, 0x134A},
		{gFollowerMonPic2076_GolemShinyPal, 0x134B},
		{gFollowerMonPic2077_PonytaShinyPal, 0x134C},
		{gFollowerMonPic2078_RapidashShinyPal, 0x134D},
		{gFollowerMonPic2079_SlowpokeShinyPal, 0x134E},
		{gFollowerMonPic2080_SlowbroShinyPal, 0x134F},
		{gFollowerMonPic2081_MagnemiteShinyPal, 0x1350},
		{gFollowerMonPic2082_MagnetonShinyPal, 0x1351},
		{gFollowerMonPic2083_FarfetchdShinyPal, 0x1352},
		{gFollowerMonPic2084_DoduoShinyPal, 0x1353},
		{gFollowerMonPic2085_DodrioShinyPal, 0x1354},
		{gFollowerMonPic2086_SeelShinyPal, 0x1355},
		{gFollowerMonPic2087_DewgongShinyPal, 0x1356},
		{gFollowerMonPic2088_GrimerShinyPal, 0x1357},
		{gFollowerMonPic2089_MukShinyPal, 0x1358},
		{gFollowerMonPic2090_ShellderShinyPal, 0x1359},
		{gFollowerMonPic2091_CloysterShinyPal, 0x135A},
		{gFollowerMonPic2092_GastlyShinyPal, 0x135B},
		{gFollowerMonPic2093_HaunterShinyPal, 0x135C},
		{gFollowerMonPic2094_GengarShinyPal, 0x135D},
		{gFollowerMonPic2095_OnixShinyPal, 0x135E},
		{gFollowerMonPic2096_DrowzeeShinyPal, 0x135F},
		{gFollowerMonPic2097_HypnoShinyPal, 0x1360},
		{gFollowerMonPic2098_KrabbyShinyPal, 0x1361},
		{gFollowerMonPic2099_KinglerShinyPal, 0x1362},
		{gFollowerMonPic2100_VoltorbShinyPal, 0x1363},
		{gFollowerMonPic2101_ElectrodeShinyPal, 0x1364},
		{gFollowerMonPic2102_ExeggcuteShinyPal, 0x1365},
		{gFollowerMonPic2103_ExeggutorShinyPal, 0x1366},
		{gFollowerMonPic2104_CuboneShinyPal, 0x1367},
		{gFollowerMonPic2105_MarowakShinyPal, 0x1368},
		{gFollowerMonPic2106_HitmonleeShinyPal, 0x1369},
		{gFollowerMonPic2107_HitmonchanShinyPal, 0x136A},
		{gFollowerMonPic2108_LickitungShinyPal, 0x136B},
		{gFollowerMonPic2109_KoffingShinyPal, 0x136C},
		{gFollowerMonPic2110_WeezingShinyPal, 0x136D},
		{gFollowerMonPic2111_RhyhornShinyPal, 0x136E},
		{gFollowerMonPic2112_RhydonShinyPal, 0x136F},
		{gFollowerMonPic2113_ChanseyShinyPal, 0x1370},
		{gFollowerMonPic2114_TangelaShinyPal, 0x1371},
		{gFollowerMonPic2115_KangaskhanShinyPal, 0x1372},
		{gFollowerMonPic2116_HorseaShinyPal, 0x1373},
		{gFollowerMonPic2117_SeadraShinyPal, 0x1374},
		{gFollowerMonPic2118_GoldeenShinyPal, 0x1375},
		{gFollowerMonPic2119_SeakingShinyPal, 0x1376},
		{gFollowerMonPic2120_StaryuShinyPal, 0x1377},
		{gFollowerMonPic2121_StarmieShinyPal, 0x1378},
		{gFollowerMonPic2122_MrMimeShinyPal, 0x1379},
		{gFollowerMonPic2123_ScytherShinyPal, 0x137A},
		{gFollowerMonPic2124_JynxShinyPal, 0x137B},
		{gFollowerMonPic2125_ElectabuzzShinyPal, 0x137C},
		{gFollowerMonPic2126_MagmarShinyPal, 0x137D},
		{gFollowerMonPic2127_PinsirShinyPal, 0x137E},
		{gFollowerMonPic2128_TaurosShinyPal, 0x137F},
		{gFollowerMonPic2129_MagikarpShinyPal, 0x1380},
		{gFollowerMonPic2130_GyaradosShinyPal, 0x1381},
		{gFollowerMonPic2131_LaprasShinyPal, 0x1382},
		{gFollowerMonPic2132_DittoShinyPal, 0x1383},
		{gFollowerMonPic2133_EeveeShinyPal, 0x1384},
		{gFollowerMonPic2134_VaporeonShinyPal, 0x1385},
		{gFollowerMonPic2135_JolteonShinyPal, 0x1386},
		{gFollowerMonPic2136_FlareonShinyPal, 0x1387},
		{gFollowerMonPic2137_PorygonShinyPal, 0x1388},
		{gFollowerMonPic2138_OmanyteShinyPal, 0x1389},
		{gFollowerMonPic2139_OmastarShinyPal, 0x138A},
		{gFollowerMonPic2140_KabutoShinyPal, 0x138B},
		{gFollowerMonPic2141_KabutopsShinyPal, 0x138C},
		{gFollowerMonPic2142_AerodactylShinyPal, 0x138D},
		{gFollowerMonPic2143_SnorlaxShinyPal, 0x138E},
		{gFollowerMonPic2144_ArticunoShinyPal, 0x138F},
		{gFollowerMonPic2145_ZapdosShinyPal, 0x1390},
		{gFollowerMonPic2146_MoltresShinyPal, 0x1391},
		{gFollowerMonPic2147_DratiniShinyPal, 0x1392},
		{gFollowerMonPic2148_DragonairShinyPal, 0x1393},
		{gFollowerMonPic2149_DragoniteShinyPal, 0x1394},
		{gFollowerMonPic2150_MewtwoShinyPal, 0x1395},
		{gFollowerMonPic2151_MewShinyPal, 0x1396},
        {gFollowerMonPic2152_ChikoritaShinyPal, 0x1397},
        {gFollowerMonPic2153_BayleefShinyPal,  0x1398},
        {gFollowerMonPic2154_MeganiumShinyPal, 0x1399},
        {gFollowerMonPic2155_CyndaquilShinyPal, 0x139A},
        {gFollowerMonPic2156_QuilavaShinyPal,  0x139B},
        {gFollowerMonPic2157_TyphlosionShinyPal, 0x139C},
        {gFollowerMonPic2158_TotodileShinyPal, 0x139D},
        {gFollowerMonPic2159_CroconawShinyPal, 0x139E},
        {gFollowerMonPic2160_FeraligatrShinyPal, 0x139F},
        {gFollowerMonPic2161_SentretShinyPal,  0x13A0},
        {gFollowerMonPic2162_FurretShinyPal,   0x13A1},
        {gFollowerMonPic2163_HoothootShinyPal, 0x13A2},
        {gFollowerMonPic2164_NoctowlShinyPal,  0x13A3},
        {gFollowerMonPic2165_LedybaShinyPal,   0x13A4},
        {gFollowerMonPic2166_LedianShinyPal,   0x13A5},
        {gFollowerMonPic2167_SpinarakShinyPal, 0x13A6},
        {gFollowerMonPic2168_AriadosShinyPal,  0x13A7},
        {gFollowerMonPic2169_CrobatShinyPal,   0x13A8},
        {gFollowerMonPic2170_ChinchouShinyPal, 0x13A9},
        {gFollowerMonPic2171_LanturnShinyPal,  0x13AA},
        {gFollowerMonPic2172_PichuShinyPal,    0x13AB},
        {gFollowerMonPic2173_CleffaShinyPal,   0x13AC},
        {gFollowerMonPic2174_IgglybuffShinyPal, 0x13AD},
        {gFollowerMonPic2175_TogepiShinyPal,   0x13AE},
        {gFollowerMonPic2176_TogeticShinyPal,  0x13AF},
        {gFollowerMonPic2177_NatuShinyPal,     0x13B0},
        {gFollowerMonPic2178_XatuShinyPal,     0x13B1},
        {gFollowerMonPic2179_MareepShinyPal,   0x13B2},
        {gFollowerMonPic2180_FlaaffyShinyPal,  0x13B3},
        {gFollowerMonPic2181_AmpharosShinyPal, 0x13B4},
        {gFollowerMonPic2182_BellossomShinyPal, 0x13B5},
        {gFollowerMonPic2183_MarillShinyPal,   0x13B6},
        {gFollowerMonPic2184_AzumarillShinyPal, 0x13B7},
        {gFollowerMonPic2185_SudowoodoShinyPal, 0x13B8},
        {gFollowerMonPic2186_PolitoedShinyPal, 0x13B9},
        {gFollowerMonPic2187_HoppipShinyPal,   0x13BA},
        {gFollowerMonPic2188_SkiploomShinyPal, 0x13BB},
        {gFollowerMonPic2189_JumpluffShinyPal, 0x13BC},
        {gFollowerMonPic2190_AipomShinyPal,    0x13BD},
        {gFollowerMonPic2191_SunkernShinyPal,  0x13BE},
        {gFollowerMonPic2192_SunfloraShinyPal, 0x13BF},
        {gFollowerMonPic2193_YanmaShinyPal,    0x13C0},
        {gFollowerMonPic2194_WooperShinyPal,   0x13C1},
        {gFollowerMonPic2195_QuagsireShinyPal, 0x13C2},
        {gFollowerMonPic2196_EspeonShinyPal,   0x13C3},
        {gFollowerMonPic2197_UmbreonShinyPal,  0x13C4},
        {gFollowerMonPic2198_MurkrowShinyPal,  0x13C5},
        {gFollowerMonPic2199_SlowkingShinyPal, 0x13C6},
        {gFollowerMonPic2200_MisdreavusShinyPal, 0x13C7},
        {gFollowerMonPic2201_UnownShinyPal,    0x13C8},
        {gFollowerMonPic2202_WobbuffetShinyPal, 0x13C9},
        {gFollowerMonPic2203_GirafarigShinyPal, 0x13CA},
        {gFollowerMonPic2204_PinecoShinyPal,   0x13CB},
        {gFollowerMonPic2205_ForretressShinyPal, 0x13CC},
        {gFollowerMonPic2206_DunsparceShinyPal, 0x13CD},
        {gFollowerMonPic2207_GligarShinyPal,   0x13CE},
        {gFollowerMonPic2208_SteelixShinyPal,  0x13CF},
        {gFollowerMonPic2209_SnubbullShinyPal, 0x13D0},
        {gFollowerMonPic2210_GranbullShinyPal, 0x13D1},
        {gFollowerMonPic2211_QwilfishShinyPal, 0x13D2},
        {gFollowerMonPic2212_ScizorShinyPal,   0x13D3},
        {gFollowerMonPic2213_ShuckleShinyPal,  0x13D4},
        {gFollowerMonPic2214_HeracrossShinyPal, 0x13D5},
        {gFollowerMonPic2215_SneaselShinyPal,  0x13D6},
        {gFollowerMonPic2216_TeddiursaShinyPal, 0x13D7},
        {gFollowerMonPic2217_UrsaringShinyPal, 0x13D8},
        {gFollowerMonPic2218_SlugmaShinyPal,   0x13D9},
        {gFollowerMonPic2219_MagcargoShinyPal, 0x13DA},
        {gFollowerMonPic2220_SwinubShinyPal,   0x13DB},
        {gFollowerMonPic2221_PiloswineShinyPal, 0x13DC},
        {gFollowerMonPic2222_CorsolaShinyPal,  0x13DD},
        {gFollowerMonPic2223_RemoraidShinyPal, 0x13DE},
        {gFollowerMonPic2224_OctilleryShinyPal, 0x13DF},
        {gFollowerMonPic2225_DelibirdShinyPal, 0x13E0},
        {gFollowerMonPic2226_MantineShinyPal,  0x13E1},
        {gFollowerMonPic2227_SkarmoryShinyPal, 0x13E2},
        {gFollowerMonPic2228_HoundourShinyPal, 0x13E3},
        {gFollowerMonPic2229_HoundoomShinyPal, 0x13E4},
        {gFollowerMonPic2230_KingdraShinyPal,  0x13E5},
        {gFollowerMonPic2231_PhanpyShinyPal,   0x13E6},
        {gFollowerMonPic2232_DonphanShinyPal,  0x13E7},
        {gFollowerMonPic2233_Porygon2ShinyPal, 0x13E8},
        {gFollowerMonPic2234_StantlerShinyPal, 0x13E9},
        {gFollowerMonPic2235_SmeargleShinyPal, 0x13EA},
        {gFollowerMonPic2236_TyrogueShinyPal,  0x13EB},
        {gFollowerMonPic2237_HitmontopShinyPal, 0x13EC},
        {gFollowerMonPic2238_SmoochumShinyPal, 0x13ED},
        {gFollowerMonPic2239_ElekidShinyPal,   0x13EE},
        {gFollowerMonPic2240_MagbyShinyPal,    0x13EF},
        {gFollowerMonPic2241_MiltankShinyPal,  0x13F0},
        {gFollowerMonPic2242_BlisseyShinyPal,  0x13F1},
        {gFollowerMonPic2243_RaikouShinyPal,   0x13F2},
        {gFollowerMonPic2244_EnteiShinyPal,    0x13F3},
        {gFollowerMonPic2245_SuicuneShinyPal,  0x13F4},
        {gFollowerMonPic2246_LarvitarShinyPal, 0x13F5},
        {gFollowerMonPic2247_PupitarShinyPal,  0x13F6},
        {gFollowerMonPic2248_TyranitarShinyPal, 0x13F7},
        {gFollowerMonPic2249_LugiaShinyPal,    0x13F8},
        {gFollowerMonPic2250_HoOhShinyPal,     0x13F9},
        {gFollowerMonPic2251_CelebiShinyPal,   0x13FA},

	};

	static const struct SpritePalette gObjectEventSpritePalettes14[] = 	
	{
		{gFollowerMonPic0277_TreeckoPal,  0x1400},
		{gFollowerMonPic0278_GrovylePal,  0x1401},
		{gFollowerMonPic0279_SceptilePal, 0x1402},
		{gFollowerMonPic0280_TorchicPal,  0x1403},
		{gFollowerMonPic0281_CombuskenPal, 0x1404},
		{gFollowerMonPic0282_BlazikenPal, 0x1405},
		{gFollowerMonPic0283_MudkipPal,   0x1406},
		{gFollowerMonPic0284_MarshtompPal, 0x1407},
		{gFollowerMonPic0285_SwampertPal, 0x1408},
		{gFollowerMonPic0286_PoochyenaPal, 0x1409},
		{gFollowerMonPic0287_MightyenaPal, 0x140A},
		{gFollowerMonPic0288_ZigzagoonPal, 0x140B},
		{gFollowerMonPic0289_LinoonePal,  0x140C},
		{gFollowerMonPic0290_WurmplePal,  0x140D},
		{gFollowerMonPic0291_SilcoonPal,  0x140E},
		{gFollowerMonPic0292_BeautiflyPal, 0x140F},
		{gFollowerMonPic0293_CascoonPal,  0x1410},
		{gFollowerMonPic0294_DustoxPal,   0x1411},
		{gFollowerMonPic0295_LotadPal,    0x1412},
		{gFollowerMonPic0296_LombrePal,   0x1413},
		{gFollowerMonPic0297_LudicoloPal, 0x1414},
		{gFollowerMonPic0298_SeedotPal,   0x1415},
		{gFollowerMonPic0299_NuzleafPal,  0x1416},
		{gFollowerMonPic0300_ShiftryPal,  0x1417},
		{gFollowerMonPic0301_NincadaPal,  0x1418},
		{gFollowerMonPic0302_NinjaskPal,  0x1419},
		{gFollowerMonPic0303_ShedinjaPal, 0x141A},
		{gFollowerMonPic0304_TaillowPal,  0x141B},
		{gFollowerMonPic0305_SwellowPal,  0x141C},
		{gFollowerMonPic0306_ShroomishPal, 0x141D},
		{gFollowerMonPic0307_BreloomPal,  0x141E},
		{gFollowerMonPic0308_SpindaPal,   0x141F},
		{gFollowerMonPic0309_WingullPal,  0x1420},
		{gFollowerMonPic0310_PelipperPal, 0x1421},
		{gFollowerMonPic0311_SurskitPal,  0x1422},
		{gFollowerMonPic0312_MasquerainPal, 0x1423},
		{gFollowerMonPic0313_WailmerPal,  0x1424},
		{gFollowerMonPic0314_WailordPal,  0x1425},
		{gFollowerMonPic0315_SkittyPal,   0x1426},
		{gFollowerMonPic0316_DelcattyPal, 0x1427},
		{gFollowerMonPic0317_KecleonPal,  0x1428},
		{gFollowerMonPic0318_BaltoyPal,   0x1429},
		{gFollowerMonPic0319_ClaydolPal,  0x142A},
		{gFollowerMonPic0320_NosepassPal, 0x142B},
		{gFollowerMonPic0321_TorkoalPal,  0x142C},
		{gFollowerMonPic0322_SableyePal,  0x142D},
		{gFollowerMonPic0323_BarboachPal, 0x142E},
		{gFollowerMonPic0324_WhiscashPal, 0x142F},
		{gFollowerMonPic0325_LuvdiscPal,  0x1430},
		{gFollowerMonPic0326_CorphishPal, 0x1431},
		{gFollowerMonPic0327_CrawdauntPal, 0x1432},
		{gFollowerMonPic0328_FeebasPal,   0x1433},
		{gFollowerMonPic0329_MiloticPal,  0x1434},
		{gFollowerMonPic0330_CarvanhaPal, 0x1435},
		{gFollowerMonPic0331_SharpedoPal, 0x1436},
		{gFollowerMonPic0332_TrapinchPal, 0x1437},
		{gFollowerMonPic0333_VibravaPal,  0x1438},
		{gFollowerMonPic0334_FlygonPal,   0x1439},
		{gFollowerMonPic0335_MakuhitaPal, 0x143A},
		{gFollowerMonPic0336_HariyamaPal, 0x143B},
		{gFollowerMonPic0337_ElectrikePal, 0x143C},
		{gFollowerMonPic0338_ManectricPal, 0x143D},
		{gFollowerMonPic0339_NumelPal,    0x143E},
		{gFollowerMonPic0340_CameruptPal, 0x143F},
		{gFollowerMonPic0341_SphealPal,   0x1440},
		{gFollowerMonPic0342_SealeoPal,   0x1441},
		{gFollowerMonPic0343_WalreinPal,  0x1442},
		{gFollowerMonPic0344_CacneaPal,   0x1443},
		{gFollowerMonPic0345_CacturnePal, 0x1444},
		{gFollowerMonPic0346_SnoruntPal,  0x1445},
		{gFollowerMonPic0347_GlaliePal,   0x1446},
		{gFollowerMonPic0348_LunatonePal, 0x1447},
		{gFollowerMonPic0349_SolrockPal,  0x1448},
		{gFollowerMonPic0350_AzurillPal,  0x1449},
		{gFollowerMonPic0351_SpoinkPal,   0x144A},
		{gFollowerMonPic0352_GrumpigPal,  0x144B},
		{gFollowerMonPic0353_PluslePal,   0x144C},
		{gFollowerMonPic0354_MinunPal,    0x144D},
		{gFollowerMonPic0355_MawilePal,   0x144E},
		{gFollowerMonPic0356_MedititePal, 0x144F},
		{gFollowerMonPic0357_MedichamPal, 0x1450},
		{gFollowerMonPic0358_SwabluPal,   0x1451},
		{gFollowerMonPic0359_AltariaPal,  0x1452},
		{gFollowerMonPic0360_WynautPal,   0x1453},
		{gFollowerMonPic0361_DuskullPal,  0x1454},
		{gFollowerMonPic0362_DusclopsPal, 0x1455},
		{gFollowerMonPic0363_RoseliaPal,  0x1456},
		{gFollowerMonPic0364_SlakothPal,  0x1457},
		{gFollowerMonPic0365_VigorothPal, 0x1458},
		{gFollowerMonPic0366_SlakingPal,  0x1459},
		{gFollowerMonPic0367_GulpinPal,   0x145A},
		{gFollowerMonPic0368_SwalotPal,   0x145B},
		{gFollowerMonPic0369_TropiusPal,  0x145C},
		{gFollowerMonPic0370_WhismurPal,  0x145D},
		{gFollowerMonPic0371_LoudredPal,  0x145E},
		{gFollowerMonPic0372_ExploudPal,  0x145F},
		{gFollowerMonPic0373_ClamperlPal, 0x1460},
		{gFollowerMonPic0374_HuntailPal,  0x1461},
		{gFollowerMonPic0375_GorebyssPal, 0x1462},
		{gFollowerMonPic0376_AbsolPal,    0x1463},
		{gFollowerMonPic0377_ShuppetPal,  0x1464},
		{gFollowerMonPic0378_BanettePal,  0x1465},
		{gFollowerMonPic0379_SeviperPal,  0x1466},
		{gFollowerMonPic0380_ZangoosePal, 0x1467},
		{gFollowerMonPic0381_RelicanthPal, 0x1468},
		{gFollowerMonPic0382_AronPal,     0x1469},
		{gFollowerMonPic0383_LaironPal,   0x146A},
		{gFollowerMonPic0384_AggronPal,   0x146B},
		{gFollowerMonPic0385_CastformPal, 0x146C},
		{gFollowerMonPic0386_VolbeatPal,  0x146D},
		{gFollowerMonPic0387_IllumisePal, 0x146E},
		{gFollowerMonPic0388_LileepPal,   0x146F},
		{gFollowerMonPic0389_CradilyPal,  0x1470},
		{gFollowerMonPic0390_AnorithPal,  0x1471},
		{gFollowerMonPic0391_ArmaldoPal,  0x1472},
		{gFollowerMonPic0392_RaltsPal,    0x1473},
		{gFollowerMonPic0393_KirliaPal,   0x1474},
		{gFollowerMonPic0394_GardevoirPal, 0x1475},
		{gFollowerMonPic0395_BagonPal,    0x1476},
		{gFollowerMonPic0396_ShelgonPal,  0x1477},
		{gFollowerMonPic0397_SalamencePal, 0x1478},
		{gFollowerMonPic0398_BeldumPal,   0x1479},
		{gFollowerMonPic0399_MetangPal,   0x147A},
		{gFollowerMonPic0400_MetagrossPal, 0x147B},
		{gFollowerMonPic0401_RegirockPal, 0x147C},
		{gFollowerMonPic0402_RegicePal,   0x147D},
		{gFollowerMonPic0403_RegisteelPal, 0x147E},
		{gFollowerMonPic0404_KyogrePal,   0x147F},
		{gFollowerMonPic0405_GroudonPal,  0x1480},
		{gFollowerMonPic0406_RayquazaPal, 0x1481},
		{gFollowerMonPic0407_LatiasPal,   0x1482},
		{gFollowerMonPic0408_LatiosPal,   0x1483},
		{gFollowerMonPic0409_JirachiPal,  0x1484},
		{gFollowerMonPic0410_DeoxysPal,   0x1485},
		{gFollowerMonPic0411_ChimechoPal, 0x1486},
	// Gen 4
        {gFollowerMonPic0440_TurtwigPal, 0x1487},
        {gFollowerMonPic0441_GrotlePal, 0x1488},
        {gFollowerMonPic0442_TorterraPal, 0x1489},
        {gFollowerMonPic0443_ChimcharPal, 0x148A},
        {gFollowerMonPic0444_MonfernoPal, 0x148B},
        {gFollowerMonPic0445_InfernapePal, 0x148C},
        {gFollowerMonPic0446_PiplupPal, 0x148D},
        {gFollowerMonPic0447_PrinplupPal, 0x148E},
        {gFollowerMonPic0448_EmpoleonPal, 0x148F},
        {gFollowerMonPic0449_StarlyPal, 0x1490},
        {gFollowerMonPic0450_StaraviaPal, 0x1491},
        {gFollowerMonPic0451_StaraptorPal, 0x1492},
        {gFollowerMonPic0452_BidoofPal, 0x1493},
        {gFollowerMonPic0453_BibarelPal, 0x1494},
        {gFollowerMonPic0454_KricketotPal, 0x1495},
        {gFollowerMonPic0455_KricketunePal, 0x1496},
        {gFollowerMonPic0456_ShinxPal, 0x1497},
        {gFollowerMonPic0457_LuxioPal, 0x1498},
        {gFollowerMonPic0458_LuxrayPal, 0x1499},
        {gFollowerMonPic0459_BudewPal, 0x149A},
        {gFollowerMonPic0460_RoseradePal, 0x149B},
        {gFollowerMonPic0461_CranidosPal, 0x149C},
        {gFollowerMonPic0462_RampardosPal, 0x149D},
        {gFollowerMonPic0463_ShieldonPal, 0x149E},
        {gFollowerMonPic0464_BastiodonPal, 0x149F},
        {gFollowerMonPic0465_BurmyPal, 0x14A0},
        {gFollowerMonPic0466_WormadamPal, 0x14A1},
        {gFollowerMonPic0467_MothimPal, 0x14A2},
        {gFollowerMonPic0468_CombeePal, 0x14A3},
        {gFollowerMonPic0469_VespiquenPal, 0x14A4},
        {gFollowerMonPic0470_PachirisuPal, 0x14A5},
        {gFollowerMonPic0471_BuizelPal, 0x14A6},
        {gFollowerMonPic0472_FloatzelPal, 0x14A7},
        {gFollowerMonPic0473_CherubiPal, 0x14A8},
        {gFollowerMonPic0474_CherrimPal, 0x14A9},
        {gFollowerMonPic0475_ShellosPal, 0x14AA},
        {gFollowerMonPic0476_GastrodonPal, 0x14AB},
        {gFollowerMonPic0477_AmbipomPal, 0x14AC},
        {gFollowerMonPic0478_DrifloonPal, 0x14AD},
        {gFollowerMonPic0479_DrifblimPal, 0x14AE},
        {gFollowerMonPic0480_BunearyPal, 0x14AF},
        {gFollowerMonPic0481_LopunnyPal, 0x14B0},
        {gFollowerMonPic0482_MismagiusPal, 0x14B1},
        {gFollowerMonPic0483_HonchkrowPal, 0x14B2},
        {gFollowerMonPic0484_GlameowPal, 0x14B3},
        {gFollowerMonPic0485_PuruglyPal, 0x14B4},
        {gFollowerMonPic0486_ChinglingPal, 0x14B5},
        {gFollowerMonPic0487_StunkyPal, 0x14B6},
        {gFollowerMonPic0488_SkuntankPal, 0x14B7},
        {gFollowerMonPic0489_BronzorPal, 0x14B8},
        {gFollowerMonPic0490_BronzongPal, 0x14B9},
        {gFollowerMonPic0491_BonslyPal, 0x14BA},
        {gFollowerMonPic0492_MimeJrPal, 0x14BB},
        {gFollowerMonPic0493_HappinyPal, 0x14BC},
        {gFollowerMonPic0494_ChatotPal, 0x14BD},
        {gFollowerMonPic0495_SpiritombPal, 0x14BE},
        {gFollowerMonPic0496_GiblePal, 0x14BF},
        {gFollowerMonPic0497_GabitePal, 0x14C0},
        {gFollowerMonPic0498_GarchompPal, 0x14C1},
        {gFollowerMonPic0499_MunchlaxPal, 0x14C2},
        {gFollowerMonPic0500_RioluPal, 0x14C3},
        {gFollowerMonPic0501_LucarioPal, 0x14C4},
        {gFollowerMonPic0502_HippopotasPal, 0x14C5},
        {gFollowerMonPic0503_HippowdonPal, 0x14C6},
        {gFollowerMonPic0504_SkorupiPal, 0x14C7},
        {gFollowerMonPic0505_DrapionPal, 0x14C8},
        {gFollowerMonPic0506_CroagunkPal, 0x14C9},
        {gFollowerMonPic0507_ToxicroakPal, 0x14CA},
        {gFollowerMonPic0508_CarnivinePal, 0x14CB},
        {gFollowerMonPic0509_FinneonPal, 0x14CC},
        {gFollowerMonPic0510_LumineonPal, 0x14CD},
        {gFollowerMonPic0511_MantykePal, 0x14CE},
        {gFollowerMonPic0512_SnoverPal, 0x14CF},
        {gFollowerMonPic0513_AbomasnowPal, 0x14D0},
        {gFollowerMonPic0514_WeavilePal, 0x14D1},
        {gFollowerMonPic0515_MagnezonePal, 0x14D2},
        {gFollowerMonPic0516_LickilickyPal, 0x14D3},
        {gFollowerMonPic0517_RhyperiorPal, 0x14D4},
        {gFollowerMonPic0518_TangrowthPal, 0x14D5},
        {gFollowerMonPic0519_ElectivirePal, 0x14D6},
        {gFollowerMonPic0520_MagmortarPal, 0x14D7},
        {gFollowerMonPic0521_TogekissPal, 0x14D8},
        {gFollowerMonPic0522_YanmegaPal, 0x14D9},
        {gFollowerMonPic0523_LeafeonPal, 0x14DA},
        {gFollowerMonPic0524_GlaceonPal, 0x14DB},
        {gFollowerMonPic0525_GliscorPal, 0x14DC},
        {gFollowerMonPic0526_MamoswinePal, 0x14DD},
        {gFollowerMonPic0527_PorygonZPal, 0x14DE},
        {gFollowerMonPic0528_GalladePal, 0x14DF},
        {gFollowerMonPic0529_ProbopassPal, 0x14E0},
        {gFollowerMonPic0530_DusknoirPal, 0x14E1},
        {gFollowerMonPic0531_FroslassPal, 0x14E2},
        {gFollowerMonPic0532_RotomPal, 0x14E3},
        {gFollowerMonPic0533_UxiePal, 0x14E4},
        {gFollowerMonPic0534_MespritPal, 0x14E5},
        {gFollowerMonPic0535_AzelfPal, 0x14E6},
        {gFollowerMonPic0536_DialgaPal, 0x14E7},
        {gFollowerMonPic0537_PalkiaPal, 0x14E8},
        {gFollowerMonPic0538_HeatranPal, 0x14E9},
        {gFollowerMonPic0539_RegigigasPal, 0x14EA},
        {gFollowerMonPic0540_GiratinaPal, 0x14EB},
        {gFollowerMonPic0541_CresseliaPal, 0x14EC},
        {gFollowerMonPic0542_PhionePal, 0x14ED},
        {gFollowerMonPic0543_ManaphyPal, 0x14EE},
        {gFollowerMonPic0544_DarkraiPal, 0x14EF},
        {gFollowerMonPic0545_ShayminPal, 0x14F0},
        {gFollowerMonPic0546_ArceusPal, 0x14F1},
        {gFollowerMonPic0547_VictiniPal, 0x14F2},

	};

	const struct SpritePalette gObjectEventSpritePalettes15[] = 	
	{
    {gFollowerMonPic2277_TreeckoShinyPal,  0x1500},
    {gFollowerMonPic2278_GrovyleShinyPal,  0x1501},
    {gFollowerMonPic2279_SceptileShinyPal, 0x1502},
    {gFollowerMonPic2280_TorchicShinyPal,  0x1503},
    {gFollowerMonPic2281_CombuskenShinyPal, 0x1504},
    {gFollowerMonPic2282_BlazikenShinyPal, 0x1505},
    {gFollowerMonPic2283_MudkipShinyPal,   0x1506},
    {gFollowerMonPic2284_MarshtompShinyPal, 0x1507},
    {gFollowerMonPic2285_SwampertShinyPal, 0x1508},
    {gFollowerMonPic2286_PoochyenaShinyPal, 0x1509},
    {gFollowerMonPic2287_MightyenaShinyPal, 0x150A},
    {gFollowerMonPic2288_ZigzagoonShinyPal, 0x150B},
    {gFollowerMonPic2289_LinooneShinyPal,  0x150C},
    {gFollowerMonPic2290_WurmpleShinyPal,  0x150D},
    {gFollowerMonPic2291_SilcoonShinyPal,  0x150E},
    {gFollowerMonPic2292_BeautiflyShinyPal, 0x150F},
    {gFollowerMonPic2293_CascoonShinyPal,  0x1510},
    {gFollowerMonPic2294_DustoxShinyPal,   0x1511},
    {gFollowerMonPic2295_LotadShinyPal,    0x1512},
    {gFollowerMonPic2296_LombreShinyPal,   0x1513},
    {gFollowerMonPic2297_LudicoloShinyPal, 0x1514},
    {gFollowerMonPic2298_SeedotShinyPal,   0x1515},
    {gFollowerMonPic2299_NuzleafShinyPal,  0x1516},
    {gFollowerMonPic2300_ShiftryShinyPal,  0x1517},
    {gFollowerMonPic2301_NincadaShinyPal,  0x1518},
    {gFollowerMonPic2302_NinjaskShinyPal,  0x1519},
    {gFollowerMonPic2303_ShedinjaShinyPal, 0x151A},
    {gFollowerMonPic2304_TaillowShinyPal,  0x151B},
    {gFollowerMonPic2305_SwellowShinyPal,  0x151C},
    {gFollowerMonPic2306_ShroomishShinyPal, 0x151D},
    {gFollowerMonPic2307_BreloomShinyPal,  0x151E},
    {gFollowerMonPic2308_SpindaShinyPal,   0x151F},
    {gFollowerMonPic2309_WingullShinyPal,  0x1520},
    {gFollowerMonPic2310_PelipperShinyPal, 0x1521},
    {gFollowerMonPic2311_SurskitShinyPal,  0x1522},
    {gFollowerMonPic2312_MasquerainShinyPal, 0x1523},
    {gFollowerMonPic2313_WailmerShinyPal,  0x1524},
    {gFollowerMonPic2314_WailordShinyPal,  0x1525},
    {gFollowerMonPic2315_SkittyShinyPal,   0x1526},
    {gFollowerMonPic2316_DelcattyShinyPal, 0x1527},
    {gFollowerMonPic2317_KecleonShinyPal,  0x1528},
    {gFollowerMonPic2318_BaltoyShinyPal,   0x1529},
    {gFollowerMonPic2319_ClaydolShinyPal,  0x152A},
    {gFollowerMonPic2320_NosepassShinyPal, 0x152B},
    {gFollowerMonPic2321_TorkoalShinyPal,  0x152C},
    {gFollowerMonPic2322_SableyeShinyPal,  0x152D},
    {gFollowerMonPic2323_BarboachShinyPal, 0x152E},
    {gFollowerMonPic2324_WhiscashShinyPal, 0x152F},
    {gFollowerMonPic2325_LuvdiscShinyPal,  0x1530},
    {gFollowerMonPic2326_CorphishShinyPal, 0x1531},
    {gFollowerMonPic2327_CrawdauntShinyPal, 0x1532},
    {gFollowerMonPic2328_FeebasShinyPal,   0x1533},
    {gFollowerMonPic2329_MiloticShinyPal,  0x1534},
    {gFollowerMonPic2330_CarvanhaShinyPal, 0x1535},
    {gFollowerMonPic2331_SharpedoShinyPal, 0x1536},
    {gFollowerMonPic2332_TrapinchShinyPal, 0x1537},
    {gFollowerMonPic2333_VibravaShinyPal,  0x1538},
    {gFollowerMonPic2334_FlygonShinyPal,   0x1539},
    {gFollowerMonPic2335_MakuhitaShinyPal, 0x153A},
    {gFollowerMonPic2336_HariyamaShinyPal, 0x153B},
    {gFollowerMonPic2337_ElectrikeShinyPal, 0x153C},
    {gFollowerMonPic2338_ManectricShinyPal, 0x153D},
    {gFollowerMonPic2339_NumelShinyPal,    0x153E},
    {gFollowerMonPic2340_CameruptShinyPal, 0x153F},
    {gFollowerMonPic2341_SphealShinyPal,   0x1540},
    {gFollowerMonPic2342_SealeoShinyPal,   0x1541},
    {gFollowerMonPic2343_WalreinShinyPal,  0x1542},
    {gFollowerMonPic2344_CacneaShinyPal,   0x1543},
    {gFollowerMonPic2345_CacturneShinyPal, 0x1544},
    {gFollowerMonPic2346_SnoruntShinyPal,  0x1545},
    {gFollowerMonPic2347_GlalieShinyPal,   0x1546},
    {gFollowerMonPic2348_LunatoneShinyPal, 0x1547},
    {gFollowerMonPic2349_SolrockShinyPal,  0x1548},
    {gFollowerMonPic2350_AzurillShinyPal,  0x1549},
    {gFollowerMonPic2351_SpoinkShinyPal,   0x154A},
    {gFollowerMonPic2352_GrumpigShinyPal,  0x154B},
    {gFollowerMonPic2353_PlusleShinyPal,   0x154C},
    {gFollowerMonPic2354_MinunShinyPal,    0x154D},
    {gFollowerMonPic2355_MawileShinyPal,   0x154E},
    {gFollowerMonPic2356_MedititeShinyPal, 0x154F},
    {gFollowerMonPic2357_MedichamShinyPal, 0x1550},
    {gFollowerMonPic2358_SwabluShinyPal,   0x1551},
    {gFollowerMonPic2359_AltariaShinyPal,  0x1552},
    {gFollowerMonPic2360_WynautShinyPal,   0x1553},
    {gFollowerMonPic2361_DuskullShinyPal,  0x1554},
    {gFollowerMonPic2362_DusclopsShinyPal, 0x1555},
    {gFollowerMonPic2363_RoseliaShinyPal,  0x1556},
    {gFollowerMonPic2364_SlakothShinyPal,  0x1557},
    {gFollowerMonPic2365_VigorothShinyPal, 0x1558},
    {gFollowerMonPic2366_SlakingShinyPal,  0x1559},
    {gFollowerMonPic2367_GulpinShinyPal,   0x155A},
    {gFollowerMonPic2368_SwalotShinyPal,   0x155B},
    {gFollowerMonPic2369_TropiusShinyPal,  0x155C},
    {gFollowerMonPic2370_WhismurShinyPal,  0x155D},
    {gFollowerMonPic2371_LoudredShinyPal,  0x155E},
    {gFollowerMonPic2372_ExploudShinyPal,  0x155F},
    {gFollowerMonPic2373_ClamperlShinyPal, 0x1560},
    {gFollowerMonPic2374_HuntailShinyPal,  0x1561},
    {gFollowerMonPic2375_GorebyssShinyPal, 0x1562},
    {gFollowerMonPic2376_AbsolShinyPal,    0x1563},
    {gFollowerMonPic2377_ShuppetShinyPal,  0x1564},
    {gFollowerMonPic2378_BanetteShinyPal,  0x1565},
    {gFollowerMonPic2379_SeviperShinyPal,  0x1566},
    {gFollowerMonPic2380_ZangooseShinyPal, 0x1567},
    {gFollowerMonPic2381_RelicanthShinyPal, 0x1568},
    {gFollowerMonPic2382_AronShinyPal,     0x1569},
    {gFollowerMonPic2383_LaironShinyPal,   0x156A},
    {gFollowerMonPic2384_AggronShinyPal,   0x156B},
    {gFollowerMonPic2385_CastformShinyPal, 0x156C},
    {gFollowerMonPic2386_VolbeatShinyPal,  0x156D},
    {gFollowerMonPic2387_IllumiseShinyPal, 0x156E},
    {gFollowerMonPic2388_LileepShinyPal,   0x156F},
    {gFollowerMonPic2389_CradilyShinyPal,  0x1570},
    {gFollowerMonPic2390_AnorithShinyPal,  0x1571},
    {gFollowerMonPic2391_ArmaldoShinyPal,  0x1572},
    {gFollowerMonPic2392_RaltsShinyPal,    0x1573},
    {gFollowerMonPic2393_KirliaShinyPal,   0x1574},
    {gFollowerMonPic2394_GardevoirShinyPal, 0x1575},
    {gFollowerMonPic2395_BagonShinyPal,    0x1576},
    {gFollowerMonPic2396_ShelgonShinyPal,  0x1577},
    {gFollowerMonPic2397_SalamenceShinyPal, 0x1578},
    {gFollowerMonPic2398_BeldumShinyPal,   0x1579},
    {gFollowerMonPic2399_MetangShinyPal,   0x157A},
    {gFollowerMonPic2400_MetagrossShinyPal, 0x157B},
    {gFollowerMonPic2401_RegirockShinyPal, 0x157C},
    {gFollowerMonPic2402_RegiceShinyPal,   0x157D},
    {gFollowerMonPic2403_RegisteelShinyPal, 0x157E},
    {gFollowerMonPic2404_KyogreShinyPal,   0x157F},
    {gFollowerMonPic2405_GroudonShinyPal,  0x1580},
    {gFollowerMonPic2406_RayquazaShinyPal, 0x1581},
    {gFollowerMonPic2407_LatiasShinyPal,   0x1582},
    {gFollowerMonPic2408_LatiosShinyPal,   0x1583},
    {gFollowerMonPic2409_JirachiShinyPal,  0x1584},
    {gFollowerMonPic2410_DeoxysShinyPal,   0x1585},
    {gFollowerMonPic2411_ChimechoShinyPal, 0x1586},
	// Gen 4
	{gFollowerMonPic2440_TurtwigShinyPal, 0x1587},
	{gFollowerMonPic2441_GrotleShinyPal, 0x1588},
	{gFollowerMonPic2442_TorterraShinyPal, 0x1589},
	{gFollowerMonPic2443_ChimcharShinyPal, 0x158A},
	{gFollowerMonPic2444_MonfernoShinyPal, 0x158B},
	{gFollowerMonPic2445_InfernapeShinyPal, 0x158C},
	{gFollowerMonPic2446_PiplupShinyPal, 0x158D},
	{gFollowerMonPic2447_PrinplupShinyPal, 0x158E},
	{gFollowerMonPic2448_EmpoleonShinyPal, 0x158F},
	{gFollowerMonPic2449_StarlyShinyPal, 0x1590},
	{gFollowerMonPic2450_StaraviaShinyPal, 0x1591},
	{gFollowerMonPic2451_StaraptorShinyPal, 0x1592},
	{gFollowerMonPic2452_BidoofShinyPal, 0x1593},
	{gFollowerMonPic2453_BibarelShinyPal, 0x1594},
	{gFollowerMonPic2454_KricketotShinyPal, 0x1595},
	{gFollowerMonPic2455_KricketuneShinyPal, 0x1596},
	{gFollowerMonPic2456_ShinxShinyPal, 0x1597},
	{gFollowerMonPic2457_LuxioShinyPal, 0x1598},
	{gFollowerMonPic2458_LuxrayShinyPal, 0x1599},
	{gFollowerMonPic2459_BudewShinyPal, 0x159A},
	{gFollowerMonPic2460_RoseradeShinyPal, 0x159B},
	{gFollowerMonPic2461_CranidosShinyPal, 0x159C},
	{gFollowerMonPic2462_RampardosShinyPal, 0x159D},
	{gFollowerMonPic2463_ShieldonShinyPal, 0x159E},
	{gFollowerMonPic2464_BastiodonShinyPal, 0x159F},
	{gFollowerMonPic2465_BurmyShinyPal, 0x15A0},
	{gFollowerMonPic2466_WormadamShinyPal, 0x15A1},
	{gFollowerMonPic2467_MothimShinyPal, 0x15A2},
	{gFollowerMonPic2468_CombeeShinyPal, 0x15A3},
	{gFollowerMonPic2469_VespiquenShinyPal, 0x15A4},
	{gFollowerMonPic2470_PachirisuShinyPal, 0x15A5},
	{gFollowerMonPic2471_BuizelShinyPal, 0x15A6},
	{gFollowerMonPic2472_FloatzelShinyPal, 0x15A7},
	{gFollowerMonPic2473_CherubiShinyPal, 0x15A8},
	{gFollowerMonPic2474_CherrimShinyPal, 0x15A9},
	{gFollowerMonPic2475_ShellosShinyPal, 0x15AA},
	{gFollowerMonPic2476_GastrodonShinyPal, 0x15AB},
	{gFollowerMonPic2477_AmbipomShinyPal, 0x15AC},
	{gFollowerMonPic2478_DrifloonShinyPal, 0x15AD},
	{gFollowerMonPic2479_DrifblimShinyPal, 0x15AE},
	{gFollowerMonPic2480_BunearyShinyPal, 0x15AF},
	{gFollowerMonPic2481_LopunnyShinyPal, 0x15B0},
	{gFollowerMonPic2482_MismagiusShinyPal, 0x15B1},
	{gFollowerMonPic2483_HonchkrowShinyPal, 0x15B2},
	{gFollowerMonPic2484_GlameowShinyPal, 0x15B3},
	{gFollowerMonPic2485_PuruglyShinyPal, 0x15B4},
	{gFollowerMonPic2486_ChinglingShinyPal, 0x15B5},
	{gFollowerMonPic2487_StunkyShinyPal, 0x15B6},
	{gFollowerMonPic2488_SkuntankShinyPal, 0x15B7},
	{gFollowerMonPic2489_BronzorShinyPal, 0x15B8},
	{gFollowerMonPic2490_BronzongShinyPal, 0x15B9},
	{gFollowerMonPic2491_BonslyShinyPal, 0x15BA},
	{gFollowerMonPic2492_MimeJrShinyPal, 0x15BB},
	{gFollowerMonPic2493_HappinyShinyPal, 0x15BC},
	{gFollowerMonPic2494_ChatotShinyPal, 0x15BD},
	{gFollowerMonPic2495_SpiritombShinyPal, 0x15BE},
	{gFollowerMonPic2496_GibleShinyPal, 0x15BF},
	{gFollowerMonPic2497_GabiteShinyPal, 0x15C0},
	{gFollowerMonPic2498_GarchompShinyPal, 0x15C1},
	{gFollowerMonPic2499_MunchlaxShinyPal, 0x15C2},
	{gFollowerMonPic2500_RioluShinyPal, 0x15C3},
	{gFollowerMonPic2501_LucarioShinyPal, 0x15C4},
	{gFollowerMonPic2502_HippopotasShinyPal, 0x15C5},
	{gFollowerMonPic2503_HippowdonShinyPal, 0x15C6},
	{gFollowerMonPic2504_SkorupiShinyPal, 0x15C7},
	{gFollowerMonPic2505_DrapionShinyPal, 0x15C8},
	{gFollowerMonPic2506_CroagunkShinyPal, 0x15C9},
	{gFollowerMonPic2507_ToxicroakShinyPal, 0x15CA},
	{gFollowerMonPic2508_CarnivineShinyPal, 0x15CB},
	{gFollowerMonPic2509_FinneonShinyPal, 0x15CC},
	{gFollowerMonPic2510_LumineonShinyPal, 0x15CD},
	{gFollowerMonPic2511_MantykeShinyPal, 0x15CE},
	{gFollowerMonPic2512_SnoverShinyPal, 0x15CF},
	{gFollowerMonPic2513_AbomasnowShinyPal, 0x15D0},
	{gFollowerMonPic2514_WeavileShinyPal, 0x15D1},
	{gFollowerMonPic2515_MagnezoneShinyPal, 0x15D2},
	{gFollowerMonPic2516_LickilickyShinyPal, 0x15D3},
	{gFollowerMonPic2517_RhyperiorShinyPal, 0x15D4},
	{gFollowerMonPic2518_TangrowthShinyPal, 0x15D5},
	{gFollowerMonPic2519_ElectivireShinyPal, 0x15D6},
	{gFollowerMonPic2520_MagmortarShinyPal, 0x15D7},
	{gFollowerMonPic2521_TogekissShinyPal, 0x15D8},
	{gFollowerMonPic2522_YanmegaShinyPal, 0x15D9},
	{gFollowerMonPic2523_LeafeonShinyPal, 0x15DA},
	{gFollowerMonPic2524_GlaceonShinyPal, 0x15DB},
	{gFollowerMonPic2525_GliscorShinyPal, 0x15DC},
	{gFollowerMonPic2526_MamoswineShinyPal, 0x15DD},
	{gFollowerMonPic2527_PorygonZShinyPal, 0x15DE},
	{gFollowerMonPic2528_GalladeShinyPal, 0x15DF},
	{gFollowerMonPic2529_ProbopassShinyPal, 0x15E0},
	{gFollowerMonPic2530_DusknoirShinyPal, 0x15E1},
	{gFollowerMonPic2531_FroslassShinyPal, 0x15E2},
	{gFollowerMonPic2532_RotomShinyPal, 0x15E3},
	{gFollowerMonPic2533_UxieShinyPal, 0x15E4},
	{gFollowerMonPic2534_MespritShinyPal, 0x15E5},
	{gFollowerMonPic2535_AzelfShinyPal, 0x15E6},
	{gFollowerMonPic2536_DialgaShinyPal, 0x15E7},
	{gFollowerMonPic2537_PalkiaShinyPal, 0x15E8},
	{gFollowerMonPic2538_HeatranShinyPal, 0x15E9},
	{gFollowerMonPic2539_RegigigasShinyPal, 0x15EA},
	{gFollowerMonPic2540_GiratinaShinyPal, 0x15EB},
	{gFollowerMonPic2541_CresseliaShinyPal, 0x15EC},
	{gFollowerMonPic2542_PhioneShinyPal, 0x15ED},
	{gFollowerMonPic2543_ManaphyShinyPal, 0x15EE},
	{gFollowerMonPic2544_DarkraiShinyPal, 0x15EF},
	{gFollowerMonPic2545_ShayminShinyPal, 0x15F0},
	{gFollowerMonPic2546_ArceusShinyPal, 0x15F1},
	{gFollowerMonPic2547_VictiniShinyPal, 0x15F2},
	};

	const struct SpritePalette gObjectEventSpritePalettes16[] = 	
	{
		// Gen 5
        {gFollowerMonPic0548_SnivyPal, 0x1600},
        {gFollowerMonPic0549_ServinePal, 0x1601},
        {gFollowerMonPic0550_SerperiorPal, 0x1602},
        {gFollowerMonPic0551_TepigPal, 0x1603},
        {gFollowerMonPic0552_PignitePal, 0x1604},
        {gFollowerMonPic0553_EmboarPal, 0x1605},
        {gFollowerMonPic0554_OshawottPal, 0x1606},
        {gFollowerMonPic0555_DewottPal, 0x1607},
        {gFollowerMonPic0556_SamurottPal, 0x1608},
        {gFollowerMonPic0557_PatratPal, 0x1609},
        {gFollowerMonPic0558_WatchogPal, 0x160A},
        {gFollowerMonPic0559_LillipupPal, 0x160B},
        {gFollowerMonPic0560_HerdierPal, 0x160C},
        {gFollowerMonPic0561_StoutlandPal, 0x160D},
        {gFollowerMonPic0562_PurrloinPal, 0x160E},
        {gFollowerMonPic0563_LiepardPal, 0x160F},
        {gFollowerMonPic0564_PansagePal, 0x1610},
        {gFollowerMonPic0565_SimisagePal, 0x1611},
        {gFollowerMonPic0566_PansearPal, 0x1612},
        {gFollowerMonPic0567_SimisearPal, 0x1613},
        {gFollowerMonPic0568_PanpourPal, 0x1614},
        {gFollowerMonPic0569_SimipourPal, 0x1615},
        {gFollowerMonPic0570_MunnaPal, 0x1616},
        {gFollowerMonPic0571_MusharnaPal, 0x1617},
        {gFollowerMonPic0572_PidovePal, 0x1618},
        {gFollowerMonPic0573_TranquillPal, 0x1619},
        {gFollowerMonPic0574_UnfezantPal, 0x161A},
        {gFollowerMonPic0575_BlitzlePal, 0x161B},
        {gFollowerMonPic0576_ZebstrikaPal, 0x161C},
        {gFollowerMonPic0577_RoggenrolaPal, 0x161D},
        {gFollowerMonPic0578_BoldorePal, 0x161E},
        {gFollowerMonPic0579_GigalithPal, 0x161F},
        {gFollowerMonPic0580_WoobatPal, 0x1620},
        {gFollowerMonPic0581_SwoobatPal, 0x1621},
        {gFollowerMonPic0582_DrilburPal, 0x1622},
        {gFollowerMonPic0583_ExcadrillPal, 0x1623},
        {gFollowerMonPic0584_AudinoPal, 0x1624},
        {gFollowerMonPic0585_TimburrPal, 0x1625},
        {gFollowerMonPic0586_GurdurrPal, 0x1626},
        {gFollowerMonPic0587_ConkeldurrPal, 0x1627},
        {gFollowerMonPic0588_TympolePal, 0x1628},
        {gFollowerMonPic0589_PalpitoadPal, 0x1629},
        {gFollowerMonPic0590_SeismitoadPal, 0x162A},
        {gFollowerMonPic0591_ThrohPal, 0x162B},
        {gFollowerMonPic0592_SawkPal, 0x162C},
        {gFollowerMonPic0593_SewaddlePal, 0x162D},
        {gFollowerMonPic0594_SwadloonPal, 0x162E},
        {gFollowerMonPic0595_LeavannyPal, 0x162F},
        {gFollowerMonPic0596_VenipedePal, 0x1630},
        {gFollowerMonPic0597_WhirlipedePal, 0x1631},
        {gFollowerMonPic0598_ScolipedePal, 0x1632},
        {gFollowerMonPic0599_CottoneePal, 0x1633},
        {gFollowerMonPic0600_WhimsicottPal, 0x1634},
        {gFollowerMonPic0601_PetililPal, 0x1635},
        {gFollowerMonPic0602_LilligantPal, 0x1636},
        {gFollowerMonPic0603_BasculinRedPal, 0x1637},
        {gFollowerMonPic0604_SandilePal, 0x1638},
        {gFollowerMonPic0605_KrokorokPal, 0x1639},
        {gFollowerMonPic0606_KrookodilePal, 0x163A},
        {gFollowerMonPic0607_DarumakaPal, 0x163B},
        {gFollowerMonPic0608_DarmanitanPal, 0x163C},
        {gFollowerMonPic0609_MaractusPal, 0x163D},
        {gFollowerMonPic0610_DwebblePal, 0x163E},
        {gFollowerMonPic0611_CrustlePal, 0x163F},
        {gFollowerMonPic0612_ScraggyPal, 0x1640},
        {gFollowerMonPic0613_ScraftyPal, 0x1641},
        {gFollowerMonPic0614_SigilyphPal, 0x1642},
        {gFollowerMonPic0615_YamaskPal, 0x1643},
        {gFollowerMonPic0616_CofagrigusPal, 0x1644},
        {gFollowerMonPic0617_TirtougaPal, 0x1645},
        {gFollowerMonPic0618_CarracostaPal, 0x1646},
        {gFollowerMonPic0619_ArchenPal, 0x1647},
        {gFollowerMonPic0620_ArcheopsPal, 0x1648},
        {gFollowerMonPic0621_TrubbishPal, 0x1649},
        {gFollowerMonPic0622_GarbodorPal, 0x164A},
        {gFollowerMonPic0623_ZoruaPal, 0x164B},
        {gFollowerMonPic0624_ZoroarkPal, 0x164C},
        {gFollowerMonPic0625_MinccinoPal, 0x164D},
        {gFollowerMonPic0626_CinccinoPal, 0x164E},
        {gFollowerMonPic0627_GothitaPal, 0x164F},
        {gFollowerMonPic0628_GothoritaPal, 0x1650},
        {gFollowerMonPic0629_GothitellePal, 0x1651},
        {gFollowerMonPic0630_SolosisPal, 0x1652},
        {gFollowerMonPic0631_DuosionPal, 0x1653},
        {gFollowerMonPic0632_ReuniclusPal, 0x1654},
        {gFollowerMonPic0633_DucklettPal, 0x1655},
        {gFollowerMonPic0634_SwannaPal, 0x1656},
        {gFollowerMonPic0635_VanillitePal, 0x1657},
        {gFollowerMonPic0636_VanillishPal, 0x1658},
        {gFollowerMonPic0637_VanilluxePal, 0x1659},
        {gFollowerMonPic0638_DeerlingPal, 0x165A},
        {gFollowerMonPic0639_SawsbuckPal, 0x165B},
        {gFollowerMonPic0640_EmolgaPal, 0x165C},
        {gFollowerMonPic0641_KarrablastPal, 0x165D},
        {gFollowerMonPic0642_EscavalierPal, 0x165E},
        {gFollowerMonPic0643_FoongusPal, 0x165F},
        {gFollowerMonPic0644_AmoongussPal, 0x1660},
        {gFollowerMonPic0645_FrillishPal, 0x1661},
        {gFollowerMonPic0646_JellicentPal, 0x1662},
        {gFollowerMonPic0647_AlomomolaPal, 0x1663},
        {gFollowerMonPic0648_JoltikPal, 0x1664},
        {gFollowerMonPic0649_GalvantulaPal, 0x1665},
        {gFollowerMonPic0650_FerroseedPal, 0x1666},
        {gFollowerMonPic0651_FerrothornPal, 0x1667},
        {gFollowerMonPic0652_KlinkPal, 0x1668},
        {gFollowerMonPic0653_KlangPal, 0x1669},
        {gFollowerMonPic0654_KlinklangPal, 0x166A},
        {gFollowerMonPic0655_TynamoPal, 0x166B},
        {gFollowerMonPic0656_EelektrikPal, 0x166C},
        {gFollowerMonPic0657_EelektrossPal, 0x166D},
        {gFollowerMonPic0658_ElgyemPal, 0x166E},
        {gFollowerMonPic0659_BeheeyemPal, 0x166F},
        {gFollowerMonPic0660_LitwickPal, 0x1670},
        {gFollowerMonPic0661_LampentPal, 0x1671},
        {gFollowerMonPic0662_ChandelurePal, 0x1672},
        {gFollowerMonPic0663_AxewPal, 0x1673},
        {gFollowerMonPic0664_FraxurePal, 0x1674},
        {gFollowerMonPic0665_HaxorusPal, 0x1675},
        {gFollowerMonPic0666_CubchooPal, 0x1676},
        {gFollowerMonPic0667_BearticPal, 0x1677},
        {gFollowerMonPic0668_CryogonalPal, 0x1678},
        {gFollowerMonPic0669_ShelmetPal, 0x1679},
        {gFollowerMonPic0670_AccelgorPal, 0x167A},
        {gFollowerMonPic0671_StunfiskPal, 0x167B},
        {gFollowerMonPic0672_MienfooPal, 0x167C},
        {gFollowerMonPic0673_MienshaoPal, 0x167D},
        {gFollowerMonPic0674_DruddigonPal, 0x167E},
        {gFollowerMonPic0675_GolettPal, 0x167F},
        {gFollowerMonPic0676_GolurkPal, 0x1680},
        {gFollowerMonPic0677_PawniardPal, 0x1681},
        {gFollowerMonPic0678_BisharpPal, 0x1682},
        {gFollowerMonPic0679_BouffalantPal, 0x1683},
        {gFollowerMonPic0680_RuffletPal, 0x1684},
        {gFollowerMonPic0681_BraviaryPal, 0x1685},
        {gFollowerMonPic0682_VullabyPal, 0x1686},
        {gFollowerMonPic0683_MandibuzzPal, 0x1687},
        {gFollowerMonPic0684_HeatmorPal, 0x1688},
        {gFollowerMonPic0685_DurantPal, 0x1689},
        {gFollowerMonPic0686_DeinoPal, 0x168A},
        {gFollowerMonPic0687_ZweilousPal, 0x168B},
        {gFollowerMonPic0688_HydreigonPal, 0x168C},
        {gFollowerMonPic0689_LarvestaPal, 0x168D},
        {gFollowerMonPic0690_VolcaronaPal, 0x168E},
        {gFollowerMonPic0691_CobalionPal, 0x168F},
        {gFollowerMonPic0692_TerrakionPal, 0x1690},
        {gFollowerMonPic0693_VirizionPal, 0x1691},
        {gFollowerMonPic0694_TornadusPal, 0x1692},
        {gFollowerMonPic0695_ThundurusPal, 0x1693},
        {gFollowerMonPic0696_ReshiramPal, 0x1694},
        {gFollowerMonPic0697_ZekromPal, 0x1695},
        {gFollowerMonPic0698_LandorusPal, 0x1696},
        {gFollowerMonPic0699_KyuremPal, 0x1697},
        {gFollowerMonPic0700_KeldeoPal, 0x1698},
        {gFollowerMonPic0701_MeloettaPal, 0x1699},
        {gFollowerMonPic0702_GenesectPal, 0x169A},
		{gFollowerMonPic0703_Unfezant_FPal, 0x169B},
		{gFollowerMonPic0704_Frillish_FPal, 0x169C},
		{gFollowerMonPic0705_Jellicent_FPal, 0x169D},
		{gFollowerMonPic0711_ShellosEastPal, 0x169E},
		{gFollowerMonPic0712_GastrodonEastPal, 0x169F},
        {gFollowerMonPic0713_RotomHeatPal, 0x16A0},
        {gFollowerMonPic0714_RotomWashPal, 0x16A1},
        {gFollowerMonPic0715_RotomFrostPal, 0x16A2},
        {gFollowerMonPic0716_RotomFanPal, 0x16A3},
        {gFollowerMonPic0717_RotomMowPal, 0x16A4},
		{gFollowerMonPic0718_GiratinaOriginPal, 0x16A5},
		{gFollowerMonPic0719_ShayminSkyPal, 0x16A6},
		{gFollowerMonPic0720_ArceusFightPal, 0x16A7},
        {gFollowerMonPic0721_ArceusFlyingPal, 0x16A8},
        {gFollowerMonPic0722_ArceusPoisonPal, 0x16A9},
        {gFollowerMonPic0723_ArceusGroundPal, 0x16AA},
        {gFollowerMonPic0724_ArceusRockPal, 0x16AB},
        {gFollowerMonPic0725_ArceusBugPal, 0x16AC},
        {gFollowerMonPic0726_ArceusGhostPal, 0x16AD},
        {gFollowerMonPic0727_ArceusSteelPal, 0x16AE},
        {gFollowerMonPic0728_ArceusFirePal, 0x16AF},
        {gFollowerMonPic0729_ArceusWaterPal, 0x16B0},
        {gFollowerMonPic0730_ArceusGrassPal, 0x16B1},
        {gFollowerMonPic0731_ArceusElectricPal, 0x16B2},
        {gFollowerMonPic0732_ArceusPsychicPal, 0x16B3},
        {gFollowerMonPic0733_ArceusIcePal, 0x16B4},
        {gFollowerMonPic0734_ArceusDragonPal, 0x16B5},
        {gFollowerMonPic0735_ArceusDarkPal, 0x16B6},
	};

	const struct SpritePalette gObjectEventSpritePalettes17[] = 	
	{
        {gFollowerMonPic2548_SnivyShinyPal, 0x1700},
        {gFollowerMonPic2549_ServineShinyPal, 0x1701},
        {gFollowerMonPic2550_SerperiorShinyPal, 0x1702},
        {gFollowerMonPic2551_TepigShinyPal, 0x1703},
        {gFollowerMonPic2552_PigniteShinyPal, 0x1704},
        {gFollowerMonPic2553_EmboarShinyPal, 0x1705},
        {gFollowerMonPic2554_OshawottShinyPal, 0x1706},
        {gFollowerMonPic2555_DewottShinyPal, 0x1707},
        {gFollowerMonPic2556_SamurottShinyPal, 0x1708},
        {gFollowerMonPic2557_PatratShinyPal, 0x1709},
        {gFollowerMonPic2558_WatchogShinyPal, 0x170A},
        {gFollowerMonPic2559_LillipupShinyPal, 0x170B},
        {gFollowerMonPic2560_HerdierShinyPal, 0x170C},
        {gFollowerMonPic2561_StoutlandShinyPal, 0x170D},
        {gFollowerMonPic2562_PurrloinShinyPal, 0x170E},
        {gFollowerMonPic2563_LiepardShinyPal, 0x170F},
        {gFollowerMonPic2564_PansageShinyPal, 0x1710},
        {gFollowerMonPic2565_SimisageShinyPal, 0x1711},
        {gFollowerMonPic2566_PansearShinyPal, 0x1712},
        {gFollowerMonPic2567_SimisearShinyPal, 0x1713},
        {gFollowerMonPic2568_PanpourShinyPal, 0x1714},
        {gFollowerMonPic2569_SimipourShinyPal, 0x1715},
        {gFollowerMonPic2570_MunnaShinyPal, 0x1716},
        {gFollowerMonPic2571_MusharnaShinyPal, 0x1717},
        {gFollowerMonPic2572_PidoveShinyPal, 0x1718},
        {gFollowerMonPic2573_TranquillShinyPal, 0x1719},
        {gFollowerMonPic2574_UnfezantShinyPal, 0x171A},
        {gFollowerMonPic2575_BlitzleShinyPal, 0x171B},
        {gFollowerMonPic2576_ZebstrikaShinyPal, 0x171C},
        {gFollowerMonPic2577_RoggenrolaShinyPal, 0x171D},
        {gFollowerMonPic2578_BoldoreShinyPal, 0x171E},
        {gFollowerMonPic2579_GigalithShinyPal, 0x171F},
        {gFollowerMonPic2580_WoobatShinyPal, 0x1720},
        {gFollowerMonPic2581_SwoobatShinyPal, 0x1721},
        {gFollowerMonPic2582_DrilburShinyPal, 0x1722},
        {gFollowerMonPic2583_ExcadrillShinyPal, 0x1723},
        {gFollowerMonPic2584_AudinoShinyPal, 0x1724},
        {gFollowerMonPic2585_TimburrShinyPal, 0x1725},
        {gFollowerMonPic2586_GurdurrShinyPal, 0x1726},
        {gFollowerMonPic2587_ConkeldurrShinyPal, 0x1727},
        {gFollowerMonPic2588_TympoleShinyPal, 0x1728},
        {gFollowerMonPic2589_PalpitoadShinyPal, 0x1729},
        {gFollowerMonPic2590_SeismitoadShinyPal, 0x172A},
        {gFollowerMonPic2591_ThrohShinyPal, 0x172B},
        {gFollowerMonPic2592_SawkShinyPal, 0x172C},
        {gFollowerMonPic2593_SewaddleShinyPal, 0x172D},
        {gFollowerMonPic2594_SwadloonShinyPal, 0x172E},
        {gFollowerMonPic2595_LeavannyShinyPal, 0x172F},
        {gFollowerMonPic2596_VenipedeShinyPal, 0x1730},
        {gFollowerMonPic2597_WhirlipedeShinyPal, 0x1731},
        {gFollowerMonPic2598_ScolipedeShinyPal, 0x1732},
        {gFollowerMonPic2599_CottoneeShinyPal, 0x1733},
        {gFollowerMonPic2600_WhimsicottShinyPal, 0x1734},
        {gFollowerMonPic2601_PetililShinyPal, 0x1735},
        {gFollowerMonPic2602_LilligantShinyPal, 0x1736},
        {gFollowerMonPic2603_BasculinRedShinyPal, 0x1737},
        {gFollowerMonPic2604_SandileShinyPal, 0x1738},
        {gFollowerMonPic2605_KrokorokShinyPal, 0x1739},
        {gFollowerMonPic2606_KrookodileShinyPal, 0x173A},
        {gFollowerMonPic2607_DarumakaShinyPal, 0x173B},
        {gFollowerMonPic2608_DarmanitanShinyPal, 0x173C},
        {gFollowerMonPic2609_MaractusShinyPal, 0x173D},
        {gFollowerMonPic2610_DwebbleShinyPal, 0x173E},
        {gFollowerMonPic2611_CrustleShinyPal, 0x173F},
        {gFollowerMonPic2612_ScraggyShinyPal, 0x1740},
        {gFollowerMonPic2613_ScraftyShinyPal, 0x1741},
        {gFollowerMonPic2614_SigilyphShinyPal, 0x1742},
        {gFollowerMonPic2615_YamaskShinyPal, 0x1743},
        {gFollowerMonPic2616_CofagrigusShinyPal, 0x1744},
        {gFollowerMonPic2617_TirtougaShinyPal, 0x1745},
        {gFollowerMonPic2618_CarracostaShinyPal, 0x1746},
        {gFollowerMonPic2619_ArchenShinyPal, 0x1747},
        {gFollowerMonPic2620_ArcheopsShinyPal, 0x1748},
        {gFollowerMonPic2621_TrubbishShinyPal, 0x1749},
        {gFollowerMonPic2622_GarbodorShinyPal, 0x174A},
        {gFollowerMonPic2623_ZoruaShinyPal, 0x174B},
        {gFollowerMonPic2624_ZoroarkShinyPal, 0x174C},
        {gFollowerMonPic2625_MinccinoShinyPal, 0x174D},
        {gFollowerMonPic2626_CinccinoShinyPal, 0x174E},
        {gFollowerMonPic2627_GothitaShinyPal, 0x174F},
        {gFollowerMonPic2628_GothoritaShinyPal, 0x1750},
        {gFollowerMonPic2629_GothitelleShinyPal, 0x1751},
        {gFollowerMonPic2630_SolosisShinyPal, 0x1752},
        {gFollowerMonPic2631_DuosionShinyPal, 0x1753},
        {gFollowerMonPic2632_ReuniclusShinyPal, 0x1754},
        {gFollowerMonPic2633_DucklettShinyPal, 0x1755},
        {gFollowerMonPic2634_SwannaShinyPal, 0x1756},
        {gFollowerMonPic2635_VanilliteShinyPal, 0x1757},
        {gFollowerMonPic2636_VanillishShinyPal, 0x1758},
        {gFollowerMonPic2637_VanilluxeShinyPal, 0x1759},
        {gFollowerMonPic2638_DeerlingShinyPal, 0x175A},
        {gFollowerMonPic2639_SawsbuckShinyPal, 0x175B},
        {gFollowerMonPic2640_EmolgaShinyPal, 0x175C},
        {gFollowerMonPic2641_KarrablastShinyPal, 0x175D},
        {gFollowerMonPic2642_EscavalierShinyPal, 0x175E},
        {gFollowerMonPic2643_FoongusShinyPal, 0x175F},
        {gFollowerMonPic2644_AmoongussShinyPal, 0x1760},
        {gFollowerMonPic2645_FrillishShinyPal, 0x1761},
        {gFollowerMonPic2646_JellicentShinyPal, 0x1762},
        {gFollowerMonPic2647_AlomomolaShinyPal, 0x1763},
        {gFollowerMonPic2648_JoltikShinyPal, 0x1764},
        {gFollowerMonPic2649_GalvantulaShinyPal, 0x1765},
        {gFollowerMonPic2650_FerroseedShinyPal, 0x1766},
        {gFollowerMonPic2651_FerrothornShinyPal, 0x1767},
        {gFollowerMonPic2652_KlinkShinyPal, 0x1768},
        {gFollowerMonPic2653_KlangShinyPal, 0x1769},
        {gFollowerMonPic2654_KlinklangShinyPal, 0x176A},
        {gFollowerMonPic2655_TynamoShinyPal, 0x176B},
        {gFollowerMonPic2656_EelektrikShinyPal, 0x176C},
        {gFollowerMonPic2657_EelektrossShinyPal, 0x176D},
        {gFollowerMonPic2658_ElgyemShinyPal, 0x176E},
        {gFollowerMonPic2659_BeheeyemShinyPal, 0x176F},
        {gFollowerMonPic2660_LitwickShinyPal, 0x1770},
        {gFollowerMonPic2661_LampentShinyPal, 0x1771},
        {gFollowerMonPic2662_ChandelureShinyPal, 0x1772},
        {gFollowerMonPic2663_AxewShinyPal, 0x1773},
        {gFollowerMonPic2664_FraxureShinyPal, 0x1774},
        {gFollowerMonPic2665_HaxorusShinyPal, 0x1775},
        {gFollowerMonPic2666_CubchooShinyPal, 0x1776},
        {gFollowerMonPic2667_BearticShinyPal, 0x1777},
        {gFollowerMonPic2668_CryogonalShinyPal, 0x1778},
        {gFollowerMonPic2669_ShelmetShinyPal, 0x1779},
        {gFollowerMonPic2670_AccelgorShinyPal, 0x177A},
        {gFollowerMonPic2671_StunfiskShinyPal, 0x177B},
        {gFollowerMonPic2672_MienfooShinyPal, 0x177C},
        {gFollowerMonPic2673_MienshaoShinyPal, 0x177D},
        {gFollowerMonPic2674_DruddigonShinyPal, 0x177E},
        {gFollowerMonPic2675_GolettShinyPal, 0x177F},
        {gFollowerMonPic2676_GolurkShinyPal, 0x1780},
        {gFollowerMonPic2677_PawniardShinyPal, 0x1781},
        {gFollowerMonPic2678_BisharpShinyPal, 0x1782},
        {gFollowerMonPic2679_BouffalantShinyPal, 0x1783},
        {gFollowerMonPic2680_RuffletShinyPal, 0x1784},
        {gFollowerMonPic2681_BraviaryShinyPal, 0x1785},
        {gFollowerMonPic2682_VullabyShinyPal, 0x1786},
        {gFollowerMonPic2683_MandibuzzShinyPal, 0x1787},
        {gFollowerMonPic2684_HeatmorShinyPal, 0x1788},
        {gFollowerMonPic2685_DurantShinyPal, 0x1789},
        {gFollowerMonPic2686_DeinoShinyPal, 0x178A},
        {gFollowerMonPic2687_ZweilousShinyPal, 0x178B},
        {gFollowerMonPic2688_HydreigonShinyPal, 0x178C},
        {gFollowerMonPic2689_LarvestaShinyPal, 0x178D},
        {gFollowerMonPic2690_VolcaronaShinyPal, 0x178E},
        {gFollowerMonPic2691_CobalionShinyPal, 0x178F},
        {gFollowerMonPic2692_TerrakionShinyPal, 0x1790},
        {gFollowerMonPic2693_VirizionShinyPal, 0x1791},
        {gFollowerMonPic2694_TornadusShinyPal, 0x1792},
        {gFollowerMonPic2695_ThundurusShinyPal, 0x1793},
        {gFollowerMonPic2696_ReshiramShinyPal, 0x1794},
        {gFollowerMonPic2697_ZekromShinyPal, 0x1795},
        {gFollowerMonPic2698_LandorusShinyPal, 0x1796},
        {gFollowerMonPic2699_KyuremShinyPal, 0x1797},
        {gFollowerMonPic2700_KeldeoShinyPal, 0x1798},
        {gFollowerMonPic2701_MeloettaShinyPal, 0x1799},
        {gFollowerMonPic2702_GenesectShinyPal, 0x179A},
		{gFollowerMonPic0465_BurmySandyPal, 0x179B},
		{gFollowerMonPic0465_BurmyTrashPal, 0x179C},
		{gFollowerMonPic0466_WormadamSandyPal, 0x179D},
		{gFollowerMonPic0466_WormadamTrashPal, 0x179E},
        {gFollowerMonPic2713_RotomHeatShinyPal, 0x179F},
        {gFollowerMonPic2714_RotomWashShinyPal, 0x17A0},
        {gFollowerMonPic2715_RotomFrostShinyPal, 0x17A1},
        {gFollowerMonPic2716_RotomFanShinyPal, 0x17A2},
        {gFollowerMonPic2717_RotomMowShinyPal, 0x17A3},
		{gFollowerMonPic0718_GiratinaOriginPal, 0x17A4},
		{gFollowerMonPic0719_ShayminSkyPal, 0x17A5},
        {gFollowerMonPic2721_ArceusFlyingShinyPal, 0x17A6},
        {gFollowerMonPic2722_ArceusPoisonShinyPal, 0x17A7},
        {gFollowerMonPic2723_ArceusGroundShinyPal, 0x17A8},
        {gFollowerMonPic2724_ArceusRockShinyPal, 0x17A9},
        {gFollowerMonPic2725_ArceusBugShinyPal, 0x17AA},
        {gFollowerMonPic2726_ArceusGhostShinyPal, 0x17AB},
        {gFollowerMonPic2727_ArceusSteelShinyPal, 0x17AC},
        {gFollowerMonPic2728_ArceusFireShinyPal, 0x17AD},
        {gFollowerMonPic2729_ArceusWaterShinyPal, 0x17AE},
        {gFollowerMonPic2730_ArceusGrassShinyPal, 0x17AF},
        {gFollowerMonPic2731_ArceusElectricShinyPal, 0x17B0},
        {gFollowerMonPic2732_ArceusPsychicShinyPal, 0x17B1},
        {gFollowerMonPic2733_ArceusIceShinyPal, 0x17B2},
        {gFollowerMonPic2734_ArceusDragonShinyPal, 0x17B3},
        {gFollowerMonPic2735_ArceusDarkShinyPal, 0x17B4},
	};

	const struct SpritePalette* const gObjectEventSpritePalettesSwitcher[255] =
	{
		[0x11] = gObjectEventSpritePalettes11,
		[0x12] = gObjectEventSpritePalettes12,
		[0x13] = gObjectEventSpritePalettes13,
		[0x14] = gObjectEventSpritePalettes14,
		[0x15] = gObjectEventSpritePalettes15,
		[0x16] = gObjectEventSpritePalettes16,
		[0x17] = gObjectEventSpritePalettes17,
	};
#endif

struct PlayerGraphics
{
	u16 graphicsId;
	u8 stateFlag;
};

static const struct PlayerGraphics sPlayerAvatarGfxIds[][2] =
{
	[PLAYER_AVATAR_STATE_NORMAL] =     {{EVENT_OBJ_GFX_RED_NORMAL, PLAYER_AVATAR_FLAG_ON_FOOT},          {EVENT_OBJ_GFX_LEAF_NORMAL, PLAYER_AVATAR_FLAG_ON_FOOT}},
	[PLAYER_AVATAR_STATE_BIKE] =       {{EVENT_OBJ_GFX_RED_BIKE, PLAYER_AVATAR_FLAG_BIKE},               {EVENT_OBJ_GFX_LEAF_BIKE, PLAYER_AVATAR_FLAG_BIKE}},
	[PLAYER_AVATAR_STATE_SURFING] =    {{EVENT_OBJ_GFX_RED_SURFING, PLAYER_AVATAR_FLAG_SURFING},         {EVENT_OBJ_GFX_LEAF_SURFING, PLAYER_AVATAR_FLAG_SURFING}},
	[PLAYER_AVATAR_STATE_FIELD_MOVE] = {{EVENT_OBJ_GFX_RED_FIELD_MOVE, PLAYER_AVATAR_FLAG_FIELD_MOVE},   {EVENT_OBJ_GFX_LEAF_FIELD_MOVE, PLAYER_AVATAR_FLAG_FIELD_MOVE}},
	[PLAYER_AVATAR_STATE_FISHING] =    {{EVENT_OBJ_GFX_RED_FISHING, 0},                                  {EVENT_OBJ_GFX_LEAF_FISHING, 0}},
	[PLAYER_AVATAR_STATE_VS_SEEKER] =  {{EVENT_OBJ_GFX_RED_VS_SEEKER, 0},                                {EVENT_OBJ_GFX_LEAF_VS_SEEKER, 0}},
	[PLAYER_AVATAR_STATE_UNDERWATER] = {{EVENT_OBJ_GFX_RED_UNDERWATER, PLAYER_AVATAR_FLAG_UNDERWATER},   {EVENT_OBJ_GFX_LEAF_UNDERWATER, PLAYER_AVATAR_FLAG_UNDERWATER}},
};

//npc_get_type hack for character customization
//hook at 0805F2C8 via r1
NPCPtr GetEventObjectGraphicsInfo(u16 graphicsId)
{
	u16 newId;
	u8 tableId = (graphicsId >> 8) & 0xFF;	// upper byte
	u8 spriteId = graphicsId & 0xFF;		// lower byte

	//Check runtime changeable OWs
	if (tableId == 0xFF && spriteId <= 0xF)
	{
		//Runtime changeable
		newId = VarGet(VAR_RUNTIME_CHANGEABLE + spriteId);
		tableId = (newId >> 8) & 0xFF;	// upper byte
		spriteId = (newId & 0xFF);		// lower byte
	}
	else
	{
		switch (spriteId) {
			case EVENT_OBJ_GFX_RED_BIKE_VS_SEEKER:
			case EVENT_OBJ_GFX_LEAF_BIKE_VS_SEEKER:
				if (tableId == 0) //Actually the Vs. Seeker sprites
				{
					newId = VarGet(VAR_PLAYER_VS_SEEKER_ON_BIKE);
					if (newId != 0) //Actually set to something different
					{
						tableId = (newId >> 8) & 0xFF;	// upper byte
						spriteId = (newId & 0xFF);		// lower byte
					}
				}
				break;
		}

		#ifndef UNBOUND
		if (spriteId > 239 && tableId == 0)
		{
			newId = VarGetEventObjectGraphicsId(spriteId + 16);
			tableId = (newId >> 8) & 0xFF;	// upper byte
			spriteId = (newId & 0xFF);		// lower byte
		}
		#endif
	}

	NPCPtr spriteAddr;
	#ifndef EXISTING_OW_TABLE_ADDRESS
	if (tableId >= NELEMS(gOverworldTableSwitcher)
	|| gOverworldTableSwitcher[tableId] == 0)
		spriteAddr = gOverworldTableSwitcher[0][spriteId];
	else
	#endif
		spriteAddr = gOverworldTableSwitcher[tableId][spriteId];

	if (spriteAddr == NULL)
		spriteAddr = gOverworldTableSwitcher[0][EVENT_OBJ_GFX_LITTLE_BOY];	// first non-player sprite in first table default

	return spriteAddr;
};

NPCPtr GetEventObjectGraphicsInfoByEventObj(struct EventObject* eventObj)
{
	return GetEventObjectGraphicsInfo(GetEventObjectGraphicsId(eventObj));
}

static u16 GetCustomGraphicsIdByState(u8 state)
{
	u16 gfxId = 0;

	switch (state) {
		case PLAYER_AVATAR_STATE_NORMAL:
			gfxId = VarGet(VAR_PLAYER_WALKRUN);
			break;
		case PLAYER_AVATAR_STATE_BIKE:
			gfxId = VarGet(VAR_PLAYER_BIKING);
			break;
		case PLAYER_AVATAR_STATE_SURFING:
			gfxId = VarGet(VAR_PLAYER_SURFING);
			break;
		case PLAYER_AVATAR_STATE_FIELD_MOVE: //HM Use
			gfxId = VarGet(VAR_PLAYER_HM_USE);
			break;
		case PLAYER_AVATAR_STATE_VS_SEEKER:
			gfxId = VarGet(VAR_PLAYER_VS_SEEKER);
			break;
		case PLAYER_AVATAR_STATE_FISHING:
			gfxId = VarGet(VAR_PLAYER_FISHING);
			break;
		case PLAYER_AVATAR_STATE_UNDERWATER:
			gfxId = VarGet(VAR_PLAYER_UNDERWATER);
			break;
	}

	return gfxId;
}

u16 GetPlayerAvatarGraphicsIdByStateIdAndGender(u8 state, u8 gender)
{
	u16 graphicsId = GetCustomGraphicsIdByState(state);
	if (graphicsId != 0)
		return graphicsId;

	return sPlayerAvatarGfxIds[state][gender].graphicsId;
}

u16 GetPlayerAvatarGraphicsIdByStateId(u8 state)
{
	return GetPlayerAvatarGraphicsIdByStateIdAndGender(state, gPlayerAvatar->gender);
}

u8 GetPlayerAvatarStateTransitionByGraphicsId(u16 graphicsId, u8 gender)
{
    for (u8 state = 0; state < NELEMS(sPlayerAvatarGfxIds); ++state)
    {
		u16 customGraphicsId = GetCustomGraphicsIdByState(state);
		if (customGraphicsId == graphicsId)
			graphicsId = sPlayerAvatarGfxIds[state][gender].graphicsId;

        if (sPlayerAvatarGfxIds[state][gender].graphicsId == graphicsId)
            return sPlayerAvatarGfxIds[state][gender].stateFlag;
    }

    return PLAYER_AVATAR_FLAG_ON_FOOT;
}

u16 GetPlayerAvatarGraphicsIdByCurrentState(void)
{
	u8 state = 0;
	u8 gender = gPlayerAvatar->gender;
    u8 flags = gPlayerAvatar->flags;

    for (; state < NELEMS(sPlayerAvatarGfxIds); ++state)
    {
        if (sPlayerAvatarGfxIds[state][gender].stateFlag & flags)
		{
			u16 graphicsId = sPlayerAvatarGfxIds[state][gender].graphicsId;
			u16 customGraphicsId = GetCustomGraphicsIdByState(state);
			if (customGraphicsId != 0)
				graphicsId = customGraphicsId;

			return graphicsId;
		}
    }

    return sPlayerAvatarGfxIds[0][0].graphicsId;
}

u8 GetPlayerAvatarGenderByGraphicsId(u8 gfxId)
{
    for (u8 state = 0; state < NELEMS(sPlayerAvatarGfxIds); ++state)
    {
		for (u8 gender = 0; gender < NELEMS(sPlayerAvatarGfxIds[0]); ++gender)
		{
			if (sPlayerAvatarGfxIds[state][gender].graphicsId == gfxId)
				return gender;

			u16 customGraphicsId = GetCustomGraphicsIdByState(state);
			if (customGraphicsId != 0 && customGraphicsId == gfxId)
				return gSaveBlock2->playerGender;
		}
	}

	return MALE;
}

static void SetPlayerAvatarExtraStateTransition(u16 graphicsId, u8 b)
{
    u8 unk = GetPlayerAvatarStateTransitionByGraphicsId(graphicsId, gPlayerAvatar->gender);
	SetPlayerAvatarTransitionFlags(unk | b);
}

u16 GetEventObjectGraphicsId(struct EventObject* eventObj)
{
	u8 lowerByte = eventObj->graphicsIdLowerByte;
	u8 upperByte = eventObj->graphicsIdUpperByte;

	#ifndef EXISTING_OW_TABLE_ADDRESS
	if (upperByte >= NELEMS(gOverworldTableSwitcher)
	&& upperByte != 0xFF) //Dynamic OW table
		return lowerByte;
	#endif

	if (upperByte == 0xFF && lowerByte <= 0xF)
		return VarGet(VAR_RUNTIME_CHANGEABLE + lowerByte); //Runtime changeable

	return lowerByte | (upperByte << 8);
}

void SetPlayerAvatarEventObjectIdAndObjectId(u8 eventObjectId, u8 spriteId)
{
    gPlayerAvatar->eventObjectId = eventObjectId;
    gPlayerAvatar->spriteId = spriteId;
    gPlayerAvatar->gender = GetPlayerAvatarGenderByGraphicsId(GetEventObjectGraphicsId(&gEventObjects[eventObjectId]));
    SetPlayerAvatarExtraStateTransition(GetEventObjectGraphicsId(&gEventObjects[eventObjectId]), 0x20);
}

static u8 GetColorFromTextColorTableNew(u16 gfxId)
{
	#ifdef UNBOUND
	u8 gender = GetEventObjectGraphicsInfo(gfxId)->gender;
	return gender == MALE ? 0 : gender == FEMALE ? 1 : 2; //Blue, Red, Black
	#else
	return GetColorFromTextColorTable(gfxId);
	#endif
}

u8 ContextNpcGetTextColor(void)
{
	u16 gfxId;

	if (gSpecialVar_TextColor != 0xFF)
	{
		return gSpecialVar_TextColor;
	}
	else if (gSelectedEventObject == 0)
	{
		return 3;
	}
	else
	{
		gfxId = GetEventObjectGraphicsId(&gEventObjects[gSelectedEventObject]);

		#ifndef UNBOUND
		if (gfxId >= EVENT_OBJ_GFX_VAR_0 && gfxId <= 0xFF) //Vanilla dynamic id
			gfxId = VarGetEventObjectGraphicsId(gfxId - EVENT_OBJ_GFX_VAR_0);
		#endif

		return GetColorFromTextColorTableNew(gfxId);
	}
}

// load trainer card sprite based on variables
// 	hook at 810c374 via r2
u8 PlayerGenderToFrontTrainerPicId(u8 gender, bool8 modify)
{
	if (modify != TRUE)
		return gender;

	u16 trainerId = VarGet(VAR_TRAINERCARD_MALE + gender);
	if (trainerId == 0)
		trainerId = TRAINER_PIC_PLAYER_M + gender;

	return trainerId;
};

void InitPlayerAvatar(s16 x, s16 y, u8 direction, u8 gender)
{
	u8 eventObjectId;
	struct EventObject* eventObject;
	struct EventObjectTemplate playerEventObjTemplate = {0};
	u16 graphicsId = GetPlayerAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_NORMAL, gender);

	playerEventObjTemplate.localId = EVENT_OBJ_ID_PLAYER;
	playerEventObjTemplate.graphicsIdLowerByte = graphicsId & 0xFF;
	playerEventObjTemplate.graphicsIdUpperByte = graphicsId >> 8;
	playerEventObjTemplate.x = x - 7;
	playerEventObjTemplate.y = y - 7;
	playerEventObjTemplate.movementType = MOVEMENT_TYPE_PLAYER;

	eventObjectId = SpawnSpecialEventObject(&playerEventObjTemplate);
	eventObject = &gEventObjects[eventObjectId];
	eventObject->isPlayer = 1;
	eventObject->warpArrowSpriteId = CreateWarpArrowSprite();
	EventObjectTurn(eventObject, direction);
	ClearPlayerAvatarInfo();

	gPlayerAvatar->runningState = NOT_MOVING;
	gPlayerAvatar->tileTransitionState = T_NOT_MOVING;
	gPlayerAvatar->eventObjectId = eventObjectId;
	gPlayerAvatar->spriteId = eventObject->spriteId;
	gPlayerAvatar->gender = gender;
	SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_FIELD_MOVE | PLAYER_AVATAR_FLAG_ON_FOOT);
	CreateFollowerAvatar();
}

void PlayerHandleDrawTrainerPic(void)
{
	s16 xPos, yPos;
	u32 trainerPicId = GetBackspriteId();

	if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
	{
		if ((GetBattlerPosition(gActiveBattler) & BIT_FLANK) != B_FLANK_LEFT) // Second mon, on the right.
			xPos = 90;
		else // First mon, on the left.
			xPos = 32;

		yPos = (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80;
	}

	else
	{
		xPos = 80;
		yPos = (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80;
	}

	LoadTrainerBackPal(trainerPicId, gActiveBattler);
	SetMultiuseSpriteTemplateToTrainerBack(trainerPicId, GetBattlerPosition(gActiveBattler));
	gBattlerSpriteIds[gActiveBattler] = CreateSprite(&gMultiuseSpriteTemplate[0], xPos, yPos, GetBattlerSpriteSubpriority(gActiveBattler));

	if (IS_DOUBLE_BATTLE)
		gSprites[gBattlerSpriteIds[gActiveBattler]].oam.priority = 0; //So it appears above enemy healthbars

	gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = gActiveBattler;
	gSprites[gBattlerSpriteIds[gActiveBattler]].pos2.x = 240;
	gSprites[gBattlerSpriteIds[gActiveBattler]].data[0] = -3; //-2; //Speed scrolling in
	gSprites[gBattlerSpriteIds[gActiveBattler]].callback = SpriteCB_TrainerSlideIn; //sub_805D7AC in Emerald

	gBattlerControllerFuncs[gActiveBattler] = Player_CompleteOnBattlerSpriteCallbackDummy;
}

void PlayerHandleTrainerSlide(void)
{
	u32 trainerPicId = GetBackspriteId();

	LoadTrainerBackPal(trainerPicId, gActiveBattler);
	SetMultiuseSpriteTemplateToTrainerBack(trainerPicId, GetBattlerPosition(gActiveBattler));
	gBattlerSpriteIds[gActiveBattler] = CreateSprite(&gMultiuseSpriteTemplate[0], 80, (8 - gTrainerBackPicCoords[trainerPicId].coords) * 4 + 80, 30);

	if (IS_DOUBLE_BATTLE)
		gSprites[gBattlerSpriteIds[gActiveBattler]].oam.priority = 0;

	gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = gActiveBattler;
	gSprites[gBattlerSpriteIds[gActiveBattler]].pos2.x = -96;
	gSprites[gBattlerSpriteIds[gActiveBattler]].data[0] = 2;
	gSprites[gBattlerSpriteIds[gActiveBattler]].callback = SpriteCB_TrainerSlideIn;

	gBattlerControllerFuncs[gActiveBattler] = Player_CompleteOnBattlerSpriteCallbackDummy2;
}

u16 GetBackspriteId(void)
{
	u16 trainerPicId;

	if (gBattleTypeFlags & BATTLE_TYPE_LINK)
	{
		if ((gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_FIRE_RED
		|| (gLinkPlayers[GetMultiplayerId()].version & 0xFF) == VERSION_LEAF_GREEN)
			trainerPicId = gLinkPlayers[GetMultiplayerId()].gender;
		else
			trainerPicId = gLinkPlayers[GetMultiplayerId()].gender + BACK_PIC_BRENDAN;
	}
	else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gActiveBattler == 2)
	{
		trainerPicId = LoadPartnerBackspriteIndex();
	}
	else if (IsAIControlledBattle())
	{
		trainerPicId = LoadPartnerBackspriteIndex(); //The trainer's backsprite for the Battle Sands is stored in the multi partner var
	}
	else
	{
		if (VarGet(VAR_BACKSPRITE_SWITCH))
			trainerPicId = VarGet(VAR_BACKSPRITE_SWITCH);
		else
			trainerPicId = gSaveBlock2->playerGender;
	}

	return trainerPicId;
}

#ifdef UNBOUND
bool8 IsPaletteTagAffectedByCharacterCustomization(u16 tag)
{
	switch (tag)
	{
		case EVENT_OBJ_PAL_TAG_DEFAULT:
		case EVENT_OBJ_PAL_TAG_MOM:
		case EVENT_OBJ_PAL_TAG_AROS:
		case EVENT_OBJ_PAL_TAG_RED_PLAYER:
		case EVENT_OBJ_PAL_TAG_LEAF_PLAYER:
		case EVENT_OBJ_PAL_TAG_ETHAN_PLAYER:
		case EVENT_OBJ_PAL_TAG_LYRA_PLAYER:
		case EVENT_OBJ_PAL_TAG_LUCAS_PLAYER:
		case EVENT_OBJ_PAL_TAG_DAWN_PLAYER:
		case EVENT_OBJ_PAL_TAG_SHADOW_GRUNT_PLAYER:
		case EVENT_OBJ_PAL_TAG_MARLON_PLAYER:
		case EVENT_OBJ_PAL_TAG_PLAYER_CHAMPION:
			return TRUE;
		default:
			return FALSE;
	}
}

static bool8 IsPaletteTagAffectedBySkinCharacterCustomization(unusedArg u16 tag)
{
	return tag != EVENT_OBJ_PAL_TAG_MARLON_PLAYER;
}

static bool8 IsPaletteTagAffectedByHairCharacterCustomization(u16 tag)
{
	return tag != EVENT_OBJ_PAL_TAG_AROS
		&& tag != EVENT_OBJ_PAL_TAG_MARLON_PLAYER;
}

static u8 GetOutfitStyleByEventObjTag(u16 tag)
{
	switch (tag)
	{
		case EVENT_OBJ_PAL_TAG_DEFAULT:
			return OUTFIT_STYLE_DEFAULT;
		case EVENT_OBJ_PAL_TAG_PLAYER_CHAMPION:
			return OUTFIT_STYLE_CHAMPION;
		case EVENT_OBJ_PAL_TAG_MARLON_PLAYER:
			return OUTFIT_STYLE_MARLON;
		default:
			return OUTFIT_STYLE_NONE;
	}
}

#define SKIN_TONE_OFFSET 1
#define HAIR_COLOUR_OFFSET 4
#define OUTFIT_OFFSET 7
#define DEFAULT_TRIM_OFFSET (OUTFIT_OFFSET + 2)
static void ChangePlayerPaletteByPaletteAndOffset(u16 paletteOffset, bool8 changeSkin, bool8 changeHair, u8 outfitStyle)
{
	u16 skinTone = VarGet(VAR_PLAYER_SKIN_TONE);
	u16 hairColour = VarGet(VAR_PLAYER_HAIR_COLOUR);

	if (changeSkin && skinTone > 0 && skinTone < NELEMS(sPlayerSkinColours))
	{
		u16 skinOffset = paletteOffset + SKIN_TONE_OFFSET;
		CpuCopy16(sPlayerSkinColours[skinTone] + SKIN_TONE_OFFSET, gPlttBufferUnfaded + skinOffset, 3 * sizeof(u16));
		CpuCopy16(sPlayerSkinColours[skinTone] + SKIN_TONE_OFFSET, gPlttBufferFaded + skinOffset, 3 * sizeof(u16));
	}

	if (changeHair && hairColour > 0 && hairColour < NELEMS(sPlayerHairColours))
	{
		u16 hairOffset = paletteOffset + HAIR_COLOUR_OFFSET;
		CpuCopy16(sPlayerHairColours[hairColour] + HAIR_COLOUR_OFFSET, gPlttBufferUnfaded + hairOffset, 3 * sizeof(u16));
		CpuCopy16(sPlayerHairColours[hairColour] + HAIR_COLOUR_OFFSET, gPlttBufferFaded + hairOffset, 3 * sizeof(u16));
	}

	if (outfitStyle != OUTFIT_STYLE_NONE)
	{
		const u16* const* outfitPals;
		const u16* const* trimPals;
		u16 outfitColour, trimColour;
		u32 outfitPalCount, trimPalCount, copyAmount;
		trimColour = 0;

		if (outfitStyle == OUTFIT_STYLE_CHAMPION)
		{
			outfitColour = VarGet(VAR_PLAYER_CHAMPION_OUTFIT_COLOUR);
			trimColour = VarGet(VAR_PLAYER_CHAMPION_TRIM_COLOUR);
			outfitPals = sPlayerChampionOutfitColours;
			outfitPalCount = NELEMS(sPlayerChampionOutfitColours);
			trimPals = sPlayerChampionTrimColours;
			trimPalCount = NELEMS(sPlayerChampionTrimColours);
			copyAmount = 3;
		}
		else if (outfitStyle == OUTFIT_STYLE_MARLON)
		{
			outfitColour = VarGet(VAR_PLAYER_MARLON_OUTFIT_COLOUR);
			outfitPals = sPlayerMarlonOutfitColours;
			outfitPalCount = NELEMS(sPlayerMarlonOutfitColours);
			copyAmount = 3;
		}
		else
		{
			//Default outfit
			outfitColour = VarGet(VAR_PLAYER_OUTFIT_COLOUR);
			trimColour = VarGet(VAR_PLAYER_TRIM_COLOUR);
			outfitPals = sPlayerOutfitColours;
			outfitPalCount = NELEMS(sPlayerOutfitColours);
			trimPals = sPlayerTrimColours;
			trimPalCount = NELEMS(sPlayerTrimColours);
			copyAmount = 2;
		}

		if (outfitColour > 0 && outfitColour < outfitPalCount)
		{
			u16 outfitOffset = paletteOffset + OUTFIT_OFFSET;
			CpuCopy16(outfitPals[outfitColour] + OUTFIT_OFFSET, gPlttBufferUnfaded + outfitOffset, copyAmount * sizeof(u16));
			CpuCopy16(outfitPals[outfitColour] + OUTFIT_OFFSET, gPlttBufferFaded + outfitOffset, copyAmount * sizeof(u16));
		}

		if (trimColour > 0 && trimColour < trimPalCount)
		{
			u8 baseTrimOffset = OUTFIT_OFFSET + copyAmount;
			u16 trimOffset = paletteOffset + baseTrimOffset;
			CpuCopy16(trimPals[trimColour] + baseTrimOffset, gPlttBufferUnfaded + trimOffset, 2 * sizeof(u16));
			CpuCopy16(trimPals[trimColour] + baseTrimOffset, gPlttBufferFaded + trimOffset, 2 * sizeof(u16));
		}
	}
}
#endif

void ChangeEventObjPal(unusedArg u16 paletteOffset, unusedArg u16 palTag)
{
	#ifdef UNBOUND
	ChangePlayerPaletteByPaletteAndOffset(paletteOffset, IsPaletteTagAffectedBySkinCharacterCustomization(palTag),
	                                                     IsPaletteTagAffectedByHairCharacterCustomization(palTag),
	                                                     GetOutfitStyleByEventObjTag(palTag));
	#endif
}

void ChangeTrainerPicPal(unusedArg u16 paletteOffset, unusedArg u8 outfitStyle)
{
	#ifdef UNBOUND
	if (outfitStyle == OUTFIT_STYLE_MARLON)
		ChangePlayerPaletteByPaletteAndOffset(paletteOffset, FALSE, FALSE, outfitStyle); //Just outfit, no skin and hair
	else
		ChangePlayerPaletteByPaletteAndOffset(paletteOffset, TRUE, TRUE, outfitStyle);
	#endif
}

void ChangeTrainerBackPal(unusedArg u16 backPicId, unusedArg u8 palSot)
{
	#ifdef UNBOUND
	//Dynamically changes the palette of the player character in Unbound
	switch (backPicId)
	{
		case TRAINER_BACK_PIC_RED: //Player M
		case TRAINER_BACK_PIC_LEAF: //Player F
			ChangeTrainerPicPal(0x100 + palSot * 16, OUTFIT_STYLE_DEFAULT); //All colours
			break;
		case TRAINER_BACK_PIC_PLAYER_CHAMPION_M:
		case TRAINER_BACK_PIC_PLAYER_CHAMPION_F:
			ChangeTrainerPicPal(0x100 + palSot * 16, OUTFIT_STYLE_CHAMPION); //All colours
			break;
		case TRAINER_BACK_PIC_MARLON_PLAYER_M:
		case TRAINER_BACK_PIC_MARLON_PLAYER_F:
		case TRAINER_BACK_PIC_IVORY_PLAYER_M:
		case TRAINER_BACK_PIC_IVORY_PLAYER_F:
			ChangePlayerPaletteByPaletteAndOffset(0x100 + palSot * 16, TRUE, FALSE, OUTFIT_STYLE_MARLON); //Just skin and outfit - no hair
			break;
		case TRAINER_BACK_PIC_RED_PLAYER:
		case TRAINER_BACK_PIC_LEAF_PLAYER:
		case TRAINER_BACK_PIC_ETHAN_PLAYER:
		case TRAINER_BACK_PIC_LYRA_PLAYER:
		case TRAINER_BACK_PIC_LUCAS_PLAYER:
		case TRAINER_BACK_PIC_DAWN_PLAYER:
			ChangePlayerPaletteByPaletteAndOffset(0x100 + palSot * 16, TRUE, TRUE, OUTFIT_STYLE_NONE); //Just skin & hair
			break;
	}
	#endif
}

void LoadTrainerBackPal(u16 backPicId, u8 battlerId)
{
	DecompressTrainerBackPalette(backPicId, battlerId);
	ChangeTrainerBackPal(backPicId, battlerId);
}

const u8* GetTrainerSpritePal(u16 trainerPicId)
{
	return gTrainerFrontPicPaletteTable[trainerPicId].data;
}

#ifdef UNBOUND
static bool8 IsTrainerPicAffectedByCustomization(u16 trainerPicId)
{
	return trainerPicId == TRAINER_PIC_PLAYER_M
		|| trainerPicId == TRAINER_PIC_PLAYER_F
		|| trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_M
		|| trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_F
		|| trainerPicId == TRAINER_PIC_PLAYER_MARLON_M
		|| trainerPicId == TRAINER_PIC_PLAYER_MARLON_F
		|| trainerPicId == TRAINER_PIC_PLAYER_RED
		|| trainerPicId == TRAINER_PIC_PLAYER_LEAF
		|| trainerPicId == TRAINER_PIC_PLAYER_ETHAN
		|| trainerPicId == TRAINER_PIC_PLAYER_LYRA;
}

u8 GetOutfitStyleByTrainerPic(u16 trainerPicId)
{
	if (trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_M
	|| trainerPicId == TRAINER_PIC_PLAYER_CHAMPION_F)
	{
		return OUTFIT_STYLE_CHAMPION;
	}
	else if (trainerPicId == TRAINER_PIC_PLAYER_M
		|| trainerPicId == TRAINER_PIC_PLAYER_F)
	{
		return OUTFIT_STYLE_DEFAULT;
	}
	else if (trainerPicId == TRAINER_PIC_PLAYER_MARLON_M
	|| trainerPicId == TRAINER_PIC_PLAYER_MARLON_F)
	{
		return OUTFIT_STYLE_MARLON;
	}

	return OUTFIT_STYLE_NONE;
}
#endif

void TryUpdateTrainerPicPalTrainerCard(u16 trainerPicId, u16 palOffset)
{
	LoadCompressedPalette(GetTrainerSpritePal(trainerPicId), palOffset * 16, 0x20);
	#ifdef UNBOUND
	if (IsTrainerPicAffectedByCustomization(trainerPicId))
	{
		u32 offset = palOffset * 16;
		ChangeTrainerPicPal(offset, GetOutfitStyleByTrainerPic(trainerPicId));
	}
	#endif
}

u16 CreateTrainerPicSprite(u16 species, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag)
{
    u16 spriteId = CreatePicSprite_HandleDeoxys(species, 0, 0, isFrontPic, x, y, paletteSlot, paletteTag, TRUE);
	#ifdef UNBOUND
	if (isFrontPic && IsTrainerPicAffectedByCustomization(species))
	{
		u32 offset = 0x100 + gSprites[spriteId].oam.paletteNum * 16;
		ChangeTrainerPicPal(offset, GetOutfitStyleByTrainerPic(species));
	}
	#endif
	return spriteId;
}

void TryModifyMugshotTrainerPicPal(unusedArg u16 trainerPicId, unusedArg u8 index)
{
	#ifdef UNBOUND
	if (IsTrainerPicAffectedByCustomization(trainerPicId)) //Is player sprite
	{
		if (index != 0xFF)
		{
			u32 offset = 0x100 + index * 16;
			ChangeTrainerPicPal(offset, GetOutfitStyleByTrainerPic(trainerPicId));
		}
	}
	#endif
}

void TryUpdateRegionMapIconPal(void)
{
	#ifdef UNBOUND
	u8 paletteSlot = IndexOfSpritePaletteTag(1);
	if (paletteSlot != 0xFF)
		ChangeEventObjPal(0x100 + paletteSlot * 16, EVENT_OBJ_PAL_TAG_DEFAULT);
	#endif
}
