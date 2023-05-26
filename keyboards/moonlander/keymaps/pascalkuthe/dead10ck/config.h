/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 150

#define ONESHOT_TAP_TOGGLE 2

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 791

#define USB_SUSPEND_WAKEUP_DELAY 100
#define CAPS_LOCK_STATUS
#define RGB_MATRIX_STARTUP_SPD 60
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING
#define LEADER_KEY_STRICT_KEY_PROCESSING
