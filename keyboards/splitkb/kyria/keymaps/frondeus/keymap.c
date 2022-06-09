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
    _COLEMAK_DH = 0, // Default layer - requires Colemak (Not DH tho!) installed and active in OS
    _COLEMAK_EMU, // Colemak emulated, for OS with classic QWERTY layout. Handy in BIOS and stuff. Does not support polish/danish characters
    _QWERTY,
    _NUM, // Numbers
    _SYM, // Symbols
    _NAV, // Navigation, arrows
    _FUNCTION, // F1-F12
    _MOUSE,
    _I3, // I3wm layer
    _ADJUST, // Change RGB, change layout
    _TOGGLE // Makes some layers toggable so you can write without held thumb
};


#define COLEMAK   DF(_COLEMAK_DH)
#define COLEMU   DF(_COLEMAK_EMU)
#define QWERTY   DF(_QWERTY)
/* #define QWERDH   DF(_QWERTY_DH) */
//#define COLEMAK  DF(_COLEMAK_DH)

/* #define SYM      MO(_SYM) */
#define NAV      MO(_NAV)
#define NUM      MO(_NUM)
#define FKEYS    MO(_FUNCTION)
#define I3       LM(_I3, MOD_LGUI)
#define T_SYM    TG(_SYM)
#define T_NAV    TG(_NAV)
#define T_NUM    TG(_NUM)
#define T_I3     TG(_I3)
#define T_FKEYS  TG(_FUNCTION)
#define ADJUST   MO(_ADJUST)
#define _RESET   TO(_COLEMAK_DH)
#define TOGGLE   TG(_TOGGLE)
#define MOUSE    TG(_MOUSE)

#define ESC_FN   LT(_FUNCTION,KC_ESC)
#define RS_COLN  MT(MOD_RSFT, CM_COLN)
#define SYM_UNDS LT(_SYM,     CM_UNDS)
#define HOME_A   MT(MOD_LGUI, CM_A)
#define HOME_R   MT(MOD_LALT, CM_R)
#define HOME_S   MT(MOD_LSFT, CM_S)
#define HOME_T   MT(MOD_LCTL, CM_T)
#define HOME_N   MT(MOD_RCTL, CM_N)
#define HOME_E   MT(MOD_RSFT, CM_E)
#define HOME_I   MT(MOD_LALT, CM_I)
#define HOME_O   MT(MOD_RGUI, CM_O)

#define CE_RS_COLN  MT(MOD_RSFT, KC_COLN)
#define CE_SYM_UNDS LT(_SYM,     KC_UNDS)
#define CE_H_A   MT(MOD_LGUI, KC_A)
#define CE_H_R   MT(MOD_LALT, KC_R)
#define CE_H_S   MT(MOD_LSFT, KC_S)
#define CE_H_T   MT(MOD_LCTL, KC_T)
#define CE_H_N   MT(MOD_RCTL, KC_N)
#define CE_H_E   MT(MOD_RSFT, KC_E)
#define CE_H_I   MT(MOD_LALT, KC_I)
#define CE_H_O   MT(MOD_RGUI, KC_O)

