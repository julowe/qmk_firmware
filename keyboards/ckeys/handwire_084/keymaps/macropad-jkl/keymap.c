#include QMK_KEYBOARD_H

enum layers {
  _BASE,                // base layer
  _LAYERS,              // layer of all layers
  _MUSIC,               // music mode
  _MUSIC_4_LIFE,        // music mode until unplugged
  _MOUSE,               // mousekeys
//  _TERMINAL,            // terminal
  _ADMIN                // admin duties
};

enum custom_keycodes {
/*  TERM_ABOUT = SAFE_RANGE,
  TERM_PRINT,
  TERM_FLUSH,
  TERM_HELP, */
  CKEYS_ABOUT,
  W3_QUEN,
  W3_QUENLONG,
  W3_AXII,
  W3_AARD,
  W3_YRDEN,
  W3_IGNI,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE (numpad)
   * ,---    --------------------.
   * |  7      |  8  |  9  |  /  | <-- Hold for LAYERS
   * |---    --+-----+-----+-----|
   * |  4      |  5  |  6  |  *  |
   * |---    --+-----+-----+-----|
   * |  Yrden  |  Aard  |  3  |  -  |
   * |---    --+-----+-----+-----|
   * |  Quen   |  Axii  |  Igni  |  +  |
   * `---    ------------------- '
   */
  [_BASE] = LAYOUT(
    KC_KP_7, KC_KP_8, KC_KP_9, LT(MO(_LAYERS), KC_PSLS), \
    KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST,                  \
    W3_YRDEN, W3_AARD, KC_KP_3, KC_PMNS,                  \
    W3_QUEN, W3_AXII, W3_IGNI, KC_PPLS \
  ),
    /* LAYERS
   * ,---------------------------.
   * |  MUSIC  |     |     |  X  |
   * |---------+-----+-----+-----|
   * |  MOUSE  |     |     |     |
   * |---------+-----+-----+-----|
   * |         |     |     |     |
   * |---------+-----+-----+-----|
   * |  ADMIN  |     |     |     |
   * `---------------------------'
   */
  [_LAYERS] = LAYOUT(
    TG(_MUSIC),    _______, _______, _______, \
    TG(_MOUSE),    _______, _______, _______, \
    _______, _______, _______, _______, \
    TG(_ADMIN),    _______, _______, _______\
  ),
    /* MUSIC
   * ,-----------------------.
   * |  X  |     |     |  X  |
   * |-----+-----+-----+-----|
   * |     |     |     |4EVER|
   * |-----+-----+-----+-----|
   * | OFF |     |     |     |
   * |-----+-----+-----+-----|
   * |  ON |     |     |MODES|
   * `---------------------- '
   */
  // TODO: Make this music layer the one to jump to other music layers (different octaves)
  [_MUSIC] = LAYOUT(
    _______,  _______, _______, _______,             \
    _______,  _______, _______, TG(_MUSIC_4_LIFE), \
    MU_OFF,   _______, _______, _______,             \
    MU_ON,    _______, _______, MU_MOD \
  ),
    /* MUSIC_4_LIFE
   * ,-----------------------.
   * |  ♫  |  ♫  |  ♫  |  ♫  |
   * |-----+-----+-----+-----|
   * |  ♫  |  ♫  |  ♫  |  ♫  |
   * |-----+-----+-----+-----|
   * |  ♫  |  ♫  |  ♫  |  ♫  |
   * |-----+-----+-----+-----|
   * |  ♫  |  ♫  |  ♫  |  ♫  |
   * `---------------------- '
   */
  [_MUSIC_4_LIFE] = LAYOUT(
    KC_M, KC_M, KC_M, KC_M, \
    KC_M, KC_M, KC_M, KC_M, \
    KC_M, KC_M, KC_M, KC_M, \
    KC_M, KC_M, KC_M, KC_M \
  ),
    /* MOUSE
   * ,-------------------------------------------------.
   * |  BUTTON 5 |           | SCROLL UP  |     X      |
   * |-----------+-----------+------------+------------|
   * |     X     |LEFT CLICK |     UP     |RIGHT CLICK |
   * |-----------+-----------+------------+------------|
   * |  BUTTON 4 |   LEFT    |    DOWN    |   RIGHT    |
   * |-----------+-----------+------------+------=-----|
   * |  BUTTON 3 |SCROLL LEFT|SCROLL DOWN |SCROLL RIGHT|
   * `-------------------------------------------------'
   */
  [_MOUSE] = LAYOUT(
    KC_MS_BTN5, _______,       KC_MS_WH_UP,   _______,         \
    _______,    KC_MS_BTN1,    KC_MS_UP,      KC_MS_BTN2,    \
    KC_MS_BTN4, KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_RIGHT,   \
    KC_MS_BTN3, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT \
  ),
    /* TERMINAL
   * ,---------------------------------------.
   * |            |ABOUT|          |    X    |
   * |------------+-----+----------+---------|
   * |TERMINAL OFF|PRINT|          |         |
   * |------------+-----+----------+---------|
   * |     X      |FLUSH|          |         |
   * |------------+-----+----------+---------|
   * |TERMINAL ON |HELP |          |         |
   * `--------=======------------------------'
   */
  /* remove terminal layer for comilation 'fix'
  [_TERMINAL] = LAYOUT(
    _______,    TERM_ABOUT, _______, _______, \
    TERM_OFF,   TERM_PRINT, _______, _______, \
    _______,    TERM_FLUSH, _______, _______, \
    TERM_ON,    TERM_HELP , _______, _______\
  ),
  */
    /* ADMIN
   * ,-----------------------------------------.
   * |   RESET    |     |           |    X     |
   * |------------+-----+-----------+----------|
   * |ABOUT CKEYS |     |           |          |
   * |------------+-----+-----------+----------|
   * |            |     |CLICKY UP  |CLICKY OFF|
   * |------------+-----+-----------+----------|
   * |     X      |     |CLICKY DOWN|CLICKY ON |
   * `-----------------------------------------'
   */
  [_ADMIN] = LAYOUT(
    RESET,       _______, _______, _______,  \
    CKEYS_ABOUT, _______, _______, _______,  \
    _______,     _______, _______, CK_OFF, \
    _______,     _______, _______, CK_ON \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
/*    case TERM_ABOUT:
      if (record->event.pressed) {
        // when keycode TERM_ABOUT is pressed
        SEND_STRING("about"SS_TAP(X_ENTER));
      } else {
        // when keycode TERM_ABOUT is released
      }
      break;
    case TERM_PRINT:
      if (record->event.pressed) {
        SEND_STRING("print"SS_TAP(X_ENTER));
      } else { }
      break;
    case TERM_FLUSH:
      if (record->event.pressed) {
        SEND_STRING("flush"SS_TAP(X_ENTER));
      } else { }
      break;
    case TERM_HELP:
      if (record->event.pressed) {
        SEND_STRING("help"SS_TAP(X_ENTER));
      } else { }
      break; */
    case CKEYS_ABOUT:
      if (record->event.pressed) {
        SEND_STRING("https://cKeys.org"SS_TAP(X_ENTER)"Making people smile one keyboard at a time."SS_TAP(X_ENTER)"cKeys is a volunteer-run 501(c)(3) nonprofit organization."SS_TAP(X_ENTER));
      } else { }
      break;
    case W3_QUEN:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_6) SS_DELAY(50) SS_UP(X_6) SS_DELAY(50) SS_DOWN(X_Q) SS_DELAY(50) SS_UP(X_Q));
      } else { }
      break;
    //learn how to do event on press and another on release of key
    case W3_QUENLONG:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_6) SS_DELAY(50) SS_UP(X_6) SS_DELAY(50) SS_DOWN(X_Q) SS_DELAY(50) SS_UP(X_Q));
      } else { }
      break;
    case W3_AXII:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_7) SS_DELAY(50) SS_UP(X_7) SS_DELAY(50) SS_DOWN(X_Q) SS_DELAY(50) SS_UP(X_Q));
      } else { }
      break;
    case W3_AARD:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_3) SS_DELAY(50) SS_UP(X_3) SS_DELAY(50) SS_DOWN(X_Q) SS_DELAY(50) SS_UP(X_Q));
      } else { }
      break;
    case W3_YRDEN:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_4) SS_DELAY(50) SS_UP(X_4) SS_DELAY(50) SS_DOWN(X_Q) SS_DELAY(50) SS_UP(X_Q));
      } else { }
      break;
    case W3_IGNI:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_5) SS_DELAY(50) SS_UP(X_5) SS_DELAY(50) SS_DOWN(X_Q) SS_DELAY(50) SS_UP(X_Q));
      } else { }
      break;
  }
  return true;
};
