#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: Qwerty
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| Backs |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Enter|
     * |-------------------------------------------------------    |
     * |Fn0   |  A|  S|  D|  F|  G|  H|  J|  K|  L| ; |  ' | # |   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| Shift    |
     * `-----------------------------------------------------------'
     * |Ctrl |Gui|Alt  |Space                  |Alt  |APP |Fn0|Ctrl|
     * `-----------------------------------------------------------'
     */
    KEYMAP(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
           TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,NO, \
           FN0,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NONUS_HASH,  ENT,  \
           LSFT,NONUS_BSLASH,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,NO,  RSFT, \
           LCTL,LGUI,LALT,          FN2,                     RALT,APP, FN0, RCTL),
    /* 1: Function Layer
     * ,-----------------------------------------------------------.
     * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10| F11| F12|Backs|
     * |-----------------------------------------------------------|
     * |Sleep|  Q| Up|  E|  R|  T|  Y|  U| Up|  O|Ins|Home|PgUp|Wak|
     * |-------------------------------------------------------    |
     * |Fn0   |Left|Dwn|Right|  F|  G|  H| Lft| Dn|Right| ;|End|PgDn|  |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V| Spc|  N|  M|PScr|Brk|ScLk| Shift  |
     * `-----------------------------------------------------------'
     * |Ctrl |Gui|Alt  |                       |Alt  |APP |Fn0|Ctrl|
     * `-----------------------------------------------------------'
     */
    KEYMAP(GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10,  F11, F12, DEL, \
           SLEP, NO,   UP, NO,  NO,   T,   Y,   U,  UP,   O,   INS, HOME, PGUP,NO, \
           FN0, LEFT, DOWN, RIGHT,   F,   G,   H, LEFT,DOWN,RIGHT,  TRNS,END, PGDN,  WAKE,  \
           LSFT, NO,  NO,  NO, NO, NO, SPC,  NO,  NO,  PSCR, PAUS, SLCK, NO,  RSFT, \
           LCTL,LGUI,LALT,          TRNS,                     RALT,APP, FN0, RCTL),


};
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1), // FN0
  [1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),
  [2] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),
};
