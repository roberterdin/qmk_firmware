#include QMK_KEYBOARD_H

enum layer_names {
    _QW,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NAV,
    };

enum custom_keycodes {
  BACKLIT= SAFE_RANGE,
  LOWER,
  RAISE,
  KC_LSTRT,
  KC_LEND,
  KC_PRVWD,
  KC_NXTWD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * |   `    | 1      | 2      | 3      | 4      | 5      | -      |   ~    | =      | 6      | 7      | 8      | 9      | 0      |  DEL   |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * |CTL|Esc | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      |  '     |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | ENTER  |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | LALT   |  LCTL  | LOWER  | ENTER  | LEFT   | DOWN   | RIGHT  | SPACE  | RAISE  | NAV    | RALT   | RGUI   | RCTRL  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_TILD,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        MT(MOD_LCTL, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LCTL, LOWER,  KC_ENT,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  RAISE,  MO(_NAV), KC_RALT, KC_RGUI, KC_RCTL
    ),

    /* LOWER
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | SELECT |    !   |    @   |    #   |   $    |    %   | P7     | P8     | P9     |   ^    |   &    |   *    |   (    |   )    |  Del   |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |   _    |    +   |   {    |   }    |   |    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |  Vol+  |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     |        |  Raise |  Prv   |  Nxt   |  Vol-  |  Play  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_5x15( 
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_MSEL, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR,   KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,  _______, _______, KC_VOLU, _______,
        _______, _______, RGB_TOG, _______, RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, _______, RAISE, KC_MPRV, KC_MNXT, KC_VOLD, KC_MPLY
    ),

    /* RAISE
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     |        |   -    |  =     |  [     |   ]    |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     |        |        |        |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_5x15( 
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______,   _______, _______, _______,
        KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
        KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______, _______, _______,
        _______, _______, RGB_TOG, LOWER, RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, _______, RAISE, _______, _______, _______, _______
    ),

    /* NAV
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     |        |  PrevW |   UP   | NextW  |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     |  LineS |  LEFT  | DOWN   |  RIGHT | LineE  |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     |        |        |        |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_ortho_5x15( 
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   _______, KC_PRVWD, KC_UP,   KC_NXTWD, _______, _______,
        MT(MOD_LCTL, KC_ESC), KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_LSTRT, KC_LEFT, KC_DOWN, KC_RGHT, KC_LEND, _______,
        KC_LSFT, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______, _______, _______,
        _______, _______, RGB_TOG, _______, RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, _______, _______, _______, _______, _______, _______
    ),


    /* Adjust (Lower + Raise)
    * ,--------------------------------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | Reset|      |      |      |      |      |      |      |      |      |      |      | Reset|  Del |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |Aud on|Audoff|AGnorm|      |      |      |AGswap|Qwerty|      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|      |      |      |MIDIof|      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
    * `--------------------------------------------------------------------------------------------------------'
    */

    [_ADJUST] = LAYOUT_ortho_5x15(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   KC_DEL,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, _______, _______, _______, AG_SWAP,_______ ,  _______,_______,  _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   _______, _______, _______, MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case KC_PRVWD:
        if (record->event.pressed) {
            if (keymap_config.swap_lctl_lgui) {
                register_mods(mod_config(MOD_LALT));
                register_code(KC_LEFT);
            } else {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_LEFT);
            }
        } else {
            if (keymap_config.swap_lctl_lgui) {
                unregister_mods(mod_config(MOD_LALT));
                unregister_code(KC_LEFT);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_LEFT);
            }
        }
        break;
    case KC_NXTWD:
        if (record->event.pressed) {
            if (keymap_config.swap_lctl_lgui) {
                register_mods(mod_config(MOD_LALT));
                register_code(KC_RIGHT);
            } else {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_RIGHT);
            }
        } else {
            if (keymap_config.swap_lctl_lgui) {
                unregister_mods(mod_config(MOD_LALT));
                unregister_code(KC_RIGHT);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_RIGHT);
            }
        }
        break;
    case KC_LSTRT:
        if (record->event.pressed) {
            if (keymap_config.swap_lctl_lgui) {
                // CMD-arrow on Mac, but we have CTL and GUI swapped
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_LEFT);
            } else {
                register_code(KC_HOME);
            }
        } else {
            if (keymap_config.swap_lctl_lgui) {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_LEFT);
            } else {
                unregister_code(KC_HOME);
            }
        }
        break;
    case KC_LEND:
        if (record->event.pressed) {
            if (keymap_config.swap_lctl_lgui) {
                // CMD-arrow on Mac, but we have CTL and GUI swapped
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_RIGHT);
            } else {
                register_code(KC_END);
            }
        } else {
            if (keymap_config.swap_lctl_lgui) {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_RIGHT);
            } else {
                unregister_code(KC_END);
            }
        }
        break;
  }
  return true;
}

