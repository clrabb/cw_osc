#include "speaker.h"
#include <Arduino.h>

speaker::speaker()
{
}

void
speaker::beat()
{
    int tone_value = analogRead( A0 );
    Serial.print( "tone: " );
    Serial.println( tone_value );
}