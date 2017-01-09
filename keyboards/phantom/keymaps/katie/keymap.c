#include "phantom.h"

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Make the keymap more readable
#define _______ KC_TRNS

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------------------------.
   * |Esc  |f1| f2| f3| f4|  | f5| f6| f7| f8|   | f9|f10|f11|f12|	|Prnt|ScLk|Paus|
   * |-----------------------------------------------------------|	|--------------|
   * | ~ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  0| - | = |Backsp |	| Ins|Home|PgUp|
   * |-----------------------------------------------------------|	|--------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|	| Del| End|PgDn|
   * |-----------------------------------------------------------|	`--------------'
   * |Esc/Ctr|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|		 ,----.
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |		 | Up |
   * |-----------------------------------------------------------|	 ,-------------.
   * |Ctrl|Gui |Alt |      Space            |ALT |GUI |_FL |CTRL |	 |Lft| Dn |Rig |
   * `-----------------------------------------------------------'	 `-------------'
   */
[_BL] = KEYMAP(
  KC_ESC,        KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,              KC_PSCR,   KC_SLCK, KC_PAUS, \
  KC_GRV,        KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,    KC_HOME, KC_PGUP, \
  KC_TAB,        KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC, KC_RBRC, KC_BSLS,    KC_DELETE, KC_END,  KC_PGDN, \
  CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT, KC_ENT,  \
  KC_LSFT,       KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,                                 KC_UP,   \
  KC_LCTL,       KC_LGUI, KC_LALT,                  KC_SPC,                    KC_RALT, KC_RGUI, KC_FN1,   KC_RCTL,                      KC_LEFT,   KC_DOWN, KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------------------------.
   * |     |  |   |   |   |  |   |   |   |   |   |   |   |   |   |	|    |    |    |
   * |-----------------------------------------------------------|	|--------------|
   * |   |   |   |   |   |   |   |   |   |   |   |   |   | Reset |	| << |>|| | >> |
   * |-----------------------------------------------------------|	|--------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |	| MT | V- | V+ |
   * |-----------------------------------------------------------|	`--------------'
   * |       |   |   |   |   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|		 ,----.
   * |        |   |   |   |   |   |   |   |   |   |   |          |		 | MU |
   * |-----------------------------------------------------------|	 ,-------------.
   * |    |    |    |                       |    |RClk|    | LClk|	 | ML| MD | MR |
   * `-----------------------------------------------------------'	 `-------------'
   */
[_FL] = KEYMAP(
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,     KC_MPRV, KC_MPLY, KC_MNXT, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MUTE, KC_VOLD, KC_VOLU, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                               KC_MS_U, \
  _______, _______, _______,                   _______,                   _______, KC_BTN2, MO(_FL), KC_BTN1,                      KC_MS_L, KC_MS_D, KC_MS_R),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
  [1] = ACTION_LAYER_TAP_TOGGLE(_FL),
};

// Runs once when the firmware starts
void matrix_init_user(void) {
}

// Runs continuously in a loop
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    phantom_led_all_off();

    switch (layer) {
        case _FL:
            phantom_led_r_on();
            break;
        default:
            // none
            break;
    }
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
