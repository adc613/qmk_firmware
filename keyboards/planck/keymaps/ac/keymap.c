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
#define _HOME 0
#define _LOWER 1
#define _RAISE 2
#define _POWER 3
#define _FUNCTION 4
// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum special_keycode {
  SOUND1=SAFE_RANGE,
  SOUND2,
  SOUND3,
  SOUND4,
};

enum layouts {
  HOME,
  TYPING,
  NUMS,
  SYMBOLS,
  T_SYMBOLS,
  FUNC,
  POWER,
};

enum functions {
  ULTRA_KEY,
  S_ENT,
  GUI_SPC,
  S_1a,
  S_2a,
  S_3a,
  S_4a,
  S_5a,
  S_6a,
  S_7a,
  S_8a,
  S_9a,
  S_0a,
  TEST_1,
};

enum macros {
  S_SPC,
  TERM,
  TEST,
  PASS,
  EMAL,
  DCON,
};

const uint16_t PROGMEM fn_actions[] = {
  [ULTRA_KEY] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  [S_ENT] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),
  [GUI_SPC] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_SPC),
  [S_1a] = ACTION_MODS_KEY(MOD_LGUI, KC_1),
  [S_2a] = ACTION_MODS_KEY(MOD_LGUI, KC_2),
  [S_3a] = ACTION_MODS_KEY(MOD_LGUI, KC_3),
  [S_4a] = ACTION_MODS_KEY(MOD_LGUI, KC_4),
  [S_5a] = ACTION_MODS_KEY(MOD_LGUI, KC_5),
  [S_6a] = ACTION_MODS_KEY(MOD_LGUI, KC_6),
  [S_7a] = ACTION_MODS_KEY(MOD_LGUI, KC_7),
  [S_8a] = ACTION_MODS_KEY(MOD_LGUI, KC_8),
  [S_9a] = ACTION_MODS_KEY(MOD_LGUI, KC_9),
  [S_0a] = ACTION_MODS_KEY(MOD_LGUI, KC_0),
};

enum {
  BSPC1  = 0,
  BSPC2,
  BSPC3,
  BSPC4,
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
    case DCON:
      if (record->event.pressed) {
          return MACRO( D(LGUI), D(LALT), T(I), U(LALT), U(LGUI), END );
      }
      break;
    case TEST:
      if (record->event.pressed) {
          return MACRO( T(T), END );
      }
      break;
    case PASS:
      if (record->event.pressed) {
          return MACRO( I(10), D(LSFT), T(P), T(A), T(4), T(4), U(LSFT),  T(W), T(O), T(R), T(D), END );
      }
      break;
    case EMAL:
      if (record->event.pressed) {
          return MACRO( I(10), T(F), T(A), T(K),T(E), D(LSFT), T(2), U(LSFT), T(E), T(M), T(A), T(I), T(L), T(DOT), T(C), T(O), T(M), END );
      }
      break;

  }

  return MACRO_NONE;

}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *  -----------------------------------------------------------------------------------
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |U_KEY |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |S_ENT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | L_POW|L_FUNC|L_TYPE| ALT  |DN, [ |    Space    |UP, ] | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[HOME] = {
  {KC_TAB,       KC_Q,           KC_W,    KC_E,    KC_R,             KC_T,        KC_Y,        KC_U,             KC_I,    KC_O,    KC_P,    TD(BSPC1) },
  {F(ULTRA_KEY), KC_A,           KC_S,    KC_D,    KC_F,             KC_G,        KC_H,        KC_J,             KC_K,    KC_L,    KC_SCLN, KC_QUOT  },
  {KC_LSFT,      KC_Z,           KC_X,    KC_C,    KC_V,             KC_B,        KC_N,        KC_M,             KC_COMM, KC_DOT,  KC_SLSH, F(S_ENT) },
  {TG(POWER),   OSL(FUNC), TG(TYPING), KC_LALT, LT(SYMBOLS, KC_LBRC),   F(GUI_SPC),  F(GUI_SPC),  LT(NUMS, KC_RBRC),   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT }
},