#define EMACS    RSG(KC_QUOT)

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
    YUR_YOUR,
    YURA_YOUARE,
    IM_IAM,
    IV_IVE,
    ID_ID,
    IL_ILL,
    WHS_WHOS,
    ITS_ITS,
    NT_NT,
    THD_THEYD,
    THV_THEYVE,

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
const uint16_t PROGMEM your_combo[]    = {CM_U,   CM_Y, HOME_R, COMBO_END};
const uint16_t PROGMEM youare_combo[]  = {CM_U, CM_Y, HOME_R, HOME_A, COMBO_END};
const uint16_t PROGMEM iam_combo[]     = {HOME_I, CM_M, COMBO_END};
const uint16_t PROGMEM ive_combo[]     = {HOME_I, CM_V, COMBO_END};
const uint16_t PROGMEM id_combo[]      = {HOME_I, CM_D, COMBO_END};
const uint16_t PROGMEM ill_combo[]     = {HOME_I, CM_L, COMBO_END};
const uint16_t PROGMEM whos_combo[]    = {CM_W, CM_H, HOME_S, COMBO_END};
const uint16_t PROGMEM its_combo[]     = {HOME_I, HOME_T, HOME_S, COMBO_END};
const uint16_t PROGMEM nt_combo[]      = {HOME_N, HOME_T, COMBO_END};
const uint16_t PROGMEM theyd_combo[]   = {HOME_T, CM_H, CM_D, COMBO_END};
const uint16_t PROGMEM theyve_combo[]  = {HOME_T, CM_H, CM_V, COMBO_END};

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
    [YUR_YOUR] = COMBO_ACTION(your_combo),
    [YURA_YOUARE] = COMBO_ACTION(youare_combo),
    [IM_IAM] = COMBO_ACTION(iam_combo),
    [IV_IVE] = COMBO_ACTION(ive_combo),
    [ID_ID] = COMBO_ACTION(id_combo),
    [IL_ILL] = COMBO_ACTION(ill_combo),
    [WHS_WHOS] = COMBO_ACTION(whos_combo),
    [ITS_ITS] = COMBO_ACTION(its_combo),
    [NT_NT] = COMBO_ACTION(nt_combo),
    [THD_THEYD] = COMBO_ACTION(theyd_combo),
    [THV_THEYVE] = COMBO_ACTION(theyve_combo),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Delete | Q    |  W   |  F   | P    | B    |                              | J    | L    | U    | Y    | !    | Bksp   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Tab    | A    | R    | S    | T    | G    |                              | M    | N    | E    | I    | O    | Ent    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | AltGrp | Z    | X    | C    | D    | V    | CAPS | ADJ  |  |      |MOUSE | '    | K    | H    | ,    | .    | :      |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | Esc  | Spc  |      |      |  |      |      | _    |      | TOGL |
 *                        | Tab+-| FKEY |      | NUM  |      |  |      | NAV  | SYM  | I3   |Scrl+-|
 *                        `----------------------------------'  `----------------------------------'
 */

    [_COLEMAK_DH] = LAYOUT(
     KC_DEL  , CM_Q ,  CM_W   ,  CM_F  ,   CM_P ,   CM_B ,                                        CM_J,  CM_L  ,  CM_U , CM_Y   ,CM_EXLM, KC_BSPC,
     KC_TAB  ,HOME_A,  HOME_R ,  HOME_S,  HOME_T,   CM_G ,                                        CM_M,  HOME_N, HOME_E, HOME_I ,HOME_O,  KC_ENT,
     KC_RALT , CM_Z ,  CM_X   ,  CM_C  ,   CM_D ,   CM_V , KC_CAPS,ADJUST ,     _______, MOUSE  , CM_QUOT,CM_K ,  CM_H , CM_COMM,CM_DOT,  CM_COLN,
                                 _______,ESC_FN , KC_SPC , NUM    ,_______,     _______, NAV , SYM_UNDS,    I3 , TOGGLE
    ),

    [_TOGGLE] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, T_FKEYS, _______, T_NUM  , _______, _______, T_NAV  , T_SYM  ,    T_I3, _RESET
    ),
