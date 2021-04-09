/* Copyright 2020 imchipwood
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include <stdio.h>

#define ANIM_SIZE 512

// double calc_total = 0.0;
// double calc_input = 0.0;
// char calc_operator = ' ';


enum layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _NUMPAD,
    _SUB,
    _SYSTEM,
};

enum custom_keycodes {
    KC_CLOSE = SAFE_RANGE,
};


// Tap Dance declarations
enum {
    TD_DOT_CALC,
    TD_PLUS_ENTER,
    TD_SLASH_BACKSP,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_DOT_CALC] = ACTION_TAP_DANCE_DOUBLE(KC_DOT,KC_CALC),
    [TD_PLUS_ENTER] = ACTION_TAP_DANCE_DOUBLE(KC_KP_PLUS,KC_ENTER),
    [TD_SLASH_BACKSP] = ACTION_TAP_DANCE_DOUBLE(KC_KP_SLASH,KC_BSPC),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
            BASE LAYER
    /-----------------------------------------------------`
    |             |    /    |    *    |    -    |    +    |
    |             |---------|---------|---------|---------|
    |             |    9    |    6    |    3    |    .    |
    |             |---------|---------|---------|---------|
    |             |    8    |    5    |    2    |    0    |
    |-------------|---------|---------|---------|---------|
    | Left mouse  |    7    |    4    |    1    |  TT(1)  |
    \-----------------------------------------------------'
    */
    [_NUMPAD] = LAYOUT(
                    TD(TD_SLASH_BACKSP),  KC_KP_ASTERISK,     KC_KP_MINUS,   TD(TD_PLUS_ENTER),
                    KC_9,               KC_6,               KC_3,          TD(TD_DOT_CALC),
                    KC_8,               KC_5,               KC_2,          KC_0,
        KC_MUTE,    KC_7,               KC_4,               KC_1,          TG(_SUB)
    ),

    /*  SUB
    /-----------------------------------------------------`
    |             |         |         |         |         |
    |             |---------|---------|---------|---------|
    |             |         |         |         |         |
    |             |---------|---------|---------|---------|
    |             |         |         |         |         |
    |-------------|---------|---------|---------|---------|
    | Left mouse  | MACWIN  |         |         |  NUMP   |
    \-----------------------------------------------------'
    */
    [_SUB] = LAYOUT(
                    XXXXXXX,      XXXXXXX,    XXXXXXX,      XXXXXXX,
                    XXXXXXX,      XXXXXXX,    XXXXXXX,      XXXXXXX,
                    XXXXXXX,      XXXXXXX,    XXXXXXX,      XXXXXXX,
        KC_MPLY,    CG_TOGG,     XXXXXXX,     XXXXXXX,      TG(_SUB)
    ),
    /*
            SUB LAYER
    /-----------------------------------------------------`
    |             |         |         |         |  Reset  |
    |             |---------|---------|---------|---------|
    |             |         |         |         |    +    |
    |             |---------|---------|---------|---------|
    |             |         |         |         |    -    |
    |-------------|---------|---------|---------|---------|
    |    LOCK     |         |         |         |    =    |
    \-----------------------------------------------------'
    */
    [_SYSTEM] = LAYOUT(
                    _______,     _______,     _______,      RESET,
                    _______,     _______,     _______,      KC_KP_PLUS,
                    _______,     _______,     _______,      KC_KP_MINUS,
        KC_LOCK,    _______,     _______,     _______,      KC_EQL
    ),
};



void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    //debug_enable = true;
    //debug_matrix = true;
    //debug_keyboard = true;
    //debug_mouse = true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _NUMPAD:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _SUB:
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_EQL);
                } else {
                    tap_code(KC_MINS);
                }
                break;
        }
    }
}

// static void calculate(uint16_t keycode) {
//     switch (keycode) {
//     case KC_KP_PLUS:
//         break;
//     case KC_KP_MINUS:
//         break;
//     case KC_KP_ASTERISK:
//         break;
//     case KC_KP_SLASH:
//         break;
//     case KC_1:
//         break;
//     case KC_2:
//         break;
//     default:
//        break;
//     }
// }


static void render_nyan(void) {
    static const char PROGMEM nyan_cat[ANIM_SIZE] = {
        0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40,
        0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x24, 0x24, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24,
        0x24, 0x24, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24,
        0x24, 0x24, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24,
        0x24, 0x24, 0x92, 0x92, 0x92, 0xf2, 0xb2, 0x32, 0x72, 0xd2, 0xa4, 0xff, 0x00, 0xfc, 0x02, 0x05,
        0x81, 0x01, 0x01, 0x21, 0x03, 0x01, 0xf1, 0x0b, 0x09, 0x11, 0x21, 0x49, 0x42, 0x7c, 0x40, 0x3f,
        0x10, 0x08, 0x08, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x49, 0x49, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49,
        0x49, 0x49, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49,
        0x49, 0x49, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49,
        0x49, 0x49, 0x24, 0x24, 0x24, 0x24, 0x25, 0x27, 0x26, 0xa4, 0x4d, 0x7f, 0x40, 0x8f, 0x92, 0xb0,
        0xa0, 0xa0, 0xa8, 0xa0, 0xa1, 0xbf, 0xa0, 0xc0, 0x80, 0x84, 0xb6, 0xa0, 0xa0, 0xb0, 0xa4, 0xa0,
        0xb4, 0x86, 0x40, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01, 0x01, 0x03,
        0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x03, 0x00, 0x01, 0x02, 0x02,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(nyan_cat, ANIM_SIZE);
}

// static void render_calc(void){
//     oled_write_P(PSTR("Layer: "), false);
//     oled_write_ln_P(PSTR("Calc"), false);

//     char stotal[6];
//     sprintf(stotal, "%lf", calc_total);

//     // char soperator[3];
//     // sprintf(soperator, " %c ", calc_operator);

//     char sinput[6];
//     sprintf(sinput, "%lf", calc_input);

//     oled_write(stotal, false);
//     // oled_write(soperator, false);
//     oled_write(sinput, false);
// }


static void render_grid(void){

    oled_write_P(PSTR("Mode: "), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    oled_write_P(PSTR("Foo "), false);
    oled_write_P(PSTR("Bar "), false);
    oled_write_P(PSTR("Baz "), false);
    oled_write_ln_P(PSTR("Ban"), false);
    
    oled_write_P(PSTR("Foo "), false);
    oled_write_P(PSTR("Bar "), false);
    oled_write_P(PSTR("Baz "), false);
    oled_write_ln_P(PSTR("Ban"), false);

    oled_write_P(PSTR("Foo "), false);
    oled_write_P(PSTR("Bar "), false);
    oled_write_P(PSTR("Baz "), false);
    oled_write_ln_P(PSTR("Ban"), false);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case _CALC:
        //     // main layer - move mouse right (CW) and left (CCW)
        //     if (record->event.pressed) {
        //         calculate(keycode);
        //     }
        //     break;
        case KC_CLOSE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Q);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Q);
            }
            break;
        default:
            return true;
    }
    return true;
}

bool was_numpad = true;

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status

    switch (get_highest_layer(layer_state)) {
        case _NUMPAD:
            if(!was_numpad){
                was_numpad = true;
                oled_init(OLED_ROTATION_0);
            }
            render_nyan();
            // oled_write_ln_P(PSTR("Numpad"), false);
            break;
        case _SUB:
            if(was_numpad){
                was_numpad = false;
                oled_init(OLED_ROTATION_0);
            }
            render_grid();
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }

    // Host Keyboard LED Status
    // led_t led_state = host_keyboard_led_state();
}
#endif