/* Typing
 *  -----------------------------------------------------------------------------------
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | GUI  |      |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[TYPING] = {
  {_______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, _______, TD(BSPC2) },
  {_______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, _______, _______ },
  {_______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, _______, _______ },
  {_______, _______, _______, KC_LGUI, LT(SYMBOLS, KC_LBRC), KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______ }
},


/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |M_TERM|M_PASS|M_EMAL|      |   %  |      |      |   +  |   {  |   }  |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |   (  |   )  |      |   =  |   -  |   (  |   )  |      |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |M_S_1 |M_S_2 |M_S_3 |M_S_4 |M_S_5 |M_S_6 |M_S_7 |M_S_8 |M_S_9 |M_S_0 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  M_S_SPC    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[SYMBOLS] = {
  {M(TERM), M(PASS), M(EMAL), _______, KC_PERC, _______, _______,   KC_PLUS, _______, _______, _______, _______ },
  {_______, M(DCON), _______, KC_LPRN, KC_RPRN, _______, KC_EQL,    KC_MINS, KC_LCBR, KC_RCBR, _______, KC_BSLS },
  {_______, F(S_1a),  F(S_2a),  F(S_3a),  F(S_4a),  F(S_5a),  F(S_6a),  F(S_7a),  F(S_8a),  F(S_9a),  F(S_0a),   _______},
  {KC_MPRV, KC_MNXT, KC_CAPS, _______, _______, M(S_SPC), M(S_SPC), _______, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU }
},

/* Typing Symbols
 * ,-----------------------------------------------------------------------------------.
 * |M_TERM|M_PASS|M_EMAL|      |   %  |      |   *  |   +  |   {  |   }  |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |   (  |   )  |      |   =  |   -  |   (  |   )  |      |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   /  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  M_S_SPC    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[T_SYMBOLS] = {
  {M(TERM), M(PASS), M(EMAL), _______, KC_PERC, _______, KC_ASTR, KC_PLUS, _______, _______, _______, _______ },
  {_______, M(DCON), _______, KC_LPRN, KC_RPRN, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______ },
  {_______, _______, _______, _______, KC_EQL,  _______, _______,  KC_MINS, _______, _______, _______, _______ },
  {KC_MNXT, KC_MPRV, KC_CAPS, _______, _______, M(S_SPC), M(S_SPC), _______, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU }
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   !  |   @  |   #  |   $  |   ^  |   %  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  ~   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |M_S_1 |M_S_2 |M_S_3 |M_S_4 |M_S_5 |M_S_6 |M_S_7 |M_S_8 |M_S_9 |M_S_0 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      _      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[NUMS] = {
  {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_CIRC, KC_PERC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  _______},
  {KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_PIPE},
  {_______, F(S_1a),  F(S_2a),  F(S_3a),  F(S_4a),  F(S_5a),  F(S_6a),  F(S_7a),  F(S_8a),  F(S_9a),  F(S_0a),   _______},
  {_______, _______, _______, KC_CAPS, _______, KC_UNDS, KC_UNDS, _______, _______, _______,  _______, _______}
},

/* POWER
 * ,-----------------------------------------------------------------------------------.
 * |      |      | Tab  |  Up  | Enter|  Ins | Home |      |   1  |   2  |   3  | bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Left | Down | Right| PgDn | PgUp |   *  |   4  |   5  |   6  |  +   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      | End  | Del  |   /  |   7  |   9  |   9  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   .  |   0  | Enter|      |
 * `-----------------------------------------------------------------------------------'
 */
[POWER] = {
  {_______, _______, KC_TAB,  KC_UP,   KC_ENT,   KC_INS,  KC_HOME, _______, KC_7,   KC_8,  KC_9,   TD(BSPC3)},
  {_______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_PGUP, KC_ASTR, KC_4,   KC_5,  KC_6,   KC_PLUS},
  {_______, SOUND1,  SOUND2,  SOUND3,  SOUND4,   KC_END,  KC_DEL,  KC_SLSH, KC_1,   KC_2,  KC_3,   KC_MINS},
  {_______, _______, _______, _______, _______,  _______, _______, _______, KC_ENT, KC_0, KC_DOT,  _______}
},

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[FUNC] = {
  {_______, _______,   _______, _______, _______, _______, _______,  _______, _______,  _______, _______, TD(BSPC4)},
  { KC_F1,  KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12},
  {_______, _______,   _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______},
  {_______, OSL(FUNC), _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______}
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

void persistent_default_layer_set(uint16_t default_layer){
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case  SOUND1:
      if (record->event.pressed) {

        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_startup, false, 0);
        #endif
      }
      return false;
      break;
    case  SOUND2:
      if (record->event.pressed) {

        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
      }
      return false;
      break;
    case  SOUND3:
      if (record->event.pressed) {

        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
      }
      return false;
      break;
    case  SOUND4:
      if (record->event.pressed) {

        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
        #endif
      }
      return false;
      break;
  }
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

void send_sound_1 (qk_tap_dance_state_t *state, void *user_data) {
    unregister_code (KC_BSPC);
  if (state->count == 2) {
    #ifdef AUDIO_ENABLE
      PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
    #endif
  }
}

void send_sound_2 (qk_tap_dance_state_t *state, void *user_data) {
    unregister_code (KC_BSPC);
  if (state->count == 2) {
    #ifdef AUDIO_ENABLE
      PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
    #endif
  }
}

void send_sound_3 (qk_tap_dance_state_t *state, void *user_data) {
    unregister_code (KC_BSPC);
  if (state->count == 2) {
    #ifdef AUDIO_ENABLE
      PLAY_NOTE_ARRAY(tone_colemak, false, 0);
    #endif
  }
}

void send_sound_4 (qk_tap_dance_state_t *state, void *user_data) {
    unregister_code (KC_BSPC);
  if (state->count == 2) {
    #ifdef AUDIO_ENABLE
      PLAY_NOTE_ARRAY(tone_plover, false, 0);
    #endif
  }
}

void send_back_space (qk_tap_dance_state_t *state, void *user_data) {
    unregister_code (KC_BSPC);
    register_code (KC_BSPC);
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [BSPC1]  = ACTION_TAP_DANCE_FN_ADVANCED(send_back_space, NULL, send_sound_1),
  [BSPC2]  = ACTION_TAP_DANCE_FN_ADVANCED(send_back_space, NULL, send_sound_2),
  [BSPC3]  = ACTION_TAP_DANCE_FN_ADVANCED(send_back_space, NULL, send_sound_3),
  [BSPC4]  = ACTION_TAP_DANCE_FN_ADVANCED(send_back_space, NULL, send_sound_4),
// Other declarations would go here, separated by commas, if you have them
};

#endif
