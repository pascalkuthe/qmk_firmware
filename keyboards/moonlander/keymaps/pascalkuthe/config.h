/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#undef TAPPING_TERM
#define TAPPING_TERM 160
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM_PER_KEY

#define USB_SUSPEND_WAKEUP_DELAY 100
#define CAPS_LOCK_STATUS
#define RGB_MATRIX_STARTUP_SPD 60
#define RGB_DISABLE_WHEN_USB_SUSPENDED
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// #define LEADER_TIMEOUT 300
// #define LEADER_PER_KEY_TIMING
// #define LEADER_KEY_STRICT_KEY_PROCESSING
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 3