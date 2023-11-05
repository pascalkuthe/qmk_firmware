# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
TAP_DANCE_ENABLE = no
LEADER_ENABLE = no
AUDIO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
SRC = matrix.c
SRC += features/achordion.c
UNICODE_ENABLE = no
UNICODEMAP_ENABLE =no
MOUSEKEY_ENABLE = yes
CAPS_WORD_ENABLE = yes