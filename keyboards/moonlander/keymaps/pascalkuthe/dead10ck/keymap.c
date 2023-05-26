// vim: nowrap

#include QMK_KEYBOARD_H
#include "version.h"

#define MT_HYP_EQ MT(MOD_HYPR, KC_EQUAL)
#define ACTIVE_STICKY_MOD_TIMEOUT 500
#define HYPER(kc) LALT(LCTL(LGUI(LSFT(kc))))
#define CALT(kc) LALT(LCTL(kc))

enum custom_keycodes {
    M_ALT_GRAVE = SAFE_RANGE,
    M_ALT_TAB,
    M_CTRL_TAB,
    M_MGC_B,
    M_MGC_E,
    M_MGC_I,
    M_MGC_R,
    M_MGC_S,
    M_MGC_U,
    M_NTM_0,
    M_NTM_1,
    M_NTM_2,
    M_NTM_3,
    M_NTM_4,
    M_NTM_5,
    M_NTM_6,
    M_NTM_7,
    M_NTM_8,
    M_NTM_9,
    M_NTM_AST,
    M_NTM_C,
    M_NTM_CDOWN,
    M_NTM_CLEFT,
    M_NTM_COLON,
    M_NTM_CRIGHT,
    M_NTM_CUP,
    M_NTM_D,
    M_NTM_DOWN,
    M_NTM_LBRKT,
    M_NTM_LEFT,
    M_NTM_LPRN,
    M_NTM_N,
    M_NTM_P,
    M_NTM_PCNT,
    M_NTM_QUOT,
    M_NTM_RIGHT,
    M_NTM_SPC,
    M_NTM_UP,
    M_NTM_X,
    M_PARENS,
    M_TM_0,
    M_TM_1,
    M_TM_2,
    M_TM_3,
    M_TM_4,
    M_TM_5,
    M_TM_6,
    M_TM_7,
    M_TM_8,
    M_TM_9,
    M_TM_AST,
    M_TM_C,
    M_TM_CDOWN,
    M_TM_CLEFT,
    M_TM_COLON,
    M_TM_CRIGHT,
    M_TM_CUP,
    M_TM_D,
    M_TM_DOWN,
    M_TM_LBRKT,
    M_TM_LEFT,
    M_TM_LPRN,
    M_TM_N,
    M_TM_P,
    M_TM_PCNT,
    M_TM_QUOT,
    M_TM_RIGHT,
    M_TM_SPC,
    M_TM_UP,
    M_TM_X,
    RGB_SLD,
};

enum tap_dance_codes {
    D_SYS,
    D_CAPS,
    D_WKSP_L,
    D_WKSP_R,
    D_TMUX,
};

enum layers {
    L_BASE,
    L_NAV,
    L_SYMB,
    L_MEDIA,
    L_TMUX,
    L_N_TMUX,
    L_NUMPAD,
    L_SYS,
};

enum combos {
    C_L_N_TMUX,
    C_RALT,
    C_LENGTH,
};

// necessary to tell it how many combos there are
uint16_t               COMBO_LEN             = C_LENGTH;
const uint16_t PROGMEM c_nested_tmux_layer[] = {OSL(L_TMUX), OSL(L_NAV), COMBO_END};
const uint16_t PROGMEM c_right_alt[]         = {OSL(L_SYMB), KC_LEFT_GUI, COMBO_END};

