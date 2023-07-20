#ifndef SPEAKER_H
#define SPEAKER_H

#include "tone_constants.h"

namespace cw_osc
{

    class speaker
    {

    private:
        unsigned short m_tone_pin;
        bool m_is_on;
        short m_current_tone;
        short m_tones[ NUM_TONES ];

    public:
        speaker();
        ~speaker();

        unsigned short tone_pin() { return this->m_tone_pin; }
        void tone_on();
        void tone_off();
        bool is_on() { return this->m_is_on; }
        bool is_off() { return !( this->is_on() ); }
        void is_on( bool on ) { this->m_is_on = on; }
        const int* tones() { return this->m_tones; }
        short current_tone() { return this->m_current_tone; }
        void current_tone( short tone ) { this->m_current_tone = tone; }
        short read_tone_from_pot();
        void set_tone_from_pot();

    private:
        void fill_tones();

    private:
        speaker( const speaker& );
        speaker& operator=( const speaker& );
    };

}

#endif // SPEAKER_H