/*
 * Sym Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      | <    | >    | |    |                              |      | +    | %    | ^    | ?    |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | (    | )    | {    | }    | /    |                              | ~    | -    | =    | @    | #    |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      | [    | ]    | \    |      |      |  |      |      | "    | `    | *    | &    | $    | ;      |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      _______, _______, _______, CM_LABK, CM_RABK, CM_PIPE,                                     _______, CM_PLUS, CM_PERC, CM_CIRC, CM_QUES, _______,
      _______, CM_LPRN, CM_RPRN, CM_LCBR, CM_RCBR, CM_SLSH,                                     CM_TILD, CM_MINS, CM_EQL , CM_AT,   CM_HASH, _______,
      _______, _______, _______, CM_LBRC, CM_RBRC, CM_BSLS, _______, _______, _______, _______, CM_DQUO, CM_GRV , CM_ASTR, CM_AMPR, CM_DLR , CM_SCLN,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Mouse Layer
 *
 * ,------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |  M↑  |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |  M←  |  M↓  |  M→  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      | MOUSE|      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |Middle| Left | Right|      |Scroll|
 *                        |      |      |      |      |      |  | Click| Click| Click|      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MOUSE] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, KC_MS_U, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, MOUSE  , _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2, _______, _______
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |  ↑   | End  |Insert|        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Shift| Ctrl |      |                              | PdDn |   ←  |  ↓   |   →  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |PAUSE |      |      |      |      |  |      |      |      |      | MUTE |
 *                        |Song+-|      |      |      |      |  |      |      |      |      |Vol+- |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS , _______,
      _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 KC_MPLY, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE
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
 * | PrtScr |  F12 |  F1  |  F2  |  F3  |      |                              |      |      |      |      |      |        |
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
      KC_PSCR,  KC_F12,  KC_F1 ,  KC_F2 ,  KC_F3 , _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F10,  KC_F4 ,  KC_F5 ,  KC_F6 , _______,                                     _______, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, _______,
      _______,  KC_F11,  KC_F7 ,  KC_F8 ,  KC_F9 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * I3 Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |Lock    | 0    | 6    | 7    | 8    | 9    |                              | 5    | 1    | Up   | 2    | 3    | Quit   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |Parent|LAlt  |LShift|LCtrl |      |                              |Fullsc|Left  |Down  |Right | 4    |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |Child |      |      |      |      |      |      |  |      |      |NxtFre|Horizo|Vertic|Layout|Resize|        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      | Run  |      |      |  |      |      |      |      |      |
 *                        |Work+-|      |      |      |      |  |      |      |      |      |Win+- |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_I3] = LAYOUT(
      CM_Q   , KC_0   , KC_6   , KC_7   , KC_8   , KC_9   ,                                     KC_5   , KC_1   , CM_K   , KC_2   , KC_3   , S(CM_Q),
      _______, CM_A   , KC_LALT, KC_LSFT, KC_LCTL, EMACS  ,                                     CM_F   , CM_H   , CM_J   , CM_L   , KC_4   , _______,
      _______, CM_Z   , _______, _______, _______, _______, _______, _______, _______, _______, CM_GRV , CM_G   , CM_V   , CM_T   , CM_R   , _______,
                                 _______, _______, _______, _______, _______, _______, _______, KC_RSFT, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | Colm |Colemu|Qwerty|      |      |                              |      |      |      |      |      |        |
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
      _______, COLEMAK,  COLEMU, QWERTY , _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Base Layer: Colemak emulated
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Bksp   | Q    |  W   |  F   | P    | B    |                              | J    | L    | U    | Y    | ?    | Bksp   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Tab    | A    | R    | S    | T    | G    |                              | M    | N    | E    | I    | O    | Ent    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | AltGrp | Z    | X    | C    | D    | V    | ADJ  |      |  |      | CAPS | '    | K    | H    | ,    | .    | ;      |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | MUTE | Esc  | Spc  |      |      |  |      |      | _    |      | TOGL |
 *                        | Vol+-| FKEY |      | NUM  |      |  |      | NAV  | SYM  | I3   |Scrl+-|
 *                        `----------------------------------'  `----------------------------------'
 */


    [_COLEMAK_EMU] = LAYOUT(
     KC_BSPC , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                        KC_J,  KC_L  ,  KC_U , KC_Y   ,KC_QUES, KC_BSPC,
     KC_TAB  ,CE_H_A,  CE_H_R ,  CE_H_S,  CE_H_T,   KC_G ,                                        KC_M,  CE_H_N, CE_H_E, CE_H_I ,CE_H_O,  KC_ENT,
     KC_RALT , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , ADJUST ,_______,     _______, KC_CAPS, KC_QUOT,KC_K ,  KC_H , KC_COMM,KC_DOT,  KC_SCLN,
                                 KC_MUTE, ESC_FN, KC_SPC , NUM    ,_______,     FKEYS  ,NAV, CE_SYM_UNDS,   I3 , TOGGLE
    ),
