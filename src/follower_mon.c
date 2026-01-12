#include "defines.h"
#include "../include/follower_mon.h"
#include "../include/follower_mon_sprites.h"
#include "../include/pokemon.h"
#include "../include/new/follow_me.h"
#include "../include/global.fieldmap.h"
#include "../include/event_object_movement.h"
#include "../include/script_menu.h"
#include "../include/new_menu_helpers.h"
#include "../include/script.h"
#include "../include/follower_mon_pal.h"


extern u8 SparkleTiles[];
extern u16 SparklePal[];

static void SpriteCB_Sparkle(struct Sprite *sprite);

static const struct OamData sSparkleOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = ST_OAM_SIZE_2,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSparkleAnim0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_FRAME(80, 5),
    ANIMCMD_END,
};

static const union AffineAnimCmd sSparkleAffineAnim0[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(4, 4, 8, 30),
    AFFINEANIMCMD_END,
};

static const union AnimCmd *const sSparkleAnimTable[] =
{
    sSparkleAnim0,
};

static const union AffineAnimCmd *const sSparkleAffineAnimTable[] =
{
    sSparkleAffineAnim0,
};

static struct SpriteSheet sSparkleTileData =
{
    .data = SparkleTiles,
    .size = (192 * 32) / 2,
    .tag = 12,
};

static struct SpritePalette sSparklePalData =
{
    .data = SparklePal,
    .tag = 12,
};

static struct SpriteTemplate sSparkleTemplate =
{
    .tileTag = 12,
    .paletteTag = 12,
    .oam = &sSparkleOamData,
    .anims = sSparkleAnimTable,
    .images = NULL,
    .affineAnims = sSparkleAffineAnimTable,
    .callback = SpriteCB_Sparkle,
};

static void SpriteCB_Sparkle(struct Sprite *sprite)
{
    if (sprite->data[0] == 30)
        DestroySprite(sprite);
    else
        sprite->data[0]++;
}

void CreateSparkleSprite(void)
{
    if (FlagGet(FLAG_FOLLOWER_POKEMON) && gFollowerState.inProgress)
    {
        struct Sprite *followerSprite = &gSprites[gEventObjects[gFollowerState.objId].spriteId];
        s16 posX = followerSprite->pos1.x - 16;
        s16 posY = followerSprite->pos1.y - 10;
        u8 spriteId;

        LoadSpriteSheet(&sSparkleTileData);
        LoadSpritePalette(&sSparklePalData);
        spriteId = CreateSprite(&sSparkleTemplate, posX, posY, 0);

        gSprites[spriteId].data[0] = 0;
        gSprites[spriteId].centerToCornerVecX = 0;
        gSprites[spriteId].centerToCornerVecY = 0;
        gSprites[spriteId].coordOffsetEnabled = TRUE;
    }
}

u16 GetFollowerMonSprite(void)
{
    u8 slotId = 7;
    u16 species;

    for (u8 i = 0; i < gPlayerPartyCount; ++i)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL)
         && GetMonData(&gPlayerParty[i], MON_DATA_HP, NULL) > 0)
        {
            slotId = i;
            break;
        }
    }

    if (slotId == 7)
        return 0;

    struct Pokemon* mon = &gPlayerParty[slotId];
    species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    return gFollowerMonSpriteIdTable[species];
}

void CreateFollowerMonObject(void)
{
    u16 sprite = GetFollowerMonSprite();
    if (sprite == 0)  // If there is no valid Pokémon, do not create the follower
        return;
    struct EventObject *playerObj = &gEventObjects[gPlayerAvatar->eventObjectId];
 
         s16 posX = playerObj->currentCoords.x - 7;
         s16 posY = playerObj->currentCoords.y - 7;
     
         // Adjusts follower position based on player direction
         switch (playerObj->facingDirection)
    {
        case DIR_SOUTH: posY -= 1; break;
         case DIR_NORTH: posY += 1; break;
         case DIR_WEST:  posX += 1; break;
         case DIR_EAST:  posX -= 1; break;
     }
 
     // Check if follower already exists before creating a new one
     for (u8 i = 0; i < MAP_OBJECTS_COUNT; i++)
     {
         if (gEventObjects[i].localId == 30 && gEventObjects[i].active)
             return;  // There is already a follower, so don't create another one
    }

    struct EventObjectTemplate followerObj =
    {
        .localId = 30,
        .graphicsIdLowerByte = sprite & 0xFF,
        .graphicsIdUpperByte = sprite >> 8,
        .x = posX,
        .y = posY,
        .elevation = 3,
        .movementType = 1,
        .movementRangeX = 0,
        .movementRangeY = 0,
        .trainerType = 0,
        .trainerRange_berryTreeId = 0,
    };

    SpawnSpecialEventObject(&followerObj);
}

void FollowerMonFacePlayer(void)
{
    u8 dir;

    switch (gEventObjects[gPlayerAvatar->eventObjectId].facingDirection)
    {
        case DIR_SOUTH:
            dir = DIR_NORTH;
            break;
        case DIR_NORTH:
            dir = DIR_SOUTH;
            break;
        case DIR_WEST:
            dir = DIR_EAST;
            break;
        case DIR_EAST:
            dir = DIR_WEST;
            break;
        case DIR_SOUTHWEST:
            dir = DIR_SOUTHEAST;
            break;
        case DIR_SOUTHEAST:
            dir = DIR_SOUTHWEST;
            break;
        case DIR_NORTHWEST:
            dir = DIR_NORTHEAST;
            break;
        case DIR_NORTHEAST:
            dir = DIR_NORTHWEST;
            break;
        default:
            dir = DIR_NORTH;
            break;
    }

    EventObjectTurn(&gEventObjects[gFollowerState.objId], dir);
}

void TurnFollowerMonToPlayer(void)
{
    u8 dir = gEventObjects[gPlayerAvatar->eventObjectId].facingDirection;
    EventObjectTurn(&gEventObjects[gFollowerState.objId], dir);
}

void ShowFollowerMon(void)
{
    if (FlagGet(FLAG_FOLLOWER_POKEMON) && gFollowerState.inProgress)
        gEventObjects[gFollowerState.objId].invisible = FALSE;
}
extern void Task_ScriptShowMonPic(u8 taskId);
#define gMonPaletteTable (*((struct CompressedSpritePalette**) 0x8000130))
#define gMonShinyPaletteTable (*((struct CompressedSpritePalette**) 0x8000134))

