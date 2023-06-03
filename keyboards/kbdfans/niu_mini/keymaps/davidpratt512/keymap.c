#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY Layer */
    [0] = LAYOUT_planck_mit(
            QK_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
            KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_COLN, KC_QUOT, 
            KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SC_SENT, 
            KC_LCTL, LALT_T(KC_CAPS), KC_LGUI, KC_LBRC, MO(1), KC_SPC, MO(2), KC_RBRC, KC_HOME, KC_RALT, KC_RCTL
    ),
    /* Numpad Layer */
    [1] = LAYOUT_planck_mit(
            KC_TRNS, KC_NUM, RGB_HUI, RGB_SAI, RGB_VAI, KC_LBRC, KC_RBRC, KC_P7, KC_P8, KC_P9, KC_EQL, KC_TRNS,
            KC_TRNS, KC_PPLS, KC_MINS, KC_PAST, KC_PSLS, KC_LT, KC_GT, KC_P4, KC_P5, KC_P6, KC_COMM, KC_QUOT, 
            KC_TRNS, KC_INS, KC_PSCR, KC_PGDN, KC_PGUP, KC_TRNS, KC_P0, KC_P1, KC_P2, KC_P3, KC_DOT, KC_TRNS, 
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_TRNS, KC_TRNS
    ),
    /* HJKL & F-keys */
    [2] = LAYOUT_planck_mit(
            KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_EQL, KC_DEL,
            KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_UNDS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSLS, KC_TRNS, 
            KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, RGB_MOD, MO(3), KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, 
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_TRNS, KC_TRNS
    ),
    /* RESET & RGB Lighting */
    [3] = LAYOUT_planck_mit(
        KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, RGB_HUI, RGB_SAI, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};


/* Layer lighting */

// individual layers
const rgblight_segment_t PROGMEM layer1[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_RED}
);

// array of layers
// later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer1
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}


/* --------------------------------- Key Overrides --------------------------------- */

const key_override_t comma_paren_override = ko_make_with_layers(
        MOD_MASK_SHIFT,  /* When shift is active            */
        KC_COMM,         /* and KC_COMM is pressed          */
        KC_LPRN,         /* replace the result with KC_LPRN */
        1 << 0           /* on these layers.                */
);

const key_override_t dot_paren_override = ko_make_with_layers(
        MOD_MASK_SHIFT,  /* When shift is active            */
        KC_DOT,          /* and KC_DOT is pressed           */
        KC_RPRN,         /* replace the result with KC_RPRN */
        1 << 0           /* on these layers.                */
);

const key_override_t colon_semicolon_override = ko_make_basic(
        MOD_MASK_SHIFT,  /* When shift is active            */
        KC_COLN,         /* and KC_COLN is pressed          */
        KC_SCLN          /* replace the result with KC_SCLN */
);

const key_override_t **key_overrides = (const key_override_t *[]) {
    &comma_paren_override,
    &dot_paren_override,
    &colon_semicolon_override,
    NULL  /* The array must be null-terminated */
};
