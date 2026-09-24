#include "modding.h"
#include "ultra64.h"
#include "enums.h"
#include "common_structs.h"

extern Actor *gCurrentPlayer;
extern u16 newly_pressed_input[];
void playAnimation(Actor *arg0, s32 arg2);

RECOMP_CALLBACK("*", dk64recomp_every_frame) void dance(void) {
    if (newly_pressed_input[0] & 0x20) {
        if (!(gCurrentPlayer->unk6A & 1)) return;
        if (gCurrentPlayer->unk58 > 7) return;
        switch (gCurrentPlayer->control_state) {
            case 0xC: // Idle
            case 0xD: // Walking
                break;
            default:
                return;
        }
        playAnimation(gCurrentPlayer, 0x5B);
        gCurrentPlayer->control_state = 0x71;
        gCurrentPlayer->control_state_progress = 0;
    }
}