struct CompressedSpritePalette * GetSpritePalToUse(bool8 isShiny)
{
    if(isShiny)
        return gMonShinyPaletteTable;
    else
        return gMonPaletteTable;
}

u8 CreateMonSprite_MysteryGift(u16 species, s16 x, s16 y)
{
    struct Pokemon* mon = &gPlayerParty[0];
    u32 personality = 0xFFFFFFFF;
    u32 otId = T1_READ_32(gSaveBlock2->playerTrainerId);
    u16 isShiny = IsMonShiny(mon);
    const struct CompressedSpritePalette * spritePal = GetSpritePalToUse(isShiny);
    u16 spriteId = CreateMonPicSprite_HandleDeoxys(species, otId, personality, 1, x, y, 0, spritePal[species].tag);
    LoadCompressedSpritePalette(&spritePal[species]);
    if(spriteId != 0xFFFF)
    {
        gSprites[spriteId].oam.paletteNum = IndexOfSpritePaletteTag(spritePal[species].tag);
    }
    if (spriteId == 0xFFFF)
        return MAX_SPRITES;
    else
        return spriteId;
}

bool8 ScriptMenu_ShowMysteryPokemonPic(u16 species, u8 x, u8 y)
{
    u8 spriteId;
    u8 taskId;
    if (FindTaskIdByFunc(Task_ScriptShowMonPic) != 0xFF)
        return FALSE;
    spriteId = CreateMonSprite_MysteryGift(species, 8 * x + 40, 8 * y + 40);
    taskId = CreateTask(Task_ScriptShowMonPic, 80);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = species;
    gTasks[taskId].data[2] = spriteId;
    gSprites[spriteId].callback = SpriteCallbackDummy;
    gSprites[spriteId].oam.priority = 0;
    SetStandardWindowBorderStyle(gTasks[taskId].data[5], TRUE);
    ScheduleBgCopyTilemapToVram(0);
    return TRUE;
}

bool8 ShowMysteryGiftMon()
{
    u16 species = VarGet(0x4004);
    u8 x = 0x1A;
    u8 y = 0x2;

    ScriptMenu_ShowMysteryPokemonPic(species, x, y);
    return FALSE;
}
#define tState        data[0]
#define tSpecies      data[1]
#define tSpriteId     data[2]
#define tWindowId     data[5]
void Remove_PokemonPic(void)
{
    u8 taskId = FindTaskIdByFunc(Task_ScriptShowMonPic);
    
    if (taskId != 0xFF)
    {
        u8 spriteId = gTasks[taskId].tSpriteId;

        if (spriteId < MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[spriteId];

            FreeSpriteOamMatrix(sprite);
            DestroySprite(sprite);
            FreeSpriteTiles(sprite);
            FreeSpritePalette(sprite);
        }
        DestroyTask(taskId);
    }
}
struct Pokemon* GetFirstValidPartyMon(void)
{
    for (int i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon* mon = &gPlayerParty[i];

        if (GetMonData(mon, MON_DATA_SPECIES, NULL) != SPECIES_NONE
            && !GetMonData(mon, MON_DATA_IS_EGG, NULL)
            && GetMonData(mon, MON_DATA_HP, NULL) > 0)
        {
            return mon;
        }
    }
    return NULL;
}

static u8 GetFollowerMapObjId(void)
{
	return gFollowerState.objId;
}

