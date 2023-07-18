#include "singleton_t.h"
#include "constants.h"
#include "heartbeat.h"
#include "key.h"
#include "tone_constants.h"

using namespace cw_osc;

void play_tones() {
    int melody[] = {
      NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
    };

    int noteDurations[] = {
      4, 8, 8, 4, 4, 4, 4, 4
    };

    for (int thisNote = 0; thisNote < 8; thisNote++) {
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone( TONE_PIN, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone( TONE_PIN );
  }
}

void setup() {
    // put your setup code here, to run once:
    init_singletons();
    Serial.begin(9600);

    delay(2000);
    play_tones();
}

void init_singletons() {
    singleton_t< heartbeat > hb(new heartbeat(LED_PIN, LED_MILLS_OFF, LED_MILLS_ON));
    singleton_t< key > k( new key( KEY_PIN ) );
}

void loop() {
    // put your main code here, to run repeatedly:
    heartbeat& hb = singleton_t< heartbeat >::instance();
    hb.beat();

    key& k = singleton_t< key >::instance();
    k.beat();
}
