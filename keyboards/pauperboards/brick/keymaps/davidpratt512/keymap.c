#include QMK_KEYBOARD_H


/* ---------------------------- Declare Custom Keycodes ---------------------------- */

enum layers {
    _QWERTY,
    _COLEMAK,
    _NUM,
    _NAV,
    _FUN,
    _MISC,
};

enum custom_keycodes {
    LQWERTY = SAFE_RANGE,
    LCOLEMA,
};

enum combos {
    PINKY_CAPS,
    COMBO_LENGTH,  /* Leave COMBO_LENGTH as last in enum */
};


/* ------------------------------------- Layers ------------------------------------ */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     *                                                                       1      1      1
     * 0      1      2      3      4      5      6      7      8      9      0      1      2
     * ,-----------------------------------------------------------------------------------.
     * | gesc |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   :  |  "   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | enter|
     * `------+------+------+------+------+------+------+------+------+------+------+------'
     *        | alt  | gui  | home |  NUM |  FUN | space|  NAV | end  | vol+ | alt  |
     *        `---------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_4x12_hhkb(
        QK_GESC,        KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,     KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
        LCTL_T(KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,     KC_G,     KC_H,   KC_J,     KC_K,    KC_L,    KC_COLN, RCTL_T(KC_QUOT),
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,     KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
                        KC_LALT, KC_LGUI, KC_HOME, MO(_NUM), MO(_FUN), KC_SPC, MO(_NAV), KC_END,  KC_VOLU, KC_LALT
    ),

    /* Colemak
     *                                                                       1      1      1
     * 0      1      2      3      4      5      6      7      8      9      0      1      2
     * ,-----------------------------------------------------------------------------------.
     * | gesc |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   :  | bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | tab  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  "   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | enter|
     * `------+------+------+------+------+------+------+------+------+------+------+------'
     *        | alt  | gui  | home | MO(1)| MO(3)| space| MO(2)| end  | vol+ | alt  |
     *        `---------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_ortho_4x12_hhkb(
        QK_GESC,        KC_Q,    KC_W,    KC_F,    KC_P,     KC_B,     KC_J,   KC_L,     KC_U,    KC_Y,    KC_COLN, KC_BSPC,
        LCTL_T(KC_TAB), KC_A,    KC_R,    KC_S,    KC_T,     KC_G,     KC_M,   KC_N,     KC_E,    KC_I,    KC_O,    RCTL_T(KC_QUOT),
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_D,     KC_V,     KC_K,   KC_H,     KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
                        KC_LALT, KC_LGUI, KC_HOME, MO(_NUM), MO(_FUN), KC_SPC, MO(_NAV), KC_END,  KC_VOLU, KC_LALT
    ),

    /* Numpad / Symbols
     *                                                                       1      1      1
     * 0      1      2      3      4      5      6      7      8      9      0      1      2
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |   {  |   }  |   <  |   >  |   7  |   8  |   9  |   =  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   +  |   -  |   *  |   /  |   [  |   ]  |   4  |   5  |   6  |   ,  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |   1  |   2  |   3  |   .  |      |
     * `------+------+------+------+------+------+------+------+------+------+------+------'
     *        |      |      |      |      |      |      |   0  |      | vol- |      |
     *        `---------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_ortho_4x12_hhkb(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_LT,   KC_GT,   KC_7, KC_8,    KC_9,    KC_EQL,  KC_TRNS,
        KC_TRNS, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_LBRC, KC_RBRC, KC_4, KC_5,    KC_6,    KC_COMM, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_2,    KC_3,    KC_DOT,  KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_VOLD, KC_TRNS
    ),

    /* HJKL & i3 Nav & Symbols
     *                                                                       1      1      1
     * 0      1      2      3      4      5      6      7      8      9      0      1      2
     * ,-----------------------------------------------------------------------------------.
     * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   -  |   =  |  del |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | i3_1 | i3_2 | i3_3 | i3_4 |   _  | left | down |  up  | rght |   |  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | i3_1 | i3_2 | i3_3 | i3_4 | i3_R | home | pgdn | pgup |  end |   \  |      |
     * `------+------+------+------+------+------+------+------+------+------+------+------'
     *        |      |      |      |      |      |      |      |      | vol- |      |
     *        `---------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_ortho_4x12_hhkb(
        KC_TRNS, KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  KC_DEL,
        KC_TRNS, A(KC_1),    A(KC_2),    A(KC_3),    A(KC_4),    KC_UNDS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PIPE, KC_GRV,
        KC_TRNS, A(S(KC_1)), A(S(KC_2)), A(S(KC_3)), A(S(KC_4)), A(KC_0), KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSLS, KC_TRNS,
                 KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS
    ),

    /* Function Layer
     *                                                                       1      1      1
     * 0      1      2      3      4      5      6      7      8      9      0      1      2
     * ,-----------------------------------------------------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  | zoom0| zoom-| zoom+|  {   |  }   | pause| clear|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F5  |  F6  |  F7  |  F8  | ws 4 |  br- |  br+ |  [   |  ]   |  |   |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F9  |  F10 |  F11 |  F12 | i3ex | MISC | flux |  <   |  >   |  \   |      |
     * `------+------+------+------+------+------+------+------+------+------+------+------'
     *        |      |      |      |      |      |      |      |      | mute |      |
     *        `---------------------------------------------------------------------'
     */
    [_FUN] = LAYOUT_ortho_4x12_hhkb(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   RCTL(KC_0), RCTL(KC_MINS), RCS(KC_EQL), KC_LCBR, KC_RCBR, KC_PAUS, KC_CLR,
        KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   A(KC_4),    A(KC_PGDN),    A(KC_PGUP),  KC_LBRC, KC_RBRC, KC_PIPE, KC_TRNS,
        KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  A(KC_0),    MO(_MISC),     A(KC_END),   KC_LT,   KC_GT,   KC_BSLS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,       KC_TRNS,     KC_TRNS, KC_MUTE, KC_TRNS
    ),

    /* RESET & RGB Lighting - mainly for niu mini
     *                                                                       1      1      1
     * 0      1      2      3      4      5      6      7      8      9      0      1      2
     * ,-----------------------------------------------------------------------------------.
     * |      | reset| qwer | cole |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |  TOG |  MOD |  HUI |  SAT |  VAL |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  pwr |  slp |      |      |      |      |      |      |      |      |      |
     * `------+------+------+------+------+------+------+------+------+------+------+------'
     *        |      |      |      |      |      |      |      |      |      |      |
     *        `---------------------------------------------------------------------'
     */
    [_MISC] = LAYOUT_ortho_4x12_hhkb(
        KC_TRNS, QK_BOOT, LQWERTY, LCOLEMA, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
        KC_TRNS, KC_PWR,  KC_SLEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

};


/* -------------------------------- Custom Keycodes -------------------------------- */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LQWERTY:
            /* Switch to the QWERTY base layer */
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;

        case LCOLEMA:
            /* Switch to the COLEMAK base layer */
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
    }
    return true;
}


