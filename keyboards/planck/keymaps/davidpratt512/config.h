#pragma once

/* -- TapDance --------------------------------------------------------------------- */

#define TAPPING_TERM 175          /* Timeout for TapDance and ModTaps */
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY


/* -- Audio at startup ------------------------------------------------------------- */

/*
 * HOLST OP.28 MOVEMENT 1
 * F G A A# C
 */
#define HOLST_STARTUP H__NOTE(_F3), \
    H__NOTE(_G3), \
    H__NOTE(_A3), \
    H__NOTE(_AS3), \
    H__NOTE(_C4), \
    WD_NOTE(_REST), \
    H__NOTE(_F6), \
    H__NOTE(_G6), \
    H__NOTE(_A6), \
    H__NOTE(_AS6), \
    H__NOTE(_C7)

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(HOLST_STARTUP)
#endif
