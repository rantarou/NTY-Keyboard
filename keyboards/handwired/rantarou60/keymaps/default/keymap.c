#include "rantarou60.h"

#define _QWERTY 0
#define _FN1 1
#define _FN2 2
#define KC_ KC_TRNS
#define KC_X0 MO(_FN2)
#define KC_X1 MO(_FN1)

// Func macro definitions.
#define KC_LED  FUNC(0)
#define KC_LEDI FUNC(1)
#define KC_LEDD FUNC(2)

// Enable these functions using FUNC(n) macro.
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_BACKLIGHT_TOGGLE(),
    [1] = ACTION_BACKLIGHT_INCREASE(),
    [2] = ACTION_BACKLIGHT_DECREASE()
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = KEYMAP(
 /*,----+----+----+----+----+----+----+----+----+----+----+----+----+--------. */
    GESC, 1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,MINS,EQL ,  BSPC  ,
 /*|----`----`----`----`----`----`----`----`----`----`----`----`----`--------| */
    TAB   , Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,LBRC,RBRC, BSLS ,
 /*|------`----`----`----`----`----`----`----`----`----`----`----`----`------| */
    CAPS   , A  , S  , D  , F  , G  , H  , J  , K  , L  ,SCLN,QUOT,    ENTER ,
 /*|-------`----`----`----`----`----`----`----`----`----`----`----`----------| */
    LSFT     , Z  , X  , C  , V  , B  , N  , M  ,COMM,DOT ,SLSH,       RSFT  ,
 /*|---------`----`----`----`----`----`----`----`----`----`----`-------------| */
    LCTL ,LGUI ,LALT ,            SPACE             ,RALT  ,X1   ,X0   ,RCTL
 /*`-----+-----+-----+------------------------------+------+-----+-----'-----' */
  ),

  [_FN1] = KEYMAP(
 /*,----+----+----+----+----+----+----+----+----+----+----+----+----+--------. */
    GRV , F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,   DEL  ,
 /*|esc-`-1--`-2--`-3--`-4--`-5--`-6--`-7--`-8--`-9--`-0--`mnus`plus`--bksp--| */
          ,PGUP, UP ,PGDN,    ,    ,    ,    ,    ,    ,PSCR,    ,    ,      ,
 /*|tab---`-q--`-w--`-e--`-r--`-t--`-y--`-u--`-i--`-o--`-p--`-{--`-}--`--|---| */
           ,LEFT,DOWN,RGHT,    ,    ,HOME,    ,    ,    ,    ,    ,          ,
 /*|caps---`-a--`-s--`-d--`-f--`-g--`-h--`-j--`-k--`-l--`-;--`-'--`----enter-| */
             ,INS ,DEL ,    ,    ,    ,END ,    ,MUTE,VOLD,VOLU,             ,
 /*|shift----`-z--`-x--`-c--`-v--`-b--`-n--`-m--`-,--`-.--`-/--`-------shift-| */
         ,     ,     ,                              ,      ,     ,     ,
 /*`ctrl-+-gui-+-alt-+----------space---------------+-alt--+-fn1-+-fn2-'ctrl-' */
  ),

  [_FN2] = KEYMAP(
 /*,----+----+----+----+----+----+----+----+----+----+----+----+----+--------. */
        ,LED ,LEDI,LEDD,    ,    ,    ,    ,    ,    ,    ,    ,    ,        ,
 /*|esc-`-1--`-2--`-3--`-4--`-5--`-6--`-7--`-8--`-9--`-0--`mnus`plus`--bksp--| */
          ,    ,    ,    ,    ,    ,    , 7  , 8  , 9  ,    ,    ,    ,      ,
 /*|tab---`-q--`-w--`-e--`-r--`-t--`-y--`-u--`-i--`-o--`-p--`-{--`-}--`--|---| */
           ,    ,    ,    ,    ,    ,    , 4  , 5  , 6  ,    ,    ,          ,
 /*|caps---`-a--`-s--`-d--`-f--`-g--`-h--`-j--`-k--`-l--`-;--`-'--`----enter-| */
             ,    ,    ,    ,    ,    , 0  , 1  , 2  , 3  ,    ,             ,
 /*|shift----`-z--`-x--`-c--`-v--`-b--`-n--`-m--`-,--`-.--`-/--`-------shift-| */
         ,     ,     ,                              ,      ,     ,     ,
 /*`ctrl-+-gui-+-alt-+----------space---------------+-alt--+-fn1-+-fn2-'ctrl-' */
  )
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
