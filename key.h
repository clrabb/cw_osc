#ifndef KEY_H
#define KEY_H

#include "key_state_abc.h"

namespace cw_osc
{

    class key
    {
    private:
        unsigned long m_last_press_millis;
        unsigned short m_key_pin;
        key_state_abc* m_state_up;
        key_state_abc* m_state_down;
        key_state_abc* m_current_state;
        bool m_is_tone_on;

    public:
        key( unsigned short key_pin );
        ~key();

        void beat();
        unsigned short key_pin();
        key_state_abc* state_up() { return this->m_state_up; }
        key_state_abc* state_down() { return this->m_state_down; }
        key_state_abc* current_state() { return this->m_current_state; }
        
        bool is_key_pin_high();
        bool is_key_pin_low();

    private:
        void current_state( key_state_abc* state );

    private:
        key( const key& );
        key& operator=( const key& );
    };

}

#endif // KEY_H