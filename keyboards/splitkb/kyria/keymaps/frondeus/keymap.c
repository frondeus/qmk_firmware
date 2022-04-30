/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "keymap_colemak.h"
#include "sendstring_colemak.h"

enum layers {
    _COLEMAK_DH = 0,
    _NUM,
    _SYM,
    _NAV,
    _FUNCTION,
    _ADJUST,
    _TOGGLE
};


/* #define QWERTY   DF(_QWERTY) */
/* #define QWERDH   DF(_QWERTY_DH) */
//#define COLEMAK  DF(_COLEMAK_DH)

#define SYM_UNDS LT(_SYM, CM_UNDS)
/* #define SYM      MO(_SYM) */
#define NAV      MO(_NAV)
#define NUM      MO(_NUM)
#define FKEYS    MO(_FUNCTION)
#define T_SYM    TG(_SYM)
#define T_NAV    TG(_NAV)
#define T_NUM    TG(_NUM)
#define T_FKEYS  TG(_FUNCTION)
#define ADJUST   MO(_ADJUST)
#define _RESET   TO(_COLEMAK_DH)
#define TOGGLE   TG(_TOGGLE)

#define RS_SCLN MT(MOD_RSFT, CM_SCLN)

#define HOME_A  MT(MOD_LGUI, CM_A)
#define HOME_R  MT(MOD_LALT, CM_R)
#define HOME_S  MT(MOD_LSFT, CM_S)
#define HOME_T  MT(MOD_LCTL, CM_T)
#define HOME_N  MT(MOD_RCTL, CM_N)
#define HOME_E  MT(MOD_RSFT, CM_E)
#define HOME_I  MT(MOD_LALT, CM_I)
#define HOME_O  MT(MOD_RGUI, CM_O)

enum combos {
    AE_DK_ASH,   // Æ

    ECO_PL_EOGO, // Ę
    ACO_PL_AOGO, // Ą
    OQU_PL_OACU, // Ó
    SQU_PL_SACU, // Ś
    ZQU_PL_ZACU, // Ź
    CQU_PL_CACU, // Ć
    NQU_PL_NACU, // Ń
    UQU_DK_UACU, // Ú
    YQU_DK_YACU, // Ý
    AQU_DK_AACU, // Á
    EQU_DK_EACU, // É
    IQU_DK_IACU, // Í

    ZDO_PL_ZDOT, // Ż
    ADO_DK_ACIR, // Å

    LSL_PL_LSTR, // Ł
    OSL_DK_ODIA, // Ø