combo_t key_combos[] = {
    [C_L_N_TMUX] = COMBO(c_nested_tmux_layer, OSL(L_N_TMUX)),
    [C_RALT]     = COMBO(c_right_alt, KC_RIGHT_ALT),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
         KC_DELETE,       KC_1,          KC_2,        KC_3,    KC_4,       KC_5,       KC_HOME,       KC_END,      KC_6,     KC_7,     KC_8,       KC_9,         KC_0,       KC_MINUS,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          KC_AMPR,        KC_Q,          KC_W,        KC_E,    KC_R,       KC_T,       KC_PIPE,     TO(L_SYMB),    KC_Y,     KC_U,     KC_I,       KC_O,         KC_P,      KC_BACKSLASH,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
      LT(L_SYMB,KC_ESC),  KC_A,          KC_S,        KC_D,    KC_F,       KC_G,      MT_HYP_EQ,     TG(L_NAV),    KC_H,     KC_J,     KC_K,       KC_L,     KC_SEMICOLON,   KC_QUOTE,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
       KC_LEFT_SHIFT,  LCTL_T(KC_Z),  LSFT_T(KC_X),   KC_C,    KC_V,       KC_B,                                   KC_N,     KC_M,   KC_COMMA,    KC_DOT,       KC_SLASH,    QK_LEAD,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
         TD(D_SYS),     TD(D_CAPS),  KC_LEFT_GUI,OSL(L_TMUX),OSL(L_NAV),LALT(KC_TAB),                        TG(L_NUMPAD),OSL(L_SYMB),KC_LEFT_GUI,TD(D_WKSP_L),TD(D_WKSP_R), MO(L_MEDIA),
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                       LCTL_T(KC_ENTER),  LSFT_T(KC_TAB),      KC_LEFT_ALT,         KC_LEFT_ALT,LSFT_T(KC_BACKSPACE),LCTL_T(KC_SPACE)
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),

  [L_NAV] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,      _______,      _______,     _______, _______,  _______,     _______,     _______,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,      _______,      _______,     KC_HOME,KC_PAGE_UP, KC_PGDN,   KC_END,      _______,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,        _______,   KC_PGDN, _______,    _______,      _______,      _______,     KC_LEFT, KC_DOWN,   KC_UP,     KC_RIGHT,     _______,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,                                 _______,  _______,  _______,    _______,     _______,      _______,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,                                 _______, _______,  _______,    _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                            _______,           _______,          _______,              _______,       _______,           _______
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),
  [L_SYMB] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          KC_ESC,         KC_F1,         KC_F2,      KC_F3,   KC_F4,      KC_F5,       _______,       _______,     KC_F6,   KC_F7,    KC_F8,      KC_F9,        KC_F10,       KC_F11,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,       _______,    KC_LCBR, KC_RCBR,    KC_HASH,      _______,     TO(L_MEDIA), KC_GRAVE, KC_EXLM,   KC_AT,     KC_CIRC,      _______,       KC_F12,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,       _______,    KC_LPRN, KC_RPRN,    KC_TILD,      _______,       _______,    KC_PERC, KC_AMPR,  KC_PIPE,     KC_DLR,      _______,       KC_DQUO,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,       _______,    KC_LBRC, KC_RBRC,    _______,                                 _______, KC_ASTR,  _______,    _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,       _______,    KC_LABK, KC_RABK,    _______,                                 _______, _______,  _______,    _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                            M_ALT_TAB,      M_ALT_GRAVE,       M_CTRL_TAB,             _______,       _______,           _______
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),
  [L_MEDIA] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
           AU_TOGG,       _______,       _______,   _______, _______,    _______,      _______,       _______,    _______, _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
           MU_TOGG,       _______,       _______,   _______, _______,    _______,      _______,     TO(L_BASE),   _______, _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
           MI_MOD,        _______,       _______,   _______, _______,    _______,      _______,       _______,    _______, _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
           _______,       _______,       _______,   _______, _______,    _______,                                 _______, KC_MPLY,  KC_MPRV,     KC_MNXT,     _______,      _______,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
           RGB_SPD,       RGB_SPI,       _______,   _______, _______,    RGB_MOD,                                 RGB_TOG, KC_VOLD,  KC_VOLU,  KC_AUDIO_MUTE, HYPER(KC_M),   _______,
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                            RGB_VAD,          RGB_VAI,     TOGGLE_LAYER_COLOR,         RGB_SLD,        RGB_HUD,          RGB_HUI
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),
  [L_TMUX] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,        M_TM_1,       M_TM_2,      M_TM_3,  M_TM_4,     M_TM_5,      _______,       _______,    M_TM_6,   M_TM_7,   M_TM_8,    M_TM_9,        M_TM_0,       _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,      M_TM_QUOT,     M_TM_PCNT,   M_TM_AST,M_TM_LPRN,  _______,      _______,       _______, M_TM_CLEFT,M_TM_CDOWN,M_TM_CUP,  M_TM_CRIGHT,    M_TM_P,       _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,        _______,     M_TM_LBRKT,   M_TM_D, _______,    _______,      _______,       _______,  M_TM_LEFT,M_TM_DOWN, M_TM_UP,   M_TM_RIGHT,    M_TM_COLON,    _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,        _______,      M_TM_X,      M_TM_C, _______,    _______,                                 M_TM_N,  _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,        _______,       _______,   _______, _______,    _______,                                 _______, _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                             _______,         _______,           _______,              _______,       _______,          M_TM_SPC
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),
  [L_N_TMUX] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,        M_NTM_1,       M_NTM_2,   M_NTM_3, M_NTM_4,    M_NTM_5,      _______,       _______,    M_NTM_6, M_NTM_7,  M_NTM_8,     M_NTM_9,      M_NTM_0,     _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,      M_NTM_QUOT,    M_NTM_PCNT, M_NTM_AST,M_NTM_LPRN, _______,      _______,       _______,M_NTM_CLEFT,M_NTM_CDOWN,M_NTM_CUP,M_NTM_CRIGHT,   M_NTM_P,     _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,     M_NTM_LBRKT,  M_NTM_D, _______,    _______,      _______,       _______, M_NTM_LEFT,M_NTM_DOWN,M_NTM_UP,  M_NTM_RIGHT,  M_NTM_COLON,   _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,       M_NTM_X,    M_NTM_C, _______,    _______,                                 M_NTM_N, _______,  _______,     _______,      _______,     _______,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,       _______,    _______, _______,    _______,                                 _______, _______,  _______,     _______,      _______,     _______,
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                             _______,         _______,           _______,              _______,       _______,         M_NTM_SPC
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),
  [L_NUMPAD] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,      _______,       _______,    _______, M_PARENS, KC_SLASH,  KC_ASTERISK,   KC_MINUS,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,      _______,       _______,    _______,   KC_7,     KC_8,       KC_9,        KC_PLUS,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,      _______,       _______,    _______,   KC_4,     KC_5,       KC_6,        KC_PLUS,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,                                 _______,   KC_1,     KC_2,       KC_3,       KC_ENTER,      _______,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,                                 _______,   KC_0,     KC_0,      KC_DOT,      KC_ENTER,      _______,
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                            _______,         _______,           _______,               _______,     KC_BACKSPACE,       KC_ENTER
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),
  [L_SYS] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
      CALT(KC_DELETE),  CALT(KC_F1), CALT(KC_F2),CALT(KC_F3),_______,     _______,     _______,       _______,    _______, _______,  _______,     _______,      _______,      QK_BOOT,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,       _______,    _______, _______,     _______,     _______,     TO(L_BASE),   _______, _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,       _______,    _______, _______,     _______,     _______,       M_MGC_R,    M_MGC_E, M_MGC_I,  M_MGC_S,    M_MGC_U,       M_MGC_B,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,       _______,    _______, _______,     _______,                                _______, _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,       _______,    _______, _______,     _______,                                _______, _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                            _______,           _______,          _______,              _______,      _______,           _______
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),
};
// clang-format on