/*
 * Base Layer: QWERTY native for gaming
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Tab    | Q    |  W   | E    | R    | T    |                              | Y    | U    | I    | O    | P    | Bksp   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LShift | A    | S    | D    | F    | G    |                              | ;    | H    | J    | K    | L    | Ent    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCtrl  | Z    | X    | C    | V    | B    | ADJ  |      |  |      | CAPS | '    | N    | M    | ,    | .    | RAlt   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | MUTE | Esc  | Spc  |      |      |  |      | _    | :    |      | TOGL |
 *                        | Vol+-| FKEY |      | NUM  |      |  |      | SYM  | Rsft | I3   |Scrl+-|
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_TAB , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,  KC_U  ,  KC_I , KC_O   ,KC_P,    KC_BSPC,
     KC_LSFT, KC_A,   KC_S   ,  KC_D,     KC_F,    KC_G ,                                     KC_SCLN,  KC_H  ,  KC_J , KC_K   ,KC_L,    KC_ENT,
     KC_LCTL, KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , ADJUST ,_______,     _______, KC_CAPS, KC_QUOT,KC_N ,  KC_M , KC_COMM,KC_DOT,  KC_RALT,
                                KC_MUTE,ESC_FN , KC_SPC , NUM    ,_______,     FKEYS  ,CE_SYM_UNDS, CE_RS_COLN,    I3 , TOGGLE
    ),

// /*
//  * Layer template
//  *
//  * ,------------------------------------------.                              ,-------------------------------------------.
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
        // case MT(MOD_RSFT, CM_COLN):
        //     if (record->tap.count && record->event.pressed) {
        //         tap_code16(CM_COLN);
        //         return false;
        //     }
        //     break;
        // case MT(MOD_RSFT, KC_COLN):
        //     if (record->tap.count && record->event.pressed) {
        //         tap_code16(KC_COLN);
        //         return false;
        //     }
        //     break;
    }
    return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer((layer_state&(~(1<<_TOGGLE)))|default_layer_state)) {
        case _NAV:
            if (index == 0) {
                // Songs
                if (clockwise) {
                    tap_code16(KC_MEDIA_NEXT_TRACK);
                } else {
                    tap_code16(KC_MEDIA_PREV_TRACK);
                }
            } else
            if (index == 1) {
                // Volume control
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            }
            break;
        case _I3:
            if (index == 0) {
                // Workspace in output
                if (clockwise) {
                    tap_code16(C(KC_TAB));
                }
                else {
                    tap_code16(S(C(KC_TAB)));
                }
            }
            else if (index == 1) {
                if (clockwise) {
                    tap_code(CM_L);
                } else {
                    tap_code(CM_H);
                }
            }
        default:
            if (index == 0) {
                // Tabs in browser
                if (clockwise) {
                    tap_code16(C(KC_TAB));
                }
                else {
                    tap_code16(S(C(KC_TAB)));
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
            case YUR_YOUR:
                send_string("your");
                break;
            case YURA_YOUARE:
                send_string("you're");
                break;
            case IM_IAM:
                send_string("I'm");
                break;
            case IV_IVE:
                send_string("I've");
                break;
            case ID_ID:
                send_string("I'd");
                break;
            case IL_ILL:
                send_string("I'll");
                break;
            case WHS_WHOS:
                send_string("who's");
                break;
            case ITS_ITS:
                send_string("it's");
                break;
            case NT_NT:
                send_string("n't");
                break;
            case THD_THEYD:
                send_string("they'd");
                break;
            case THV_THEYVE:
                send_string("they've");
                break;
        }
    }
}