/* ------------------------------------- ModTap ------------------------------------ */

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    /*
     * Return false for any key that you want to use IGNORE_MOD_TAP_INTERRUPT on.
     * Return true for any key that you *don't* want to use that on.
     */
    switch (keycode) {
        case LCTL_T(KC_TAB):
        case LCTL_T(KC_QUOT):
            return false;
        default:
            return true;
    }
}


/* ------------------------------------- Combos ------------------------------------ */

uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM pinky_caps_combo[] = {LCTL_T(KC_TAB), RCTL_T(KC_QUOT), COMBO_END};
combo_t key_combos[] = {
    [PINKY_CAPS] = COMBO(pinky_caps_combo, KC_CAPS),
};


/* --------------------------------- Key Overrides --------------------------------- */

const key_override_t comma_paren_override = ko_make_with_layers(
        MOD_MASK_SHIFT,  /* When shift is active            */
        KC_COMM,         /* and KC_COMM is pressed          */
        KC_LPRN,         /* replace the result with KC_LPRN */
        1 << _QWERTY     /* on these layers.                */
);

const key_override_t dot_paren_override = ko_make_with_layers(
        MOD_MASK_SHIFT,  /* When shift is active            */
        KC_DOT,          /* and KC_DOT is pressed           */
        KC_RPRN,         /* replace the result with KC_RPRN */
        1 << _QWERTY     /* on these layers.                */
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