uint16_t active_sticky_mod         = 0;
uint16_t sticky_mod_timer          = 0;
bool     active_sticky_mod_pressed = false;
int      ss_waitms                 = 20;

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_TAB):
        case LSFT_T(KC_BACKSPACE):
            return true;
        default:
            return false;
    }
}

void matrix_scan_user(void) {
    if (active_sticky_mod && timer_elapsed(sticky_mod_timer) > ACTIVE_STICKY_MOD_TIMEOUT) {
        // if we're still holding the key, reset the timer to give more time
        if (active_sticky_mod_pressed) {
            sticky_mod_timer = timer_read();
        } else {
            unregister_code(active_sticky_mod);
            active_sticky_mod = 0;
        }
    }
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_C, KC_B)) {
        SEND_STRING_DELAY("```" SS_LSFT("\n\n") "```" SS_TAP(X_UP), ss_waitms);

    } else if (leader_sequence_four_keys(KC_C, KC_B, KC_P, KC_P)) {
        SEND_STRING_DELAY(SS_LSFT("\n\n") "```" SS_LSFT("\n\n") "```" SS_TAP(X_UP) SS_LCTL(SS_TAP(X_V)), ss_waitms);

    } else if (leader_sequence_three_keys(KC_C, KC_B, KC_P)) {
        SEND_STRING_DELAY("```" SS_LSFT("\n\n") "```" SS_TAP(X_UP) SS_LCTL(SS_TAP(X_V)), ss_waitms);
    }

    else if (leader_sequence_three_keys(KC_L, KC_S, KC_L)) {
        SEND_STRING_DELAY("ls -alh\n", ss_waitms);

    } else if (leader_sequence_three_keys(KC_A, KC_L, KC_S)) {
        SEND_STRING_DELAY("aws s3 ls --human ", ss_waitms);

    } else if (leader_sequence_two_keys(KC_T, KC_M)) {
        SEND_STRING_DELAY("tmux a || tmux\n", ss_waitms);
    }

    // disable bracketed paste
    else if (leader_sequence_two_keys(KC_B, KC_P)) {
        SEND_STRING_DELAY("printf \"\\e[?2004l\"\n", ss_waitms);
    }

    // enable bracketed paste
    else if (leader_sequence_three_keys(KC_B, KC_P, KC_P)) {
        SEND_STRING_DELAY("printf \"\\e[?2004h\"\n", ss_waitms);
    }

    else if (leader_sequence_two_keys(KC_S, KC_U)) {
        SEND_STRING_DELAY("sudo -i\n", ss_waitms);

    } else if (leader_sequence_two_keys(KC_P, KC_S)) {
        SEND_STRING_DELAY("ps -aefH", ss_waitms);

    } else if (leader_sequence_three_keys(KC_P, KC_S, KC_L)) {
        SEND_STRING_DELAY("ps -aefH | less\n", ss_waitms);
    }

    else if (leader_sequence_three_keys(KC_T, KC_A, KC_I)) {
        SEND_STRING_DELAY("tai64nlocal", ss_waitms);

    } else if (leader_sequence_two_keys(KC_T, KC_A)) {
        SEND_STRING_DELAY("tail -F  | tai64nlocal" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT), ss_waitms);

    } else if (leader_sequence_two_keys(KC_P, KC_U)) {
        SEND_STRING_DELAY("/etc/puppet/bin/puppet", ss_waitms);
    }

    else if (leader_sequence_two_keys(KC_O, KC_S)) {
        SEND_STRING_DELAY("source /opt/SGraph/scripts/oozie-env.sh\n", ss_waitms);

    } else if (leader_sequence_three_keys(KC_O, KC_J, KC_I)) {
        SEND_STRING_DELAY("oozie job -info '" SS_LSFT(SS_LCTL("v")) "'\n", ss_waitms);

    } else if (leader_sequence_three_keys(KC_O, KC_J, KC_S)) {
        SEND_STRING_DELAY("oozie jobs -jobtype ", ss_waitms);

    } else if (leader_sequence_two_keys(KC_Y, KC_L)) {
        SEND_STRING_DELAY("yarn logs -applicationId '" SS_LSFT(SS_LCTL("v")) "'\n", ss_waitms);
    }

    else if (leader_sequence_three_keys(KC_J, KC_Q, KC_L)) {
        SEND_STRING_DELAY("jq -C '.' | less -R\n", ss_waitms);

    } else if (leader_sequence_two_keys(KC_E, KC_M)) {
        SEND_STRING_DELAY("skyler@dead10ck.dev", ss_waitms);
    }
}

