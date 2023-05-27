# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
TAP_DANCE_ENABLE = no
LEADER_ENABLE = yes
AUDIO_ENABLE = yes
SRC = matrix.c
SRC += features/achordion.c
UNICODE_ENABLE = no
UNICODEMAP_ENABLE =no
MOUSEKEY_ENABLE = yes
COMBO_ENABLE = no
CAPS_WORD_ENABLE = yes