    YU_YOU,

    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM dk_ash_combo[] =  {HOME_A, HOME_E,  COMBO_END};
const uint16_t PROGMEM pl_eogo_combo[] = {HOME_E, CM_COMM, COMBO_END};
const uint16_t PROGMEM pl_aogo_combo[] = {HOME_A, CM_COMM, COMBO_END};
const uint16_t PROGMEM pl_oacu_combo[] = {HOME_O, CM_QUOT, COMBO_END};
const uint16_t PROGMEM pl_sacu_combo[] = {HOME_S, CM_QUOT, COMBO_END};
const uint16_t PROGMEM pl_zacu_combo[] = {CM_Z,   CM_QUOT, COMBO_END};
const uint16_t PROGMEM pl_cacu_combo[] = {CM_C,   CM_QUOT, COMBO_END};
const uint16_t PROGMEM pl_nacu_combo[] = {HOME_N, CM_QUOT, COMBO_END};
const uint16_t PROGMEM dk_uacu_combo[] = {CM_U,   CM_QUOT, COMBO_END};
const uint16_t PROGMEM dk_yacu_combo[] = {CM_Y,   CM_QUOT, COMBO_END};
const uint16_t PROGMEM dk_aacu_combo[] = {HOME_A, CM_QUOT, COMBO_END};
const uint16_t PROGMEM dk_eacu_combo[] = {HOME_E, CM_QUOT, COMBO_END};
const uint16_t PROGMEM dk_iacu_combo[] = {HOME_I, CM_QUOT, COMBO_END};
const uint16_t PROGMEM pl_zdot_combo[] = {CM_Z,   CM_DOT,  COMBO_END};
const uint16_t PROGMEM dk_acir_combo[] = {HOME_A, CM_DOT,  COMBO_END};
const uint16_t PROGMEM pl_lstr_combo[] = {CM_L,   HOME_S,  COMBO_END};
const uint16_t PROGMEM dk_odia_combo[] = {HOME_O, HOME_S,  COMBO_END};
const uint16_t PROGMEM you_combo[]     = {CM_U,   CM_Y,    COMBO_END};

combo_t key_combos[] = {
    [AE_DK_ASH] = COMBO_ACTION(dk_ash_combo),
    [ECO_PL_EOGO] = COMBO_ACTION(pl_eogo_combo), // Ę
    [ACO_PL_AOGO] = COMBO_ACTION(pl_aogo_combo), // Ą
    [OQU_PL_OACU] = COMBO_ACTION(pl_oacu_combo), // Ó
    [SQU_PL_SACU] = COMBO_ACTION(pl_sacu_combo), // Ś
    [ZQU_PL_ZACU] = COMBO_ACTION(pl_zacu_combo), // Ź
    [CQU_PL_CACU] = COMBO_ACTION(pl_cacu_combo), // Ć
    [NQU_PL_NACU] = COMBO_ACTION(pl_nacu_combo), // Ń
    [UQU_DK_UACU] = COMBO_ACTION(dk_uacu_combo), // Ú
    [YQU_DK_YACU] = COMBO_ACTION(dk_yacu_combo), // Ý
    [AQU_DK_AACU] = COMBO_ACTION(dk_aacu_combo), // Á
    [EQU_DK_EACU] = COMBO_ACTION(dk_eacu_combo), // É
    [IQU_DK_IACU] = COMBO_ACTION(dk_iacu_combo), // Í

    [ZDO_PL_ZDOT] = COMBO_ACTION(pl_zdot_combo), // Ż
    [ADO_DK_ACIR] = COMBO_ACTION(dk_acir_combo), // Å

    [LSL_PL_LSTR] = COMBO_ACTION(pl_lstr_combo), // Ł
    [OSL_DK_ODIA] = COMBO_ACTION(dk_odia_combo), // Ø
    [YU_YOU] = COMBO_ACTION(you_combo),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Bksp   | Q    |  W   |  F   | P    | B    |                              | J    | L    | U    | Y    | ?    | Bksp   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Tab    | A    | R    | S    | T    | G    |                              | M    | N    | E    | I    | O    | Ent    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | AltGrp | Z    | X    | C    | D    | V    | ADJ  |      |  |      | CAPS | '    | K    | H    | ,    | .    | :      |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | MUTE | Esc  | Spc  |      |      |  |      | _    | ;    |      | TOGL |
 *                        |      |      |      | NUM  | NAV  |  | FKEY | SYM  | Rsft |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */


    [_COLEMAK_DH] = LAYOUT(
     KC_BSPC , CM_Q ,  CM_W   ,  CM_F  ,   CM_P ,   CM_B ,                                        CM_J,  CM_L  ,  CM_U , CM_Y   ,CM_QUES, KC_BSPC,
     KC_TAB  ,HOME_A,  HOME_R ,  HOME_S,  HOME_T,   CM_G ,                                        CM_M,  HOME_N, HOME_E, HOME_I ,HOME_O,  KC_ENT,
     KC_RALT , CM_Z ,  CM_X   ,  CM_C  ,   CM_D ,   CM_V , ADJUST ,_______,     _______, KC_CAPS, CM_QUOT,CM_K ,  CM_H , CM_COMM,CM_DOT,  CM_COLN,
                                 KC_MUTE,KC_ESC , KC_SPC , NUM    , NAV   ,     FKEYS  ,SYM_UNDS, RS_SCLN,_______, TOGGLE
    ),

    [_TOGGLE] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, T_NUM  , T_NAV  , T_FKEYS, T_SYM  , _______, _______, _RESET
    ),
/*
 * Sym Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      | <    | >    | |    |                              |      | -    | +    | *    | !    |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | (    | )    | {    | }    | /    |                              | @    | %    | =    | ~    | `    |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      | [    | ]    | \    |      |      |  |      |      | "    | #    | ^    | &    | $    |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      _______, _______, _______, CM_LABK, CM_RABK, CM_PIPE,                                     _______, CM_MINS, CM_PLUS, CM_ASTR, CM_EXLM, _______,
      _______, CM_LPRN, CM_RPRN, CM_LCBR, CM_RCBR, CM_SLSH,                                     CM_AT  , CM_PERC, CM_EQL , CM_TILD, CM_GRV , _______,
      _______, _______, _______, CM_LBRC, CM_RBRC, CM_BSLS, _______, _______, _______, _______, CM_DQUO, CM_HASH, CM_CIRC, CM_AMPR, CM_DLR , _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home | PgDn | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Shift| Ctrl |      |                              |  ←   |   ↓  |   ↑  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,KC_PAUSE, _______, KC_PSCR,
                                 KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Num Layer: Numbers
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | /    | 1    | 2    | 3    | +    |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | 0    | 4    | 5    | 6    | -    |                              |      | Ctrl | Shift| Alt  | GUI  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | *    | 7    | 8    | 9    | =    |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      _______, CM_SLSH, CM_1   , CM_2   , CM_3   , CM_PLUS,                                     _______, _______, _______, _______, _______, _______,
      _______, CM_0   , CM_4   , CM_5   , CM_6   , CM_MINS,                                     _______, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, _______,
      _______, CM_ASTR, CM_7   , CM_8   , CM_9   , CM_EQL , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F12 |  F1  |  F2  |  F3  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F10 |  F4  |  F5  |  F6  |      |                              |      | Ctrl | Shift|  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F11 |  F7  |  F8  |  F9  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_F12,  KC_F1 ,  KC_F2 ,  KC_F3 , _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F10,  KC_F4 ,  KC_F5 ,  KC_F6 , _______,                                     _______, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, _______,
      _______,  KC_F11,  KC_F7 ,  KC_F8 ,  KC_F9 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_SYM, CM_UNDS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(CM_UNDS);
                return false;
            }
            break;
    }
    return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer((layer_state&(~(1<<_TOGGLE)))|default_layer_state)) {
        case _NAV:
            if (index == 1) {
                // Arrows
                if (clockwise) {
                    tap_code(KC_UP);
                } else {
                    tap_code(KC_DOWN);
                }
            }
            break;
        default:
            if (index == 0) {
                // Volume control
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            } else if (index == 1) {
                // Page up/Page down
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
            }
            break;
    }
    return false;
}
#endif

struct AltKey {
    uint16_t prefix;
    uint16_t key;
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    uint8_t mod_state = get_mods();

    struct AltKey keys[] = {
        [AE_DK_ASH] = { KC_NO, CM_Z },

        [ECO_PL_EOGO] = { CM_G,  CM_E },
        [ACO_PL_AOGO] = { CM_G,  CM_A },
        [OQU_PL_OACU] = { CM_T,  CM_O },
        [SQU_PL_SACU] = { CM_T,  CM_S },
        [ZQU_PL_ZACU] = { CM_T,  CM_Z },
        [CQU_PL_CACU] = { CM_T,  CM_C },
        [NQU_PL_NACU] = { CM_T,  CM_N },
        [UQU_DK_UACU] = { CM_T,  CM_U },
        [YQU_DK_YACU] = { CM_T,  CM_Y },
        [AQU_DK_AACU] = { CM_T,  CM_A },
        [EQU_DK_EACU] = { CM_T,  CM_E },
        [IQU_DK_IACU] = { CM_T,  CM_I },

        [ZDO_PL_ZDOT] = { CM_DOT,CM_Z },
        [ADO_DK_ACIR] = { KC_NO, CM_W },

        [LSL_PL_LSTR] = { KC_NO, CM_L },
        [OSL_DK_ODIA] = { KC_NO, CM_P },
    };

    if (combo_index <= OSL_DK_ODIA) {
        struct AltKey key = keys[combo_index];
        if (pressed) {
            if (key.prefix != KC_NO) {
                clear_mods();
                tap_code16(RALT(key.prefix));
                set_mods(mod_state);

                tap_code16(key.key);
            }
            else {
                tap_code16(RALT(key.key));
            }
        }
        return;
    }
    if (pressed) {
        switch(combo_index) {
            case YU_YOU:
                send_string("you");
                break;
        }
    }
}