void sticky_mod(uint16_t mod_key, uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (active_sticky_mod && active_sticky_mod != mod_key) {
            unregister_code(active_sticky_mod);
            active_sticky_mod = 0;
        }

        if (!active_sticky_mod) {
            register_code(mod_key);
            active_sticky_mod = mod_key;
        }

        sticky_mod_timer = timer_read();
        tap_code(keycode);
        active_sticky_mod_pressed = true;
    } else {
        // start the timer again when we release
        sticky_mod_timer = timer_read();

        // we've already released it
        active_sticky_mod_pressed = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_ALT_TAB:
            sticky_mod(KC_LEFT_ALT, KC_TAB, record);
            return false;

        case M_CTRL_TAB:
            sticky_mod(KC_LEFT_CTRL, KC_TAB, record);
            return false;

        case M_ALT_GRAVE:
            sticky_mod(KC_LEFT_ALT, KC_GRAVE, record);
            return false;

        // Macros
        case M_TM_1:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_1), ss_waitms);
            }
            break;
        case M_TM_2:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_2), ss_waitms);
            }
            break;
        case M_TM_3:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_3), ss_waitms);
            }
            break;
        case M_TM_4:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_4), ss_waitms);
            }
            break;
        case M_TM_5:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_5), ss_waitms);
            }
            break;
        case M_TM_QUOT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_QUOTE)), ss_waitms);
            }
            break;
        case M_TM_PCNT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_5)), ss_waitms);
            }
            break;
        case M_TM_AST:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_8)), ss_waitms);
            }
            break;
        case M_TM_LPRN:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_9)), ss_waitms);
            }
            break;
        case M_TM_LBRKT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_LEFT_BRACKET), ss_waitms);
            }
            break;
        case M_TM_D:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_D), ss_waitms);
            }
            break;
        case M_TM_X:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_X), ss_waitms);
            }
            break;
        case M_TM_C:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_C), ss_waitms);
            }
            break;
        case M_TM_6:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_6), ss_waitms);
            }
            break;
        case M_TM_7:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_7), ss_waitms);
            }
            break;
        case M_TM_8:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_8), ss_waitms);
            }
            break;
        case M_TM_9:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_9), ss_waitms);
            }
            break;
        case M_TM_0:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_0), ss_waitms);
            }
            break;
        case M_TM_CLEFT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_LEFT)), ss_waitms);
            }
            break;
        case M_TM_CDOWN:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_DOWN)), ss_waitms);
            }
            break;
        case M_TM_CUP:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_UP)), ss_waitms);
            }
            break;
        case M_TM_CRIGHT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_RIGHT)), ss_waitms);
            }
            break;
        case M_TM_P:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_P), ss_waitms);
            }
            break;
        case M_TM_LEFT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_LEFT), ss_waitms);
            }
            break;
        case M_TM_DOWN:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_DOWN), ss_waitms);
            }
            break;
        case M_TM_UP:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_UP), ss_waitms);
            }
            break;
        case M_TM_RIGHT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_RIGHT), ss_waitms);
            }
            break;
        case M_TM_COLON:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_SEMICOLON)), ss_waitms);
            }
            break;
        case M_TM_N:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_N), ss_waitms);
            }
            break;
        case M_TM_SPC:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_SPACE), ss_waitms);
            }
            break;
        case M_NTM_1:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_1), ss_waitms);
            }
            break;
        case M_NTM_2:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_2), ss_waitms);
            }
            break;
        case M_NTM_3:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_3), ss_waitms);
            }
            break;
        case M_NTM_4:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_4), ss_waitms);
            }
            break;
        case M_NTM_5:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_5), ss_waitms);
            }
            break;
        case M_NTM_QUOT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_QUOTE)), ss_waitms);
            }
            break;
        case M_NTM_PCNT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_5)), ss_waitms);
            }
            break;
        case M_NTM_AST:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_8)), ss_waitms);
            }
            break;
        case M_NTM_LPRN:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_9)), ss_waitms);
            }
            break;
        case M_NTM_LBRKT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_LEFT_BRACKET), ss_waitms);
            }
            break;
        case M_NTM_D:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_D), ss_waitms);
            }
            break;
        case M_NTM_X:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_X), ss_waitms);
            }
            break;
        case M_NTM_C:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_C), ss_waitms);
            }
            break;
        case M_NTM_6:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_6), ss_waitms);
            }
            break;
        case M_NTM_7:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_7), ss_waitms);
            }
            break;
        case M_NTM_8:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_8), ss_waitms);
            }
            break;
        case M_NTM_9:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_9), ss_waitms);
            }
            break;
        case M_NTM_0:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_0), ss_waitms);
            }
            break;
        case M_NTM_CLEFT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_LEFT)), ss_waitms);
            }
            break;
        case M_NTM_CDOWN:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_DOWN)), ss_waitms);
            }
            break;
        case M_NTM_CUP:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_UP)), ss_waitms);
            }
            break;
        case M_NTM_CRIGHT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_RIGHT)), ss_waitms);
            }
            break;
        case M_NTM_P:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_P), ss_waitms);
            }
            break;
        case M_NTM_LEFT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_LEFT), ss_waitms);
            }
            break;
        case M_NTM_DOWN:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_DOWN), ss_waitms);
            }
            break;
        case M_NTM_UP:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_UP), ss_waitms);
            }
            break;
        case M_NTM_RIGHT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_RIGHT), ss_waitms);
            }
            break;
        case M_NTM_COLON:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_SEMICOLON)), ss_waitms);
            }
            break;
        case M_NTM_N:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_N), ss_waitms);
            }
            break;
        case M_NTM_SPC:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_SPACE), ss_waitms);
            }
            break;
        case M_PARENS:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LSFT(SS_TAP(X_8)) SS_LSFT(SS_TAP(X_9)), ss_waitms);
            }
            break;
        case M_MGC_R:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LALT(SS_TAP(X_SYSTEM_REQUEST) SS_DELAY(100) SS_TAP(X_R)), ss_waitms);
            }
            break;
        case M_MGC_E:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LALT(SS_TAP(X_SYSTEM_REQUEST) SS_DELAY(100) SS_TAP(X_E)), ss_waitms);
            }
            break;
        case M_MGC_I:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LALT(SS_TAP(X_SYSTEM_REQUEST) SS_DELAY(100) SS_TAP(X_I)), ss_waitms);
            }
            break;
        case M_MGC_S:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LALT(SS_TAP(X_SYSTEM_REQUEST) SS_DELAY(100) SS_TAP(X_S)), ss_waitms);
            }
            break;
        case M_MGC_U:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LALT(SS_TAP(X_SYSTEM_REQUEST) SS_DELAY(100) SS_TAP(X_U)), ss_waitms);
            }
            break;
        case M_MGC_B:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LALT(SS_TAP(X_SYSTEM_REQUEST) SS_DELAY(100) SS_TAP(X_B)), ss_waitms);
            }
            break;
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}

