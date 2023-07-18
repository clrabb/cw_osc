#include "speaker.h"
#include "tone_constants.h"
#include "constants.h"
#include <Arduino.h>

namespace cw_osc
{
    speaker::speaker()
    {
        this->fill_tones();
    }

    speaker::~speaker()
    {
        free( this->m_tones );
    }

    void 
    speaker::fill_tones()
    {    
        m_tones[0] = NOTE_B0;
        m_tones[1] = NOTE_C1;
        m_tones[2] = NOTE_CS1;
        m_tones[3] = NOTE_D1;
        m_tones[4] = NOTE_DS1;
        m_tones[5] = NOTE_E1;
        m_tones[6] = NOTE_F1;
        m_tones[7] = NOTE_FS1;
        m_tones[8] = NOTE_G1;
        m_tones[9] = NOTE_GS1;
        m_tones[10] = NOTE_A1;
        m_tones[11] = NOTE_AS1;
        m_tones[12] = NOTE_B1;
        m_tones[13] = NOTE_C2;
        m_tones[14] = NOTE_CS2;
        m_tones[15] = NOTE_D2;
        m_tones[16] = NOTE_DS2;
        m_tones[17] = NOTE_E2;
        m_tones[18] = NOTE_F2;
        m_tones[19] = NOTE_FS2;
        m_tones[20] = NOTE_G2;
        m_tones[21] = NOTE_GS2;
        m_tones[22] = NOTE_A2;
        m_tones[23] = NOTE_AS2;
        m_tones[24] = NOTE_B2;
        m_tones[25] = NOTE_C3;
        m_tones[26] = NOTE_CS3;
        m_tones[27] = NOTE_D3;
        m_tones[28] = NOTE_DS3;
        m_tones[29] = NOTE_E3;
        m_tones[30] = NOTE_F3;
        m_tones[31] = NOTE_FS3;
        m_tones[32] = NOTE_G3;
        m_tones[33] = NOTE_GS3;
        m_tones[34] = NOTE_A3;
        m_tones[35] = NOTE_AS3;
        m_tones[36] = NOTE_B3;
        m_tones[37] = NOTE_C4;
        m_tones[38] = NOTE_CS4;
        m_tones[39] = NOTE_D4;
        m_tones[40] = NOTE_DS4;
        m_tones[41] = NOTE_E4;
        m_tones[42] = NOTE_F4;
        m_tones[43] = NOTE_FS4;
        m_tones[44] = NOTE_G4;
        m_tones[45] = NOTE_GS4;
        m_tones[46] = NOTE_A4;
        m_tones[47] = NOTE_AS4;
        m_tones[48] = NOTE_B4;
        m_tones[49] = NOTE_C5;
        m_tones[50] = NOTE_CS5;
        m_tones[51] = NOTE_D5;
        m_tones[52] = NOTE_DS5;
        m_tones[53] = NOTE_E5;
        m_tones[54] = NOTE_F5;
        m_tones[55] = NOTE_FS5;
        m_tones[56] = NOTE_G5;
        m_tones[57] = NOTE_GS5;
        m_tones[58] = NOTE_A5;
        m_tones[59] = NOTE_AS5;
        m_tones[60] = NOTE_B5;
        m_tones[61] = NOTE_C6;
        m_tones[62] = NOTE_CS6;
        m_tones[63] = NOTE_D6;
        m_tones[64] = NOTE_DS6;
        m_tones[65] = NOTE_E6;
        m_tones[66] = NOTE_F6;
        m_tones[67] = NOTE_FS6;
        m_tones[68] = NOTE_G6;
        m_tones[69] = NOTE_GS6;
        m_tones[70] = NOTE_A6;
        m_tones[71] = NOTE_AS6;
        m_tones[72] = NOTE_B6;
        m_tones[73] = NOTE_C7;
        m_tones[74] = NOTE_CS7;
        m_tones[75] = NOTE_D7;
        m_tones[76] = NOTE_DS7;
        m_tones[77] = NOTE_E7;
        m_tones[78] = NOTE_F7;
        m_tones[79] = NOTE_FS7;
        m_tones[80] = NOTE_G7;
        m_tones[81] = NOTE_GS7;
        m_tones[82] = NOTE_A7;
        m_tones[83] = NOTE_AS7;
        m_tones[84] = NOTE_B7;
        m_tones[85] = NOTE_C8;
        m_tones[86] = NOTE_CS8;
        m_tones[87] = NOTE_D8;
        m_tones[88] = NOTE_DS8;  
    }

    void
    speaker::tone_on()
    {
        if ( this->is_on() )
        {
            Serial.println( "Already on - bailing" );
            return;
        }

        int pot_value = analogRead( A0 );
        if( pot_value > MAX_TONE_POT_VALUE )
          pot_value = MAX_TONE_POT_VALUE;

        int tone_idx = map( pot_value, 1, MAX_TONE_POT_VALUE, 1, NUM_TONES );
        int tone_value = this->m_tones[ tone_idx ];
        

        Serial.print( " Pot value: " );
        Serial.print( pot_value );
        Serial.print( " tone index: " );
        Serial.print( tone_idx );
        Serial.print( " Tone value: " );
        Serial.println( tone_value );

        tone( TONE_PIN, tone_value );
        this->is_on( true );
    }

    void
    speaker::tone_off()
    {
        if ( this->is_off() )
            return;
        else
        {
            noTone( TONE_PIN );
            this->is_on( false );
        }    
    }
}


