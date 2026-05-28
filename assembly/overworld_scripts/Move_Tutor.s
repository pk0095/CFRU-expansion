.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_MoveTutor
EventScript_MoveTutor:
    lock
    faceplayer
    msgbox gText_MoveTutorHi MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto MoveTutor_No
    preparemsg gText_MoveTutorChoose
    waitmsg
    multichoiceoption gText_MoveTutorMoveReminder 0
    multichoiceoption gText_MoveTutorEggMove 1
    multichoiceoption gText_MoveTutorExit 2
    multichoice 0x0 0x0 THREE_MULTICHOICE_OPTIONS 0x0
    compare LASTRESULT 0x0
    if 0x1 _goto MoveTutor_MoveReminder
    compare LASTRESULT 0x1
    if 0x1 _goto MoveTutor_EggMove
    goto MoveTutor_No

MoveTutor_MoveReminder:
    msgbox gText_MoveTutorChooseMon MSG_NORMAL
    call MoveTutor_Teach
    msgbox gText_MoveTutorWhichMove MSG_NORMAL
    call MoveTutor_TeachMoves
    release
    end

MoveTutor_EggMove:
    msgbox gText_MoveTutorChooseMon MSG_NORMAL
    call MoveTutor_EggTeach
    msgbox gText_MoveTutorWhichMove MSG_NORMAL
    call MoveTutor_TeachMoves
    clearflag 0x917
    release
    end

MoveTutor_Teach:
    special 0xDB
    waitstate
    compare 0x8004 0x6
    if 0x4 _goto MoveTutor_End
    special 0x148
    compare LASTRESULT 0x1
    if 0x1 _goto MoveTutor_IsEgg
    compare 0x8005 0x0
    if 0x1 _goto MoveTutor_NoMoves
    return

MoveTutor_EggTeach:
    setflag 0x917
    special 0xDB
    waitstate
    compare 0x8004 0x6
    if 0x4 _goto MoveTutor_EggEnd
    special 0x148
    compare LASTRESULT 0x1
    if 0x1 _goto MoveTutor_EggIsEgg
    compare 0x8005 0x0
    if 0x1 _goto MoveTutor_EggNoMoves
    return

MoveTutor_TeachMoves:
    special 0xE0
    waitstate
    compare 0x8004 0x0
    if 0x1 _goto MoveTutor_End
    return

MoveTutor_End:
    msgbox gText_MoveTutorNo MSG_NORMAL
    release
    end

MoveTutor_EggEnd:
    clearflag 0x917
    msgbox gText_MoveTutorNo MSG_NORMAL
    release
    end

MoveTutor_IsEgg:
    msgbox gText_MoveTutorIsEgg MSG_NORMAL
    release
    end

MoveTutor_EggIsEgg:
    clearflag 0x917
    msgbox gText_MoveTutorIsEgg MSG_NORMAL
    release
    end

MoveTutor_NoMoves:
    msgbox gText_MoveTutorNoMoves MSG_NORMAL
    release
    end

MoveTutor_EggNoMoves:
    clearflag 0x917
    msgbox gText_MoveTutorEggNoMoves MSG_NORMAL
    release
    end

MoveTutor_No:
    msgbox gText_MoveTutorNo MSG_NORMAL
    release
    end