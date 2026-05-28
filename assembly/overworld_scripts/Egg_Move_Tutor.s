.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_EggMoveTeacher
EventScript_EggMoveTeacher:
    lock
    faceplayer
    msgbox gText_EggMoveHi MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto EggMove_No
    msgbox gText_EggMoveChooseMon MSG_NORMAL
    call Teach
    msgbox gText_EggMoveWhichMove MSG_NORMAL
    call TeachMoves
    clearflag 0x917
    release
    end

Teach:
    setflag 0x917
    special 0xDB
    waitstate
    compare 0x8004 0x6
    if 0x4 _goto EggMove_End
    special 0x148
    compare LASTRESULT 0x1
    if 0x1 _goto EggMove_IsEgg
    compare 0x8005 0x0
    if 0x1 _goto EggMove_NoMoves
    return

TeachMoves:
    special 0xE0
    waitstate
    compare 0x8004 0x0
    if 0x1 _goto EggMove_End
    return

EggMove_End:
    clearflag 0x917
    msgbox gText_EggMoveNo MSG_NORMAL
    release
    end

EggMove_IsEgg:
    clearflag 0x917
    msgbox gText_EggMoveIsEgg MSG_NORMAL
    release
    end

EggMove_NoMoves:
    clearflag 0x917
    msgbox gText_EggMoveNoMoves MSG_NORMAL
    release
    end

EggMove_No:
    msgbox gText_EggMoveNo MSG_NORMAL
    release
    end