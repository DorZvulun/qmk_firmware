/*
 * This is my configured keymap, based on rgb_default, without COLEMAK and VIA support disabled in rules.mk because it caused errors with default layer
 *
 * THIS FILE IS READ ONLY
 */

/* Copyright 2021 Dane Evans
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
// SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s, Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv, Override)

// Light combinations
#define SET_INDICATORS(hsv)                                 \
    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, { \
        35 + 0, 1, hsv                                      \
    }
#define SET_UNDERGLOW(hsv) \
    {1, 6, hsv}, {         \
        35 + 1, 6, hsv     \
    }
#define SET_NUMPAD(hsv)  \
    { 35 + 18, 14, hsv } \
    // {35 + 22, 3, hsv},
    // {35 + 27, 3, hsv}
#define SET_NUMROW(hsv)                                                               \
    {11, 2, hsv}, {21, 2, hsv}, {31, 2, hsv}, {35 + 11, 2, hsv}, {35 + 21, 2, hsv}, { \
        35 + 31, 2, hsv                                                               \
    }
#define SET_INNER_COL(hsv) \
    {32, 4, hsv}, {        \
        35 + 32, 4, hsv    \
    }
#define SET_OUTER_COL(hsv)                         \
    {8, 4, hsv}, {17, 2, hsv}, {35 + 8, 4, hsv}, { \
        35 + 17, 2, hsv                            \
    }
#define SET_THUMB_CLUSTER(hsv)                                                      \
    {8, 1, hsv}, {17, 2, hsv}, {26, 2, hsv}, {35 + 8, 1, hsv}, {35 + 17, 2, hsv}, { \
        35 + 26, 2, hsv                                                             \
    }
#define SET_RIGHT_ARROW_STACK(hsv) \
    {21, 1, hsv}, {23, 2, hsv}, {  \
        31, 1, hsv                 \
    }
#define SET_LEFT_ARROW_STACK(hsv)           \
    {21 + 11, 1, hsv}, {23 + 11, 2, hsv}, { \
        31 + 11, 1, hsv                     \
    }
#define SET_LAYER_ID(hsv)                                                                                                                                                                                                                                                            \
    /*ind*/ {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, /*ind*/ {35 + 0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, /*und_glw*/ {1, 6, hsv}, /*und_glw*/ {35 + 1, 6, hsv}, /*ctrl*/ {7, 4, hsv}, /*ctrl*/ {35 + 7, 4, hsv}, /*cmd_alt*/ {26, 2, hsv}, /*cmd_alt*/ { \
        35 + 26, 2, hsv                                                                                                                                                                                                                                                              \
    }

enum sofle_layers /**/
{
    _DEFAULTS  = 0,
    _QWERTY    = 0,
    _COLEMAKDH = 1,
    _LOWER     = 2,
    _RAISE     = 3,
    _ADJUST    = 4,
    _NUMPAD    = 5,
    _SWITCH    = 6,
    _CONTROLS  = 7
};

enum custom_keycodes /**/
{
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAKDH,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_D_MUTE,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | CAPS |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------| MUTE  |    | PLAY  |------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | CTRL | ALT  |SUPER | LOWER| / Enter /       \Space \  |RAISE |SUPER | ALT  | CTRL |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `-----------------------------------'           '------''---------------------------'
     */
    [_QWERTY] = LAYOUT(
        //,------------------------------------------------.                    ,---------------------------------------------------.
        /**/ QK_GESC, LT(_QWERTY, KC_1), LT(_COLEMAKDH, KC_2), LT(_RAISE, KC_3), LT(_ADJUST, KC_4), LT(_NUMPAD, KC_5), /**/ LT(_SWITCH, KC_6), KC_7, KC_8, KC_9, KC_0, KC_GRV,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        /**/ LT(_NUMPAD, KC_TAB), KC_Q, KC_W, KC_E, /*                           */ KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        /**/ KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, /*                           */ KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        /**/ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, /*      */ KC_MUTE, /**/ KC_MPLY, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        /*             */ KC_LCTL, KC_LALT, KC_LGUI, KC_LOWER, KC_ENT, /**/ KC_SPC, KC_RAISE, KC_RGUI, KC_RALT, KC_RCTL
        //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
        ),
    /*
     * COLEMAK-DH
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | CAPS |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
     * |------+------+------+------+------;+------|  MUTE |    | PLAY  |------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |LShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | CTRL | ALT  |SUPER | LOWER| / Enter /       \Space \  |RAISE |SUPER | ALT  | CTRL |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'            '------''---------------------------'
     */
    [_COLEMAKDH] = LAYOUT(
        //,------------------------------------------------.                    ,---------------------------------------------------.
        /**/ QK_GESC, LT(_QWERTY, KC_1), LT(_LOWER, KC_2), LT(_RAISE, KC_3), LT(_ADJUST, KC_4), LT(_NUMPAD, KC_5), /**/ LT(_SWITCH, KC_6), KC_7, KC_8, KC_9, KC_0, KC_GRV,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        /**/ LT(_NUMPAD, KC_TAB), KC_Q, KC_W, KC_F, KC_P, KC_B, /**/ KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        /**/ KC_CAPS, KC_A, KC_R, KC_S, KC_T, KC_G, /*       */ KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        /**/ KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, /**/ KC_MUTE, /**/ KC_MPLY, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        /*            */ KC_LCTL, KC_LALT, KC_LGUI, KC_LOWER, KC_ENT, /**/ KC_SPC, KC_RAISE, KC_RGUI, KC_RALT, KC_RCTL
        //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
        ),

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | trans|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  -_  |  +=  | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |13l_win|23r_win|top_win|max_win|  0   | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | trans|   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   <- |lft_win|bot_win|rgt_win|     |  \|  |
     * |------+------+------+------+------+------|  MUTE |    | PLAY  |------+------+------+------+------+------|
     * | trans|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  | 1/4  |  4/4 |cntr_win|Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | CTRL | ALT  |  CMD | LOWER| / Enter /       \Space \  |RAISE | CMD  | ALT  | CTRL |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_LOWER] = LAYOUT(
        //,------------------------------------------------.                    ,---------------------------------------------------.
        /**/ _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, /*                      */ KC_F6, KC_F7, KC_F8, KC_MINS, KC_EQL, KC_F11,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        /**/ KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, /*                            */ LCA(KC_D), LCA(KC_T), LCA(KC_UP), LCA(KC_ENT), KC_0, KC_F12,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        /**/ _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, /*               */ KC_LEFT, LCA(KC_COMM), LCA(KC_DOWN), LCA(KC_DOT), KC_NO, KC_SLSH,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        /**/ _______, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, /**/ _______, _______, /**/ KC_LBRC, KC_RBRC, LCA(KC_1), LCA(KC_4), LCA(KC_SLSH), KC_RSFT,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        /**/ _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______
        //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
        ),
    /* RAISE
     * ,----------------------------------------.                     ,-----------------------------------------.
     * |   ~  |      |      |      |      |      |                    |      |      |      |      |      |  \   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  | Ins  | Pscr | Menu |      |      |                    | PGUP | PWrd |  Up  | NWrd | DLine| del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Caps | LAt  |tab_rgt|   |tab_lft| Caps |-------.    ,-------| PGDN | Left | Down | Rigth|  Del |   \  |
     * |------+------+------+------+------+------|  MUTE |    | PLAY  |------+------+------+------+------+------|
     * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | CTRL | ALT  |  CMD | LOWER| / Enter /       \Space \  |RAISE | CMD  | ALT  | CTRL |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_RAISE] = LAYOUT(
        //,------------------------------------------------.                    ,---------------------------------------------------.
        /**/ KC_TILD, _______, _______, _______, _______, _______, /*           */ _______, _______, _______, _______, _______, KC_BSLS,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        /**/ _______, KC_INS, KC_PSCR, KC_APP, KC_NO, KC_NO, /*                 */ KC_PGUP, LALT(KC_LEFT), KC_UP, LALT(KC_RGHT), LGUI(KC_BSPC), KC_DEL,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        /**/ _______, KC_LALT, LAG(KC_LEFT), KC_NO, LAG(KC_RGHT), KC_CAPS, /*             */ KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_BSLS,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        /**/ _______, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), XXXXXXX, _______, _______, KC_LSTRT, XXXXXXX, KC_LEND, XXXXXXX, _______, KC_LSFT,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        /*           */ _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______
        //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
        ),
    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |QWERTY| bri_u|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |QK_BOOT|     |      |      |      |BL_TOG|                    |      |      |      |      |      | bri_d|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |RGB_TOG|hue^ |sat ^ | bri ^|      |BL_MOD|-------.    ,-------|      |desk <|      |desk >|      |      |
     * |------+------+------+------+------+------|  MUTE |    | PLAY  |------+------+------+------+------+------|
     * |rgb_mod|hue dn|sat d|bri dn|      |BL_BRT|-------|    |-------|      | PREV | PLAY | NEXT |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | CTRL | ALT  |  CMD | LOWER| / Enter /       \Space \  |RAISE | CMD  | ALT  | CTRL |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_ADJUST] = LAYOUT(
        //,------------------------------------------------.                    ,---------------------------------------------------.
        EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QWERTY, KC_BRIU,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, BL_STEP, KC_NO, C(KC_LEFT), KC_NO, C(KC_RGHT), XXXXXXX, XXXXXXX,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, BL_BRTG, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
        ),
    /* NUMPAD
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | trans|      |      |      |      |      |                    |      |   7  |   8  |   9  |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |      |      |      |      |      |                    |   ^  |   4  |   5  |   6  |   *  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | trans|      |      |      |      |      |-------.    ,-------|   -  |   1  |   2  |   3  |   \  |   |  |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * | trans|      |      |      |      |      |-------|    |-------|   +  |   0  |   .  |EQ/Entr|     | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | CTRL | ALT  |  CMD | LOWER| / Enter /       \Space \  |RAISE | CMD  | ALT  | CTRL |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_NUMPAD] = LAYOUT(
        //,------------------------------------------------.                    ,---------------------------------------------------.
        /**/ _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*          */ _______, KC_P7, KC_P8, KC_P9, KC_ASTR, XXXXXXX,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*          */ KC_CIRC, KC_P4, KC_P5, KC_P6, KC_EQL, KC_BSPC,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /*          */ KC_MINS, KC_P1, KC_P2, KC_P3, KC_SLSH, KC_PIPE,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_PLUS, KC_P0, KC_PDOT, KC_ENT, _______, /**/ _______,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        /*           */ _______, OSM(MOD_MEH), _______, _______, _______, _______, _______, _______, _______, _______
        //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
        ),

    /* SWITCH
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      | low  | raise| adj  |                    |numpad|      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |QWERTY|WinMod|      |      |      |                    |      |      |      |      |      |QK_BOOT |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |EEP_RST|
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * | SLEEP|      |COLEMAKDH|   |      |      |-------|    |-------|      |MacMod|      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | CTRL | ALT  |  CMD | LOWER| / Enter /       \Space \  |RAISE | CMD  | ALT  | CTRL |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    // layer switcher
    [_SWITCH] = LAYOUT(
        //,------------------------------------------------.                    ,---------------------------------------------------.
        /**/ _______, TO(_QWERTY), TO(_COLEMAKDH), TO(2), TO(3), TO(4), /*            */ TO(5), TO(6), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        /**/ XXXXXXX, KC_QWERTY, AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX, /*                        */ XXXXXXX, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT,
        //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        /**/ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /*                      */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, EEP_RST,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        /**/ KC_SYSTEM_SLEEP, KC_NO, KC_NO, KC_COLEMAKDH, KC_NO, KC_NO, /**/ KC_NO, KC_NO, /**/ KC_NO, AG_NORM, KC_NO, KC_NO, KC_NO, KC_NO,
        //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
        /*             */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /*              */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
        //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/

        ),
};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[]    = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_RED)

   );
const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_PINK));

// _NUM,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_TEAL)

);
// _SYMBOL,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_BLUE)

);
// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_PURPLE));

//_NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_INDICATORS(HSV_ORANGE), SET_UNDERGLOW(HSV_ORANGE), SET_NUMPAD(HSV_BLUE), {7, 4, HSV_ORANGE}, {25, 2, HSV_ORANGE}, {35 + 6, 4, HSV_ORANGE}, {35 + 25, 2, HSV_ORANGE});
// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_GREEN), SET_NUMROW(HSV_GREEN));

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(

    layer_qwerty_lights,
    layer_num_lights, // overrides layer 1
    layer_symbol_lights, layer_command_lights, layer_numpad_lights,
    layer_switcher_lights, // Overrides other layers
    layer_colemakdh_lights);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state, _QWERTY));
    rgblight_set_layer_state(7, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state, _COLEMAKDH));

    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NUMPAD));
    rgblight_set_layer_state(5, layer_state_cmp(state, _SWITCH));
    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    rgblight_mode(10); // haven't found a way to set this in a more useful way
}
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Dor\nZvln"), false);

    oled_write_ln_P(PSTR(""), false);

    // snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        // case _COLEMAK:
        //     oled_write_ln_P(PSTR("Clmk"), false);
        //     break;
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("CmkDH"), false);
            break;

        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        // case _COLEMAK:
        case _QWERTY:
        case _COLEMAKDH:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Num\nPad"), false);
            break;
        case _SWITCH:
            oled_write_P(PSTR("Swit\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        // case KC_COLEMAK:
        //     if (record->event.pressed) {
        //         set_single_persistent_default_layer(_COLEMAK);
        //     }
        //     return false;
        case KC_COLEMAKDH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_D_MUTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            // case _COLEMAK:
            case _QWERTY:
            case _RAISE:
            case _COLEMAKDH:
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
                break;
            case _LOWER:
                if (clockwise) {
                    tap_code(KC_MPRV);
                } else {
                    tap_code(KC_MNXT);
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
                break;
        }
    }
    return true;
}

#endif
