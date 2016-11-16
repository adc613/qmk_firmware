// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _POWER 3
#define _FUNCTION 4

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  EXT_PLV,
};

enum functions {
  ULTRA_KEY,
  S_ENT,
  GUI_SPC,
  S_1,
  S_2,
  S_3,
  S_4,
  S_5,
  S_6,
  S_7,
  S_8,
  S_9,
  S_0,
};

enum macros {
  S_SPC,
  TERM,
  TEST,
};
// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM fn_actions[] = {
  [ULTRA_KEY] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  [S_ENT] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),
  [GUI_SPC] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_SPC),
  [S_1] = ACTION_MODS_KEY(MOD_LGUI, KC_1),
  [S_2] = ACTION_MODS_KEY(MOD_LGUI, KC_2),
  [S_3] = ACTION_MODS_KEY(MOD_LGUI, KC_3),
  [S_4] = ACTION_MODS_KEY(MOD_LGUI, KC_4),
  [S_5] = ACTION_MODS_KEY(MOD_LGUI, KC_5),
  [S_6] = ACTION_MODS_KEY(MOD_LGUI, KC_6),
  [S_7] = ACTION_MODS_KEY(MOD_LGUI, KC_7),
  [S_8] = ACTION_MODS_KEY(MOD_LGUI, KC_8),
  [S_9] = ACTION_MODS_KEY(MOD_LGUI, KC_9),
  [S_0] = ACTION_MODS_KEY(MOD_LGUI, KC_0),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  switch(id) {

      case S_SPC:
          if (record->event.pressed) {
              return MACRO( D(LGUI),  T(SPC), U(LGUI), END );
          }
          break;
      case TERM:
          if (record->event.pressed) {
              return MACRO( D(LGUI),  D(LALT), D(LCTL), T(T), U(LGUI),  U(LALT), U(LCTL), END );
          }
          break;
      case TEST:
          if (record->event.pressed) {
              return MACRO( T(T),END );
          }
          break;
  }

  return MACRO_NONE;

}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty ,-----------------------------------------------------------------------------------.  | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[0] = {
  {KC_TAB,       KC_Q,           KC_W,    KC_E,    KC_R,             KC_T,        KC_Y,        KC_U,             KC_I,    KC_O,    KC_P,    KC_BSPC  },
  {F(ULTRA_KEY), KC_A,           KC_S,    KC_D,    KC_F,             KC_G,        KC_H,        KC_J,             KC_K,    KC_L,    KC_SCLN, KC_QUOT  },
  {KC_LSFT,      KC_Z,           KC_X,    KC_C,    KC_V,             KC_B,        KC_N,        KC_M,             KC_COMM, KC_DOT,  KC_SLSH, F(S_ENT) },
  {TG(3),   OSL(4), KC_LALT, KC_LGUI, LT(1, KC_LBRC),   F(GUI_SPC),  F(GUI_SPC),  LT(2, KC_RBRC),   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT }
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |   6  |   -  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[1] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, KC_LCBR, KC_RCBR, KC_RPRN, M(TERM)},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_EQL,  KC_MINS, KC_LPRN, KC_RPRN, KC_RCBR, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______},
  {_______, _______, KC_MNXT, KC_MPRV, _______, M(S_SPC), M(S_SPC), _______, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   ^  |   %  |   &  |   *  |   (  |   )  | bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      _      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[2] = {
  {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_CIRC, KC_PERC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_BSPC},
  {KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_PIPE},
  {_______, F(S_1),  F(S_2),  F(S_3),  F(S_4),  F(S_5),  F(S_6),  F(S_7),  F(S_8),  F(S_9),  F(S_0),   F(2)},
  {_______, _______, _______, KC_CAPS, _______, KC_UNDS, KC_UNDS, _______, _______, _______,  _______, _______}
},

/* POWER
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   ^  |   %  |   &  |   *  |   (  |   )  | bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      _      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[3] = {
  {KC_ESC,  KC_1,   KC_2,  KC_3,  KC_DLR,  KC_INS,  KC_HOME, KC_TAB,  KC_UP,   KC_ENT,   _______, KC_BSPC},
  {KC_ASTR, KC_4,   KC_5,  KC_6,  KC_PLUS, KC_PGDN, KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT, KC_0,    KC_PIPE},
  {KC_SLSH, KC_7,   KC_8,  KC_9,  KC_MINS, KC_END,  KC_DEL,  KC_NUHS, KC_NUBS, _______,  _______, F(2)},
  {_______, KC_DOT, KC_0, KC_ENT, _______, KC_UNDS, KC_UNDS, _______, KC_MPLY, KC_MUTE,  KC_MNXT, KC_MPRV}
},

/* POWER
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   ^  |   %  |   &  |   *  |   (  |   )  | bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      _      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[4] = {
  {_______, _______,        _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______},
  { KC_F1,  KC_F2,          KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12},
  {_______, _______,        _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______},
  {_______, OSL(4), _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______}
},
};


#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

static bool caps_lock = false;

void persistent_default_layer_set(uint16_t default_layer){
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /*switch (keycode) {*/
    /*case  QWERTY:*/
      /*if (record->event.pressed) {*/

        /*#ifdef AUDIO_ENABLE*/
          /*PLAY_NOTE_ARRAY(tone_qwerty, false, 0);*/
        /*#endif*/
        /*persistent_default_layer_set(1UL<<_QWERTY);*/
        /*layer_off(_POWER);*/
        /*layer_on(_QWERTY);*/
        /*update_tri_layer(_LOWER, _RAISE, _POWER);*/
      /*}*/
      /*return false;*/
      /*break;*/
    /*case KC_CAPS:*/
      /*if(caps_lock==true) {*/
          /*caps_lock=false;*/
          /*PLAY_NOTE_ARRAY(tone_colemak, false, 0);*/
      /*} else {*/
          /*caps_lock=true;*/
          /*PLAY_NOTE_ARRAY(tone_goodbye, false, 0);*/
      /*}*/
      /*break;*/
    /*case LOWER:*/
      /*if (record->event.pressed) {*/
        /*layer_on(_LOWER);*/
        /*update_tri_layer(_LOWER, _RAISE, _POWER);*/
      /*} else {*/
        /*layer_off(_LOWER);*/
        /*update_tri_layer(_LOWER, _RAISE, _POWER);*/
      /*}*/
      /*return false;*/
      /*break;*/
    /*case RAISE:*/
      /*if (record->event.pressed) {*/
        /*layer_on(_RAISE);*/
        /*update_tri_layer(_LOWER, _RAISE, _POWER);*/
      /*} else {*/
        /*layer_off(_RAISE);*/
        /*update_tri_layer(_LOWER, _RAISE, _POWER);*/
      /*}*/
      /*return false;*/
      /*break;*/
  /*}*/
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