static const u16 sSpeciesToPaletteTag[] =
{
    [SPECIES_NONE] = 0X0000,
    [SPECIES_BULBASAUR] = 0x1300,
    [SPECIES_IVYSAUR] = 0x1301,
    [SPECIES_VENUSAUR] = 0x1302,
    [SPECIES_CHARMANDER] = 0x1303,
    [SPECIES_CHARMELEON] = 0x1304,
    [SPECIES_CHARIZARD] = 0x1305,
    [SPECIES_SQUIRTLE] = 0x1306,
    [SPECIES_WARTORTLE] = 0x1307,
    [SPECIES_BLASTOISE] = 0x1308,
    [SPECIES_CATERPIE] = 0x1309,
    [SPECIES_METAPOD] = 0x130A,
    [SPECIES_BUTTERFREE] = 0x130B,
    [SPECIES_WEEDLE] = 0x130C,
    [SPECIES_KAKUNA] = 0x130D,
    [SPECIES_BEEDRILL] = 0x130E,
    [SPECIES_PIDGEY] = 0x130F,
    [SPECIES_PIDGEOTTO] = 0x1310,
    [SPECIES_PIDGEOT] = 0x1311,
    [SPECIES_RATTATA] = 0x1312,
    [SPECIES_RATICATE] = 0x1313,
    [SPECIES_SPEAROW] = 0x1314,
    [SPECIES_FEAROW] = 0x1315,
    [SPECIES_EKANS] = 0x1316,
    [SPECIES_ARBOK] = 0x1317,
    [SPECIES_PIKACHU] = 0x1318,
    [SPECIES_RAICHU] = 0x1319,
    [SPECIES_SANDSHREW] = 0x131A,
    [SPECIES_SANDSLASH] = 0x131B,
    [SPECIES_NIDORAN_F] = 0x131C,
    [SPECIES_NIDORINA] = 0x131D,
    [SPECIES_NIDOQUEEN] = 0x131E,
    [SPECIES_NIDORAN_M] = 0x131F,
    [SPECIES_NIDORINO] = 0x1320,
    [SPECIES_NIDOKING] = 0x1321,
    [SPECIES_CLEFAIRY] = 0x1322,
    [SPECIES_CLEFABLE] = 0x1323,
    [SPECIES_VULPIX] = 0x1324,
    [SPECIES_NINETALES] = 0x1325,
    [SPECIES_JIGGLYPUFF] = 0x1326,
    [SPECIES_WIGGLYTUFF] = 0x1327,
    [SPECIES_ZUBAT] = 0x1328,
    [SPECIES_GOLBAT] = 0x1329,
    [SPECIES_ODDISH] = 0x132A,
    [SPECIES_GLOOM] = 0x132B,
    [SPECIES_VILEPLUME] = 0x132C,
    [SPECIES_PARAS] = 0x132D,
    [SPECIES_PARASECT] = 0x132E,
    [SPECIES_VENONAT] = 0x132F,
    [SPECIES_VENOMOTH] = 0x1330,
    [SPECIES_DIGLETT] = 0x1331,
    [SPECIES_DUGTRIO] = 0x1332,
    [SPECIES_MEOWTH] = 0x1333,
    [SPECIES_PERSIAN] = 0x1334,
    [SPECIES_PSYDUCK] = 0x1335,
    [SPECIES_GOLDUCK] = 0x1336,
    [SPECIES_MANKEY] = 0x1337,
    [SPECIES_PRIMEAPE] = 0x1338,
    [SPECIES_GROWLITHE] = 0x1339,
    [SPECIES_ARCANINE] = 0x133A,
    [SPECIES_POLIWAG] = 0x133B,
    [SPECIES_POLIWHIRL] = 0x133C,
    [SPECIES_POLIWRATH] = 0x133D,
    [SPECIES_ABRA] = 0x133E,
    [SPECIES_KADABRA] = 0x133F,
    [SPECIES_ALAKAZAM] = 0x1340,
    [SPECIES_MACHOP] = 0x1341,
    [SPECIES_MACHOKE] = 0x1342,
    [SPECIES_MACHAMP] = 0x1343,
    [SPECIES_BELLSPROUT] = 0x1344,
    [SPECIES_WEEPINBELL] = 0x1345,
    [SPECIES_VICTREEBEL] = 0x1346,
    [SPECIES_TENTACOOL] = 0x1347,
    [SPECIES_TENTACRUEL] = 0x1348,
    [SPECIES_GEODUDE] = 0x1349,
    [SPECIES_GRAVELER] = 0x134A,
    [SPECIES_GOLEM] = 0x134B,
    [SPECIES_PONYTA] = 0x134C,
    [SPECIES_RAPIDASH] = 0x134D,
    [SPECIES_SLOWPOKE] = 0x134E,
    [SPECIES_SLOWBRO] = 0x134F,
    [SPECIES_MAGNEMITE] = 0x1350,
    [SPECIES_MAGNETON] = 0x1351,
    [SPECIES_FARFETCHD] = 0x1352,
    [SPECIES_DODUO] = 0x1353,
    [SPECIES_DODRIO] = 0x1354,
    [SPECIES_SEEL] = 0x1355,
    [SPECIES_DEWGONG] = 0x1356,
    [SPECIES_GRIMER] = 0x1357,
    [SPECIES_MUK] = 0x1358,
    [SPECIES_SHELLDER] = 0x1359,
    [SPECIES_CLOYSTER] = 0x135A,
    [SPECIES_GASTLY] = 0x135B,
    [SPECIES_HAUNTER] = 0x135C,
    [SPECIES_GENGAR] = 0x135D,
    [SPECIES_ONIX] = 0x135E,
    [SPECIES_DROWZEE] = 0x135F,
    [SPECIES_HYPNO] = 0x1360,
    [SPECIES_KRABBY] = 0x1361,
    [SPECIES_KINGLER] = 0x1362,
    [SPECIES_VOLTORB] = 0x1363,
    [SPECIES_ELECTRODE] = 0x1364,
    [SPECIES_EXEGGCUTE] = 0x1365,
    [SPECIES_EXEGGUTOR] = 0x1366,
    [SPECIES_CUBONE] = 0x1367,
    [SPECIES_MAROWAK] = 0x1368,
    [SPECIES_HITMONLEE] = 0x1369,
    [SPECIES_HITMONCHAN] = 0x136A,
    [SPECIES_LICKITUNG] = 0x136B,
    [SPECIES_KOFFING] = 0x136C,
    [SPECIES_WEEZING] = 0x136D,
    [SPECIES_RHYHORN] = 0x136E,
    [SPECIES_RHYDON] = 0x136F,
    [SPECIES_CHANSEY] = 0x1370,
    [SPECIES_TANGELA] = 0x1371,
    [SPECIES_KANGASKHAN] = 0x1372,
    [SPECIES_HORSEA] = 0x1373,
    [SPECIES_SEADRA] = 0x1374,
    [SPECIES_GOLDEEN] = 0x1375,
    [SPECIES_SEAKING] = 0x1376,
    [SPECIES_STARYU] = 0x1377,
    [SPECIES_STARMIE] = 0x1378,
    [SPECIES_MR_MIME] = 0x1379,
    [SPECIES_SCYTHER] = 0x137A,
    [SPECIES_JYNX] = 0x137B,
    [SPECIES_ELECTABUZZ] = 0x137C,
    [SPECIES_MAGMAR] = 0x137D,
    [SPECIES_PINSIR] = 0x137E,
    [SPECIES_TAUROS] = 0x137F,
    [SPECIES_MAGIKARP] = 0x1380,
    [SPECIES_GYARADOS] = 0x1381,
    [SPECIES_LAPRAS] = 0x1382,
    [SPECIES_DITTO] = 0x1383,
    [SPECIES_EEVEE] = 0x1384,
    [SPECIES_VAPOREON] = 0x1385,
    [SPECIES_JOLTEON] = 0x1386,
    [SPECIES_FLAREON] = 0x1387,
    [SPECIES_PORYGON] = 0x1388,
    [SPECIES_OMANYTE] = 0x1389,
    [SPECIES_OMASTAR] = 0x138A,
    [SPECIES_KABUTO] = 0x138B,
    [SPECIES_KABUTOPS] = 0x138C,
    [SPECIES_AERODACTYL] = 0x138D,
    [SPECIES_SNORLAX] = 0x138E,
    [SPECIES_ARTICUNO] = 0x138F,
    [SPECIES_ZAPDOS] = 0x1390,
    [SPECIES_MOLTRES] = 0x1391,
    [SPECIES_DRATINI] = 0x1392,
    [SPECIES_DRAGONAIR] = 0x1393,
    [SPECIES_DRAGONITE] = 0x1394,
    [SPECIES_MEWTWO] = 0x1395,
    [SPECIES_MEW] = 0x1396,
    [SPECIES_CHIKORITA] = 0x1397,
    [SPECIES_BAYLEEF] = 0x1398,
    [SPECIES_MEGANIUM] = 0x1399,
    [SPECIES_CYNDAQUIL] = 0x139A,
    [SPECIES_QUILAVA] = 0x139B,
    [SPECIES_TYPHLOSION] = 0x139C,
    [SPECIES_TOTODILE] = 0x139D,
    [SPECIES_CROCONAW] = 0x139E,
    [SPECIES_FERALIGATR] = 0x139F,
    [SPECIES_SENTRET] = 0x13A0,
    [SPECIES_FURRET] = 0x13A1,
    [SPECIES_HOOTHOOT] = 0x13A2,
    [SPECIES_NOCTOWL] = 0x13A3,
    [SPECIES_LEDYBA] = 0x13A4,
    [SPECIES_LEDIAN] = 0x13A5,
    [SPECIES_SPINARAK] = 0x13A6,
    [SPECIES_ARIADOS] = 0x13A7,
    [SPECIES_CROBAT] = 0x13A8,
    [SPECIES_CHINCHOU] = 0x13A9,
    [SPECIES_LANTURN] = 0x13AA,
    [SPECIES_PICHU] = 0x13AB,
    [SPECIES_CLEFFA] = 0x13AC,
    [SPECIES_IGGLYBUFF] = 0x13AD,
    [SPECIES_TOGEPI] = 0x13AE,
    [SPECIES_TOGETIC] = 0x13AF,
    [SPECIES_NATU] = 0x13B0,
    [SPECIES_XATU] = 0x13B1,
    [SPECIES_MAREEP] = 0x13B2,
    [SPECIES_FLAAFFY] = 0x13B3,
    [SPECIES_AMPHAROS] = 0x13B4,
    [SPECIES_BELLOSSOM] = 0x13B5,
    [SPECIES_MARILL] = 0x13B6,
    [SPECIES_AZUMARILL] = 0x13B7,
    [SPECIES_SUDOWOODO] = 0x13B8,
    [SPECIES_POLITOED] = 0x13B9,
    [SPECIES_HOPPIP] = 0x13BA,
    [SPECIES_SKIPLOOM] = 0x13BB,
    [SPECIES_JUMPLUFF] = 0x13BC,
    [SPECIES_AIPOM] = 0x13BD,
    [SPECIES_SUNKERN] = 0x13BE,
    [SPECIES_SUNFLORA] = 0x13BF,
    [SPECIES_YANMA] = 0x13C0,
    [SPECIES_WOOPER] = 0x13C1,
    [SPECIES_QUAGSIRE] = 0x13C2,
    [SPECIES_ESPEON] = 0x13C3,
    [SPECIES_UMBREON] = 0x13C4,
    [SPECIES_MURKROW] = 0x13C5,
    [SPECIES_SLOWKING] = 0x13C6,
    [SPECIES_MISDREAVUS] = 0x13C7,
    [SPECIES_UNOWN] = 0x13C8,
    [SPECIES_WOBBUFFET] = 0x13C9,
    [SPECIES_GIRAFARIG] = 0x13CA,
    [SPECIES_PINECO] = 0x13CB,
    [SPECIES_FORRETRESS] = 0x13CC,
    [SPECIES_DUNSPARCE] = 0x13CD,
    [SPECIES_GLIGAR] = 0x13CE,
    [SPECIES_STEELIX] = 0x13CF,
    [SPECIES_SNUBBULL] = 0x13D0,
    [SPECIES_GRANBULL] = 0x13D1,
    [SPECIES_QWILFISH] = 0x13D2,
    [SPECIES_SCIZOR] = 0x13D3,
    [SPECIES_SHUCKLE] = 0x13D4,
    [SPECIES_HERACROSS] = 0x13D5,
    [SPECIES_SNEASEL] = 0x13D6,
    [SPECIES_TEDDIURSA] = 0x13D7,
    [SPECIES_URSARING] = 0x13D8,
    [SPECIES_SLUGMA] = 0x13D9,
    [SPECIES_MAGCARGO] = 0x13DA,
    [SPECIES_SWINUB] = 0x13DB,
    [SPECIES_PILOSWINE] = 0x13DC,
    [SPECIES_CORSOLA] = 0x13DD,
    [SPECIES_REMORAID] = 0x13DE,
    [SPECIES_OCTILLERY] = 0x13DF,
    [SPECIES_DELIBIRD] = 0x13E0,
    [SPECIES_MANTINE] = 0x13E1,
    [SPECIES_SKARMORY] = 0x13E2,
    [SPECIES_HOUNDOUR] = 0x13E3,
    [SPECIES_HOUNDOOM] = 0x13E4,
    [SPECIES_KINGDRA] = 0x13E5,
    [SPECIES_PHANPY] = 0x13E6,
    [SPECIES_DONPHAN] = 0x13E7,
    [SPECIES_PORYGON2] = 0x13E8,
    [SPECIES_STANTLER] = 0x13E9,
    [SPECIES_SMEARGLE] = 0x13EA,
    [SPECIES_TYROGUE] = 0x13EB,
    [SPECIES_HITMONTOP] = 0x13EC,
    [SPECIES_SMOOCHUM] = 0x13ED,
    [SPECIES_ELEKID] = 0x13EE,
    [SPECIES_MAGBY] = 0x13EF,
    [SPECIES_MILTANK] = 0x13F0,
    [SPECIES_BLISSEY] = 0x13F1,
    [SPECIES_RAIKOU] = 0x13F2,
    [SPECIES_ENTEI] = 0x13F3,
    [SPECIES_SUICUNE] = 0x13F4,
    [SPECIES_LARVITAR] = 0x13F5,
    [SPECIES_PUPITAR] = 0x13F6,
    [SPECIES_TYRANITAR] = 0x13F7,
    [SPECIES_LUGIA] = 0x13F8,
    [SPECIES_HO_OH] = 0x13F9,
    [SPECIES_CELEBI] = 0x13FA,
    [SPECIES_TREECKO] = 0x1500,
    [SPECIES_GROVYLE] = 0x1501,
    [SPECIES_SCEPTILE] = 0x1502,
    [SPECIES_TORCHIC] = 0x1503,
    [SPECIES_COMBUSKEN] = 0x1504,
    [SPECIES_BLAZIKEN] = 0x1505,
    [SPECIES_MUDKIP] = 0x1506,
    [SPECIES_MARSHTOMP] = 0x1507,
    [SPECIES_SWAMPERT] = 0x1508,
    [SPECIES_POOCHYENA] = 0x1509,
    [SPECIES_MIGHTYENA] = 0x150A,
    [SPECIES_ZIGZAGOON] = 0x150B,
    [SPECIES_LINOONE] = 0x150C,
    [SPECIES_WURMPLE] = 0x150D,
    [SPECIES_SILCOON] = 0x150E,
    [SPECIES_BEAUTIFLY] = 0x150F,
    [SPECIES_CASCOON] = 0x1510,
    [SPECIES_DUSTOX] = 0x1511,
    [SPECIES_LOTAD] = 0x1512,
    [SPECIES_LOMBRE] = 0x1513,
    [SPECIES_LUDICOLO] = 0x1514,
    [SPECIES_SEEDOT] = 0x1515,
    [SPECIES_NUZLEAF] = 0x1516,
    [SPECIES_SHIFTRY] = 0x1517,
    [SPECIES_NINCADA] = 0x1518,
    [SPECIES_NINJASK] = 0x1519,
    [SPECIES_SHEDINJA] = 0x151A,
    [SPECIES_TAILLOW] = 0x151B,
    [SPECIES_SWELLOW] = 0x151C,
    [SPECIES_SHROOMISH] = 0x151D,
    [SPECIES_BRELOOM] = 0x151E,
    [SPECIES_SPINDA] = 0x151F,
    [SPECIES_WINGULL] = 0x1520,
    [SPECIES_PELIPPER] = 0x1521,
    [SPECIES_SURSKIT] = 0x1522,
    [SPECIES_MASQUERAIN] = 0x1523,
    [SPECIES_WAILMER] = 0x1524,
    [SPECIES_WAILORD] = 0x1525,
    [SPECIES_SKITTY] = 0x1526,
    [SPECIES_DELCATTY] = 0x1527,
    [SPECIES_KECLEON] = 0x1528,
    [SPECIES_BALTOY] = 0x1529,
    [SPECIES_CLAYDOL] = 0x152A,
    [SPECIES_NOSEPASS] = 0x152B,
    [SPECIES_TORKOAL] = 0x152C,
    [SPECIES_SABLEYE] = 0x152D,
    [SPECIES_BARBOACH] = 0x152E,
    [SPECIES_WHISCASH] = 0x152F,
    [SPECIES_LUVDISC] = 0x1530,
    [SPECIES_CORPHISH] = 0x1531,
    [SPECIES_CRAWDAUNT] = 0x1532,
    [SPECIES_FEEBAS] = 0x1533,
    [SPECIES_MILOTIC] = 0x1534,
    [SPECIES_CARVANHA] = 0x1535,
    [SPECIES_SHARPEDO] = 0x1536,
    [SPECIES_TRAPINCH] = 0x1537,
    [SPECIES_VIBRAVA] = 0x1538,
    [SPECIES_FLYGON] = 0x1539,
    [SPECIES_MAKUHITA] = 0x153A,
    [SPECIES_HARIYAMA] = 0x153B,
    [SPECIES_ELECTRIKE] = 0x153C,
    [SPECIES_MANECTRIC] = 0x153D,
    [SPECIES_NUMEL] = 0x153E,
    [SPECIES_CAMERUPT] = 0x153F,
    [SPECIES_SPHEAL] = 0x1540,
    [SPECIES_SEALEO] = 0x1541,
    [SPECIES_WALREIN] = 0x1542,
    [SPECIES_CACNEA] = 0x1543,
    [SPECIES_CACTURNE] = 0x1544,
    [SPECIES_SNORUNT] = 0x1545,
    [SPECIES_GLALIE] = 0x1546,
    [SPECIES_LUNATONE] = 0x1547,
    [SPECIES_SOLROCK] = 0x1548,
    [SPECIES_AZURILL] = 0x1549,
    [SPECIES_SPOINK] = 0x154A,
    [SPECIES_GRUMPIG] = 0x154B,
    [SPECIES_PLUSLE] = 0x154C,
    [SPECIES_MINUN] = 0x154D,
    [SPECIES_MAWILE] = 0x154E,
    [SPECIES_MEDITITE] = 0x154F,
    [SPECIES_MEDICHAM] = 0x1550,
    [SPECIES_SWABLU] = 0x1551,
    [SPECIES_ALTARIA] = 0x1552,
    [SPECIES_WYNAUT] = 0x1553,
    [SPECIES_DUSKULL] = 0x1554,
    [SPECIES_DUSCLOPS] = 0x1555,
    [SPECIES_ROSELIA] = 0x1556,
    [SPECIES_SLAKOTH] = 0x1557,
    [SPECIES_VIGOROTH] = 0x1558,
    [SPECIES_SLAKING] = 0x1559,
    [SPECIES_GULPIN] = 0x155A,
    [SPECIES_SWALOT] = 0x155B,
    [SPECIES_TROPIUS] = 0x155C,
    [SPECIES_WHISMUR] = 0x155D,
    [SPECIES_LOUDRED] = 0x155E,
    [SPECIES_EXPLOUD] = 0x155F,
    [SPECIES_CLAMPERL] = 0x1560,
    [SPECIES_HUNTAIL] = 0x1561,
    [SPECIES_GOREBYSS] = 0x1562,
    [SPECIES_ABSOL] = 0x1563,
    [SPECIES_SHUPPET] = 0x1564,
    [SPECIES_BANETTE] = 0x1565,
    [SPECIES_SEVIPER] = 0x1566,
    [SPECIES_ZANGOOSE] = 0x1567,
    [SPECIES_RELICANTH] = 0x1568,
    [SPECIES_ARON] = 0x1569,
    [SPECIES_LAIRON] = 0x156A,
    [SPECIES_AGGRON] = 0x156B,
    [SPECIES_CASTFORM] = 0x156C,
    [SPECIES_VOLBEAT] = 0x156D,
    [SPECIES_ILLUMISE] = 0x156E,
    [SPECIES_LILEEP] = 0x156F,
    [SPECIES_CRADILY] = 0x1570,
    [SPECIES_ANORITH] = 0x1571,
    [SPECIES_ARMALDO] = 0x1572,
    [SPECIES_RALTS] = 0x1573,
    [SPECIES_KIRLIA] = 0x1574,
    [SPECIES_GARDEVOIR] = 0x1575,
    [SPECIES_BAGON] = 0x1576,
    [SPECIES_SHELGON] = 0x1577,
    [SPECIES_SALAMENCE] = 0x1578,
    [SPECIES_BELDUM] = 0x1579,
    [SPECIES_METANG] = 0x157A,
    [SPECIES_METAGROSS] = 0x157B,
    [SPECIES_REGIROCK] = 0x157C,
    [SPECIES_REGICE] = 0x157D,
    [SPECIES_REGISTEEL] = 0x157E,
    [SPECIES_KYOGRE] = 0x157F,
    [SPECIES_GROUDON] = 0x1580,
    [SPECIES_RAYQUAZA] = 0x1581,
    [SPECIES_LATIAS] = 0x1582,
    [SPECIES_LATIOS] = 0x1583,
    [SPECIES_JIRACHI] = 0x1584,
    [SPECIES_DEOXYS] = 0x1585,
    [SPECIES_CHIMECHO] = 0x1586,
    [SPECIES_TURTWIG] = 0x1587,
    [SPECIES_GROTLE] = 0x1588,
    [SPECIES_TORTERRA] = 0x1589,
    [SPECIES_CHIMCHAR] = 0x158A,
    [SPECIES_MONFERNO] = 0x158B,
    [SPECIES_INFERNAPE] = 0x158C,
    [SPECIES_PIPLUP] = 0x158D,
    [SPECIES_PRINPLUP] = 0x158E,
    [SPECIES_EMPOLEON] = 0x158F,
    [SPECIES_STARLY] = 0x1590,
    [SPECIES_STARAVIA] = 0x1591,
    [SPECIES_STARAPTOR] = 0x1592,
    [SPECIES_BIDOOF] = 0x1593,
    [SPECIES_BIBAREL] = 0x1594,
    [SPECIES_KRICKETOT] = 0x1595,
    [SPECIES_KRICKETUNE] = 0x1596,
    [SPECIES_SHINX] = 0x1597,
    [SPECIES_LUXIO] = 0x1598,
    [SPECIES_LUXRAY] = 0x1599,
    [SPECIES_BUDEW] = 0x159A,
    [SPECIES_ROSERADE] = 0x159B,
    [SPECIES_CRANIDOS] = 0x159C,
    [SPECIES_RAMPARDOS] = 0x159D,
    [SPECIES_SHIELDON] = 0x159E,
    [SPECIES_BASTIODON] = 0x159F,
    [SPECIES_BURMY] = 0x15A0,
    [SPECIES_WORMADAM] = 0x15A1,
    [SPECIES_MOTHIM] = 0x15A2,
    [SPECIES_COMBEE] = 0x15A3,
    [SPECIES_VESPIQUEN] = 0x15A4,
    [SPECIES_PACHIRISU] = 0x15A5,
    [SPECIES_BUIZEL] = 0x15A6,
    [SPECIES_FLOATZEL] = 0x15A7,
    [SPECIES_CHERUBI] = 0x15A8,
    [SPECIES_CHERRIM] = 0x15A9,
    [SPECIES_SHELLOS] = 0x15AA,
    [SPECIES_GASTRODON] = 0x15AB,
    [SPECIES_AMBIPOM] = 0x15AC,
    [SPECIES_DRIFLOON] = 0x15AD,
    [SPECIES_DRIFBLIM] = 0x15AE,
    [SPECIES_BUNEARY] = 0x15AF,
    [SPECIES_LOPUNNY] = 0x15B0,
    [SPECIES_MISMAGIUS] = 0x15B1,
    [SPECIES_HONCHKROW] = 0x15B2,
    [SPECIES_GLAMEOW] = 0x15B3,
    [SPECIES_PURUGLY] = 0x15B4,
    [SPECIES_CHINGLING] = 0x15B5,
    [SPECIES_STUNKY] = 0x15B6,
    [SPECIES_SKUNTANK] = 0x15B7,
    [SPECIES_BRONZOR] = 0x15B8,
    [SPECIES_BRONZONG] = 0x15B9,
    [SPECIES_BONSLY] = 0x15BA,
    [SPECIES_MIME_JR] = 0x15BB,
    [SPECIES_HAPPINY] = 0x15BC,
    [SPECIES_CHATOT] = 0x15BD,
    [SPECIES_SPIRITOMB] = 0x15BE,
    [SPECIES_GIBLE] = 0x15BF,
    [SPECIES_GABITE] = 0x15C0,
    [SPECIES_GARCHOMP] = 0x15C1,
    [SPECIES_MUNCHLAX] = 0x15C2,
    [SPECIES_RIOLU] = 0x15C3,
    [SPECIES_LUCARIO] = 0x15C4,
    [SPECIES_HIPPOPOTAS] = 0x15C5,
    [SPECIES_HIPPOWDON] = 0x15C6,
    [SPECIES_SKORUPI] = 0x15C7,
    [SPECIES_DRAPION] = 0x15C8,
    [SPECIES_CROAGUNK] = 0x15C9,
    [SPECIES_TOXICROAK] = 0x15CA,
    [SPECIES_CARNIVINE] = 0x15CB,
    [SPECIES_FINNEON] = 0x15CC,
    [SPECIES_LUMINEON] = 0x15CD,
    [SPECIES_MANTYKE] = 0x15CE,
    [SPECIES_SNOVER] = 0x15CF,
    [SPECIES_ABOMASNOW] = 0x15D0,
    [SPECIES_WEAVILE] = 0x15D1,
    [SPECIES_MAGNEZONE] = 0x15D2,
    [SPECIES_LICKILICKY] = 0x15D3,
    [SPECIES_RHYPERIOR] = 0x15D4,
    [SPECIES_TANGROWTH] = 0x15D5,
    [SPECIES_ELECTIVIRE] = 0x15D6,
    [SPECIES_MAGMORTAR] = 0x15D7,
    [SPECIES_TOGEKISS] = 0x15D8,
    [SPECIES_YANMEGA] = 0x15D9,
    [SPECIES_LEAFEON] = 0x15DA,
    [SPECIES_GLACEON] = 0x15DB,
    [SPECIES_GLISCOR] = 0x15DC,
    [SPECIES_MAMOSWINE] = 0x15DD,
    [SPECIES_PORYGON_Z] = 0x15DE,
    [SPECIES_GALLADE] = 0x15DF,
    [SPECIES_PROBOPASS] = 0x15E0,
    [SPECIES_DUSKNOIR] = 0x15E1,
    [SPECIES_FROSLASS] = 0x15E2,
    [SPECIES_ROTOM] = 0x15E3,
    [SPECIES_UXIE] = 0x15E4,
    [SPECIES_MESPRIT] = 0x15E5,
    [SPECIES_AZELF] = 0x15E6,
    [SPECIES_DIALGA] = 0x15E7,
    [SPECIES_PALKIA] = 0x15E8,
    [SPECIES_HEATRAN] = 0x15E9,
    [SPECIES_REGIGIGAS] = 0x15EA,
    [SPECIES_GIRATINA] = 0x15EB,
    [SPECIES_CRESSELIA] = 0x15EC,
    [SPECIES_PHIONE] = 0x15ED,
    [SPECIES_MANAPHY] = 0x15EE,
    [SPECIES_DARKRAI] = 0x15EF,
    [SPECIES_SHAYMIN] = 0x15F0,
    [SPECIES_ARCEUS] = 0x15F1,
    [SPECIES_VICTINI] = 0x15F2,
    // Gen 5
    [SPECIES_SNIVY] = 0x1700,
    [SPECIES_SERVINE] = 0x1701,
    [SPECIES_SERPERIOR] = 0x1702,
    [SPECIES_TEPIG] = 0x1703,
    [SPECIES_PIGNITE] = 0x1704,
    [SPECIES_EMBOAR] = 0x1705,
    [SPECIES_OSHAWOTT] = 0x1706,
    [SPECIES_DEWOTT] = 0x1707,
    [SPECIES_SAMUROTT] = 0x1708,
    [SPECIES_PATRAT] = 0x1709,
    [SPECIES_WATCHOG] = 0x170A,
    [SPECIES_LILLIPUP] = 0x170B,
    [SPECIES_HERDIER] = 0x170C,
    [SPECIES_STOUTLAND] = 0x170D,
    [SPECIES_PURRLOIN] = 0x170E,
    [SPECIES_LIEPARD] = 0x170F,
    [SPECIES_PANSAGE] = 0x1710,
    [SPECIES_SIMISAGE] = 0x1711,
    [SPECIES_PANSEAR] = 0x1712,
    [SPECIES_SIMISEAR] = 0x1713,
    [SPECIES_PANPOUR] = 0x1714,
    [SPECIES_SIMIPOUR] = 0x1715,
    [SPECIES_MUNNA] = 0x1716,
    [SPECIES_MUSHARNA] = 0x1717,
    [SPECIES_PIDOVE] = 0x1718,
    [SPECIES_TRANQUILL] = 0x1719,
    [SPECIES_UNFEZANT] = 0x171A,
    [SPECIES_BLITZLE] = 0x171B,
    [SPECIES_ZEBSTRIKA] = 0x171C,
    [SPECIES_ROGGENROLA] = 0x171D,
    [SPECIES_BOLDORE] = 0x171E,
    [SPECIES_GIGALITH] = 0x171F,
    [SPECIES_WOOBAT] = 0x1720,
    [SPECIES_SWOOBAT] = 0x1721,
    [SPECIES_DRILBUR] = 0x1722,
    [SPECIES_EXCADRILL] = 0x1723,
    [SPECIES_AUDINO] = 0x1724,
    [SPECIES_TIMBURR] = 0x1725,
    [SPECIES_GURDURR] = 0x1726,
    [SPECIES_CONKELDURR] = 0x1727,
    [SPECIES_TYMPOLE] = 0x1728,
    [SPECIES_PALPITOAD] = 0x1729,
    [SPECIES_SEISMITOAD] = 0x172A,
    [SPECIES_THROH] = 0x172B,
    [SPECIES_SAWK] = 0x172C,
    [SPECIES_SEWADDLE] = 0x172D,
    [SPECIES_SWADLOON] = 0x172E,
    [SPECIES_LEAVANNY] = 0x172F,
    [SPECIES_VENIPEDE] = 0x1730,
    [SPECIES_WHIRLIPEDE] = 0x1731,
    [SPECIES_SCOLIPEDE] = 0x1732,
    [SPECIES_COTTONEE] = 0x1733,
    [SPECIES_WHIMSICOTT] = 0x1734,
    [SPECIES_PETILIL] = 0x1735,
    [SPECIES_LILLIGANT] = 0x1736,
    [SPECIES_BASCULIN_RED] = 0x1737,
    [SPECIES_SANDILE] = 0x1738,
    [SPECIES_KROKOROK] = 0x1739,
    [SPECIES_KROOKODILE] = 0x173A,
    [SPECIES_DARUMAKA] = 0x173B,
    [SPECIES_DARMANITAN] = 0x173C,
    [SPECIES_MARACTUS] = 0x173D,
    [SPECIES_DWEBBLE] = 0x173E,
    [SPECIES_CRUSTLE] = 0x173F,
    [SPECIES_SCRAGGY] = 0x1740,
    [SPECIES_SCRAFTY] = 0x1741,
    [SPECIES_SIGILYPH] = 0x1742,
    [SPECIES_YAMASK] = 0x1743,
    [SPECIES_COFAGRIGUS] = 0x1744,
    [SPECIES_TIRTOUGA] = 0x1745,
    [SPECIES_CARRACOSTA] = 0x1746,
    [SPECIES_ARCHEN] = 0x1747,
    [SPECIES_ARCHEOPS] = 0x1748,
    [SPECIES_TRUBBISH] = 0x1749,
    [SPECIES_GARBODOR] = 0x174A,
    [SPECIES_ZORUA] = 0x174B,
    [SPECIES_ZOROARK] = 0x174C,
    [SPECIES_MINCCINO] = 0x174D,
    [SPECIES_CINCCINO] = 0x174E,
    [SPECIES_GOTHITA] = 0x174F,
    [SPECIES_GOTHORITA] = 0x1750,
    [SPECIES_GOTHITELLE] = 0x1751,
    [SPECIES_SOLOSIS] = 0x1752,
    [SPECIES_DUOSION] = 0x1753,
    [SPECIES_REUNICLUS] = 0x1754,
    [SPECIES_DUCKLETT] = 0x1755,
    [SPECIES_SWANNA] = 0x1756,
    [SPECIES_VANILLITE] = 0x1757,
    [SPECIES_VANILLISH] = 0x1758,
    [SPECIES_VANILLUXE] = 0x1759,
    [SPECIES_DEERLING] = 0x175A,
    [SPECIES_SAWSBUCK] = 0x175B,
    [SPECIES_EMOLGA] = 0x175C,
    [SPECIES_KARRABLAST] = 0x175D,
    [SPECIES_ESCAVALIER] = 0x175E,
    [SPECIES_FOONGUS] = 0x175F,
    [SPECIES_AMOONGUSS] = 0x1760,
    [SPECIES_FRILLISH] = 0x1761,
    [SPECIES_JELLICENT] = 0x1762,
    [SPECIES_ALOMOMOLA] = 0x1763,
    [SPECIES_JOLTIK] = 0x1764,
    [SPECIES_GALVANTULA] = 0x1765,
    [SPECIES_FERROSEED] = 0x1766,
    [SPECIES_FERROTHORN] = 0x1767,
    [SPECIES_KLINK] = 0x1768,
    [SPECIES_KLANG] = 0x1769,
    [SPECIES_KLINKLANG] = 0x176A,
    [SPECIES_TYNAMO] = 0x176B,
    [SPECIES_EELEKTRIK] = 0x176C,
    [SPECIES_EELEKTROSS] = 0x176D,
    [SPECIES_ELGYEM] = 0x176E,
    [SPECIES_BEHEEYEM] = 0x176F,
    [SPECIES_LITWICK] = 0x1770,
    [SPECIES_LAMPENT] = 0x1771,
    [SPECIES_CHANDELURE] = 0x1772,
    [SPECIES_AXEW] = 0x1773,
    [SPECIES_FRAXURE] = 0x1774,
    [SPECIES_HAXORUS] = 0x1775,
    [SPECIES_CUBCHOO] = 0x1776,
    [SPECIES_BEARTIC] = 0x1777,
    [SPECIES_CRYOGONAL] = 0x1778,
    [SPECIES_SHELMET] = 0x1779,
    [SPECIES_ACCELGOR] = 0x177A,
    [SPECIES_STUNFISK] = 0x177B,
    [SPECIES_MIENFOO] = 0x177C,
    [SPECIES_MIENSHAO] = 0x177D,
    [SPECIES_DRUDDIGON] = 0x177E,
    [SPECIES_GOLETT] = 0x177F,
    [SPECIES_GOLURK] = 0x1780,
    [SPECIES_PAWNIARD] = 0x1781,
    [SPECIES_BISHARP] = 0x1782,
    [SPECIES_BOUFFALANT] = 0x1783,
    [SPECIES_RUFFLET] = 0x1784,
    [SPECIES_BRAVIARY] = 0x1785,
    [SPECIES_VULLABY] = 0x1786,
    [SPECIES_MANDIBUZZ] = 0x1787,
    [SPECIES_HEATMOR] = 0x1788,
    [SPECIES_DURANT] = 0x1789,
    [SPECIES_DEINO] = 0x178A,
    [SPECIES_ZWEILOUS] = 0x178B,
    [SPECIES_HYDREIGON] = 0x178C,
    [SPECIES_LARVESTA] = 0x178D,
    [SPECIES_VOLCARONA] = 0x178E,
    [SPECIES_COBALION] = 0x178F,
    [SPECIES_TERRAKION] = 0x1790,
    [SPECIES_VIRIZION] = 0x1791,
    [SPECIES_TORNADUS] = 0x1792,
    [SPECIES_THUNDURUS] = 0x1793,
    [SPECIES_RESHIRAM] = 0x1794,
    [SPECIES_ZEKROM] = 0x1795,
    [SPECIES_LANDORUS] = 0x1796,
    [SPECIES_KYUREM] = 0x1797,
    [SPECIES_KELDEO] = 0x1798,
    [SPECIES_MELOETTA] = 0x1799,
    [SPECIES_GENESECT] = 0x179A,
    [SPECIES_BURMY_SANDY] = 0x179B,
    [SPECIES_BURMY_TRASH] = 0x0179C,
    [SPECIES_WORMADAM_SANDY] = 0x179D,
    [SPECIES_WORMADAM_TRASH] = 0x179E,
    [SPECIES_ROTOM_HEAT] = 0x179F,
    [SPECIES_ROTOM_WASH] = 0x17A0,
    [SPECIES_ROTOM_FROST] = 0x17A1,
    [SPECIES_ROTOM_FAN] = 0x17A2,
    [SPECIES_ROTOM_MOW] = 0x17A3,
    [SPECIES_GIRATINA_ORIGIN] = 0x17A4,
    [SPECIES_SHAYMIN_SKY] = 0x17A5,
    [SPECIES_ARCEUS_FLYING] = 0x17A6,
    [SPECIES_ARCEUS_POISON] = 0x17A7,
    [SPECIES_ARCEUS_GROUND] = 0x17A8,
    [SPECIES_ARCEUS_ROCK] = 0x17A9,
    [SPECIES_ARCEUS_BUG] = 0x17AA,
    [SPECIES_ARCEUS_GHOST] = 0x17AB,
    [SPECIES_ARCEUS_STEEL] = 0x17AC,
    [SPECIES_ARCEUS_FIRE] = 0x17AD,
    [SPECIES_ARCEUS_WATER] = 0x17AE,
    [SPECIES_ARCEUS_GRASS] = 0x17AF,
    [SPECIES_ARCEUS_ELECTRIC] = 0x17B0,
    [SPECIES_ARCEUS_PSYCHIC] = 0x17B1,
    [SPECIES_ARCEUS_ICE] = 0x17B2,
    [SPECIES_ARCEUS_DRAGON] = 0x17B3,
    [SPECIES_ARCEUS_DARK] = 0x17B4,
};
void ChangeFollowerPalette(void)
{
    u8 followerId = GetFollowerMapObjId();
    if (followerId >= MAP_OBJECTS_COUNT)
        return;

    struct EventObject* follower = &gEventObjects[followerId];
    if (!follower->active)
        return;

    u8 spriteId = follower->spriteId;
    if (spriteId >= MAX_SPRITES)
        return;

    struct Pokemon* mon = GetFirstValidPartyMon();
    if (mon == NULL)
        return;

    if (!IsMonShiny(mon))
        return;

    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    
    u16 paletteTag = (species < ARRAY_COUNT(sSpeciesToPaletteTag)) ? sSpeciesToPaletteTag[species] : 0x0000;
    if (paletteTag == 0x0000)
        return;

    const struct SpritePalette* paletteEntry = NULL;

    for (size_t tableIndex = 0; tableIndex < ARRAY_COUNT(sObjectEventSpritePalettesTables); tableIndex++)
    {
        const struct SpritePalette* paletteTable = sObjectEventSpritePalettesTables[tableIndex];

        for (int i = 0; paletteTable[i].data != NULL; i++)
        {
            if (paletteTable[i].tag == paletteTag)
            {
                paletteEntry = &paletteTable[i];
                break;
            }
        }

        if (paletteEntry != NULL)
            break;
    }

    if (paletteEntry == NULL)
        return;

    LoadPalette(paletteEntry->data, 0x100 + (16 * gSprites[spriteId].oam.paletteNum), 0x20);
    ApplyGlobalFieldPaletteTint(gSprites[spriteId].oam.paletteNum);
}