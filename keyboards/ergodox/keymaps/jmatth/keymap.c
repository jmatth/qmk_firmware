#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define _QWERTY 0 // default layer
#define _COLEMAK 1
#define _LOWER 2 // symbols
#define _RAISE 3 // media keys
#define _ADJUST 4 // media keys

#define _______ KC_TRNS
#define GUIZ GUI_T(KC_Z)
#define ALTX ALT_T(KC_X)
#define ALTDOT ALT_T(KC_DOT)
#define GUISLSH GUI_T(KC_SLSH)

enum layer_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | Left |           | Right|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |' / Ctrl|
 * |--------+------+------+------+------+------|  [   |           |   ]  |------+------+------+------+------+--------|
 * | LShift | Gui/Z| Alt/X|   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |Alt/. |Gui// | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Lower| Raise|      | Left | Right|                                       |  Up  | Down |      |Rse/] |Lwr/` |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Bksp | Tab  |       |  Ent | Space  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Backsp| Tab  |------|       |------| Enter  |Space |
 *                                 |ace   |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_QWERTY] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,      KC_2,        KC_3,    KC_4,   KC_5,   KC_LEFT,
        KC_TAB,         KC_Q,      KC_W,        KC_E,    KC_R,   KC_T,   KC_LBRC,
        CTL_T(KC_ESC),  KC_A,      KC_S,        KC_D,    KC_F,   KC_G,
        KC_FN2,         GUIZ,      ALTX,        KC_C,    KC_V,   KC_B,   KC_LBRC,
        MO(_LOWER),     MO(_RAISE),KC_LGUI,     KC_LEFT, KC_RGHT,
                                                                   KC_BSPC,   KC_TAB,
                                                                              KC_HOME,
                                                             KC_BSPC, KC_TAB, KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,      KC_9,     KC_0,               KC_MINS,
             KC_RBRC,     KC_Y,   KC_U,   KC_I,      KC_O,     KC_P,               KC_BSLS,
                          KC_H,   KC_J,   KC_K,      KC_L,     KC_SCLN,            CTL_T(KC_QUOT),
             KC_RBRC,     KC_N,   KC_M,   KC_COMM,   ALTDOT,   GUISLSH,            KC_FN3,
                                  KC_UP,  KC_DOWN,   KC_LBRC,  LT(_RAISE,KC_RBRC), LT(_LOWER,KC_GRV),
             KC_ENT,      KC_SPC,
             KC_PGUP,
             KC_PGDN, KC_ENT, KC_SPC
    ),
/* Colemak layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   F  |   P  |   G  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Gui/Z| Alt/X|   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |Alt/. |Gui// |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_COLEMAK] = KEYMAP(  // layer 1 : colemak
        // left hand
        _______, _______,     _______,     _______, _______, _______, _______,
        _______, KC_Q,        KC_W,        KC_F,    KC_P,    KC_G,    _______,
        _______, KC_A,        KC_R,        KC_S,    KC_T,    KC_D,
        _______, GUI_T(KC_Z), ALT_T(KC_X), KC_C,    KC_V,    KC_B,    _______,
        _______, _______,     _______,     _______, _______,
                                                             _______, _______,
                                                                      _______,
                                                    _______, _______, _______,
        // right hand
        _______,  _______, _______, _______, _______,       _______,        _______,
        _______,  KC_J,    KC_L,    KC_U,    KC_Y,          KC_SCLN,        _______,
                  KC_H,    KC_N,    KC_E,    KC_I,          KC_O,           _______,
        _______,  KC_K,    KC_M,    KC_COMM, ALT_T(KC_DOT), GUI_T(KC_SLSH), _______,
                  _______, _______, _______, _______,       _______,
        _______, _______,
        _______,
        _______, _______, _______
    ),
/* Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   #  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   !  |   $  |   (  |   )  |   =  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   -  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   0  |   .  |   /  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[_LOWER] = KEYMAP(
       // left hand
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
       _______, KC_HASH, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,
       _______, KC_EXLM, KC_DLR,  KC_LPRN, KC_RPRN, KC_EQL,
       _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,
       _______, _______, _______, _______, _______,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
       // right hand
       _______, KC_F6,      KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______, KC_HASH,    KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                LSFT(KC_P), KC_4,   KC_5,    KC_6,    KC_PLUS, _______,
       _______, KC_AMPR,    KC_1,   KC_2,    KC_3,    KC_MINS, _______,
                            KC_0,   KC_0,    KC_DOT,  KC_SLSH, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/* Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | QWERTY |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | COLEMAK|      |      |  Up  |      |      |      |           |      |ScrllU|      | MsUp |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Left | Down |Right |      |------|           |------|ScrllD|MsLeft|MsDown|MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|Rclick|LClick|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[_RAISE] = KEYMAP(
       QWERTY,  _______, _______, _______, _______, _______, _______,
       COLEMAK, _______, _______, KC_UP,   _______, _______, _______,
       _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  KC_WH_U, _______, KC_MS_U, _______, _______, _______,
                 KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, KC_BTN2, KC_BTN1
),
/* Settings layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   #  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   !  |   $  |   (  |   )  |   =  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   -  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   0  |   .  |   /  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[_ADJUST] = KEYMAP(
       // left hand
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
       _______, KC_HASH, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,
       _______, KC_EXLM, KC_DLR,  KC_LPRN, KC_RPRN, KC_EQL,
       _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,
       _______, _______, _______, _______, _______,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
       // right hand
       _______, KC_F6,      KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______, KC_HASH,    KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                LSFT(KC_P), KC_4,   KC_5,    KC_6,    KC_PLUS, _______,
       _______, KC_AMPR,    KC_1,   KC_2,    KC_3,    KC_MINS, _______,
                            KC_0,   KC_0,    KC_DOT,  KC_SLSH, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
};

/* void persistant_default_layer_set(uint16_t default_layer) { */
/*   eeconfig_update_default_layer(default_layer); */
/*   default_layer_set(default_layer); */
/* } */

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(_LOWER),                // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_MODS_ONESHOT(MOD_LSFT),  // Sticky shift light. Tap for the next keypress to be shifted. Hold for regular shift.
    [3] = ACTION_MODS_ONESHOT(MOD_RSFT),
    /* [3] = ACTION_MACRO(LESS_NO), // < completed on keypress down, to avoid shifting the next character if it is not released first. */
    /* [4] = ACTION_MACRO(GRTR_NO), // > completed on keypress down, to avoid shifting the next character if it is not released first. */
    /* [5] = ACTION_MACRO(CIRC_NO), // Completed ^ character, no space needed. */
    /* [6] = ACTION_MACRO(ACUT_NO), // Completed ´ character, no space needed. */
    /* [7] = ACTION_MACRO(GRV_NO), // Completed ` character, no space needed. */
    /* [8] = ACTION_MACRO(LESS_NO_MAC), // < completed on keypress down, to avoid same button problem when typing <> quickly */
    /* [9] = ACTION_MACRO(GRTR_NO_MAC), // > completed on keypress down, to avoid same button problem when typing <> quickly */
    /* [10] = ACTION_MACRO(ACUT_NO_MAC), // Completed ´ character, no space needed */
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case _LOWER:
            ergodox_right_led_1_on();
            ergodox_board_led_on();
            break;
        case _RAISE:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                default_layer_set(1UL<<_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                default_layer_set(1UL<<_COLEMAK);
            }
            return false;
            break;
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
    }
    return true;
};
