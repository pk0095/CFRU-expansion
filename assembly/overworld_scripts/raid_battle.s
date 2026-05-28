.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.equ SPECIAL_IS_RAID_BATTLE_AVAILABLE, 0x115
.equ SPECIAL_RAID_BATTLE_INTRO, 0x116
.equ SPECIAL_CREATE_RAID_MON, 0x117
.equ SPECIAL_START_RAID_BATTLE, 0x118
.equ SPECIAL_SET_RAID_BATTLE_FLAG, 0x119
.equ SPECIAL_CLEAR_RAID_FLAG, 0x11A
.equ SPECIAL_GIVE_RAID_BATTLE_REWARDS, 0x11C

.equ FLAG_TAG_BATTLE, 0x908
.equ FLAG_DYNAMAX_BATTLE, 0x918

.equ VAR_DAILY_EVENT, 0x504C
.equ SP_DAILY_EVENT, 0xA0

.equ ITEM_WISHING_PIECE, 0x281

.global EventScript_BeginARaidBattle

EventScript_BeginARaidBattle:
	lock
	faceplayer
	special SPECIAL_IS_RAID_BATTLE_AVAILABLE
	compare LASTRESULT 0x1
	if equal _goto RaidScript_DoStuff
	goto RaidScript_NoBattle

RaidScript_DoStuff:
	msgbox gText_StartRaidBattle MSG_YESNO
	compare LASTRESULT 0x1
	if equal _goto EventScript_RaidScreen
	release
	end

EventScript_RaidScreen:
	fadescreen FADEOUT_BLACK
	special SPECIAL_RAID_BATTLE_INTRO
	waitstate
	compare LASTRESULT 0x0
	if equal _goto RaidScript_End

	msgbox gText_Choose3 MSG_NORMAL

	special 0x27
	special 0xF5
	waitstate

	compare LASTRESULT 0x0
	if equal _goto RaidScript_End2

	special 0x28
	compare LASTRESULT 0x0
	if equal _goto RaidScript_End

	setflag FLAG_TAG_BATTLE
	setflag FLAG_DYNAMAX_BATTLE

	msgbox gText_JoinedYouTake MSG_SIGN

	special SPECIAL_CREATE_RAID_MON
	special SPECIAL_START_RAID_BATTLE
	waitstate

	special2 LASTRESULT 0xB4

	compare LASTRESULT 0x4
	if equal _goto RaidScript_End

	compare LASTRESULT 0x5
	if equal _goto RaidScript_End

	setvar 0x8000 VAR_DAILY_EVENT
	setvar 0x8001 0x1
	special2 LASTRESULT SP_DAILY_EVENT

	call EventScript_SetRaidFlag

	setvar 0x4000 0x0

	goto RaidScript_GiveReward

RaidScript_GiveReward:
	special SPECIAL_GIVE_RAID_BATTLE_REWARDS
	compare LASTRESULT 0x0
	if notequal _goto RaidScript_End
	callstd MSG_FIND
	goto RaidScript_GiveReward

RaidScript_End:
	clearflag FLAG_TAG_BATTLE
	clearflag FLAG_DYNAMAX_BATTLE
	release
	end

RaidScript_End2:
	special 0x28
	clearflag FLAG_TAG_BATTLE
	clearflag FLAG_DYNAMAX_BATTLE
	release
	end

RaidScript_NoBattle:
	checkitem ITEM_WISHING_PIECE 0x1
	compare LASTRESULT 0x1
	if notequal _goto RaidScript_NoPiece

	msgbox gText_UseWishingPiece MSG_YESNO
	compare LASTRESULT 0x1
	if notequal _goto RaidScript_NoPiece

	removeitem ITEM_WISHING_PIECE 0x1

	setvar 0x8000 0x1
	special SPECIAL_CLEAR_RAID_FLAG

	msgbox gText_WishingPieceUsed MSG_NORMAL

	goto RaidScript_DoStuff

RaidScript_NoPiece:
	msgbox gText_DenEmpty MSG_NORMAL
	release
	end

EventScript_SetRaidFlag:
	special SPECIAL_SET_RAID_BATTLE_FLAG
	return