.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_MoveReminder
EventScript_MoveReminder:
    lock
    faceplayer
    msgbox gText_MoveReminderHi MSG_YESNO
    compare LASTRESULT 0x1
    if 0x0 _goto MoveReminder_No
    msgbox gText_MoveReminderChooseMon MSG_NORMAL
    call MoveReminder_Teach
    msgbox gText_MoveReminderWhichMove MSG_NORMAL
    call MoveReminder_TeachMoves
    release
    end

MoveReminder_Teach:
    special 0xDB
    waitstate
    compare 0x8004 0x6
    if 0x4 _goto MoveReminder_End
    special 0x148
    compare LASTRESULT 0x1
    if 0x1 _goto MoveReminder_IsEgg
    compare 0x8005 0x0
    if 0x1 _goto MoveReminder_NoMoves
    return

MoveReminder_TeachMoves:
    special 0xE0
    waitstate
    compare 0x8004 0x0
    if 0x1 _goto MoveReminder_End
    return

MoveReminder_End:
    msgbox gText_MoveReminderNo MSG_NORMAL
    release
    end

MoveReminder_IsEgg:
    msgbox gText_MoveReminderIsEgg MSG_NORMAL
    release
    end

MoveReminder_NoMoves:
    msgbox gText_MoveReminderNoMoves MSG_NORMAL
    release
    end

MoveReminder_No:
    msgbox gText_MoveReminderNo MSG_NORMAL
    release
    end