extern rgb_config_t rgb_matrix_config;

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [L_NUMPAD] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {15, 97, 236}, {27, 126, 255}, {27, 126, 255}, {254, 198, 190}, {254, 198, 190}, {15, 176, 169}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {146, 224, 255}, {169, 120, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {254, 198, 190}, {233, 218, 217}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {254, 198, 190}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {254, 198, 190}, {205, 255, 255}, {0, 0, 0}, {0, 0, 0}},
    [L_SYS]    = {{0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245},
                  {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}},
};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }

    switch (biton32(layer_state)) {
        case L_NUMPAD:
            set_layer_color(L_NUMPAD);
            break;
        case L_SYS:
            set_layer_color(L_SYS);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }

    return false;
}

typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };

static tap dance_state[5];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case DOUBLE_TAP:
            layer_move(L_SYS);
            break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {}
    dance_state[0].step = 0;
}
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case DOUBLE_TAP:
            register_code16(KC_CAPS_LOCK);
            break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case DOUBLE_TAP:
            unregister_code16(KC_CAPS_LOCK);
            break;
    }
    dance_state[1].step = 0;
}

void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LGUI(KC_PAGE_UP));
        tap_code16(LGUI(KC_PAGE_UP));
        tap_code16(LGUI(KC_PAGE_UP));
    }
    if (state->count > 3) {
        tap_code16(LGUI(KC_PAGE_UP));
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            register_code16(LGUI(KC_PAGE_UP));
            break;
        case DOUBLE_TAP:
            register_code16(LGUI(LSFT(KC_PAGE_UP)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LGUI(KC_PAGE_UP));
            register_code16(LGUI(KC_PAGE_UP));
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            unregister_code16(LGUI(KC_PAGE_UP));
            break;
        case DOUBLE_TAP:
            unregister_code16(LGUI(LSFT(KC_PAGE_UP)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LGUI(KC_PAGE_UP));
            break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LGUI(KC_PAGE_DOWN));
        tap_code16(LGUI(KC_PAGE_DOWN));
        tap_code16(LGUI(KC_PAGE_DOWN));
    }
    if (state->count > 3) {
        tap_code16(LGUI(KC_PAGE_DOWN));
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP:
            register_code16(LGUI(KC_PAGE_DOWN));
            break;
        case DOUBLE_TAP:
            register_code16(LGUI(LSFT(KC_PAGE_DOWN)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LGUI(KC_PAGE_DOWN));
            register_code16(LGUI(KC_PAGE_DOWN));
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP:
            unregister_code16(LGUI(KC_PAGE_DOWN));
            break;
        case DOUBLE_TAP:
            unregister_code16(LGUI(LSFT(KC_PAGE_DOWN)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LGUI(KC_PAGE_DOWN));
            break;
    }
    dance_state[4].step = 0;
}

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
    [D_SYS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
    [D_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
    [D_WKSP_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
    [D_WKSP_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
};
