#include <arduino.h>
#include "key.h"
#include "speaker.h"

using namespace cw_osc;

key::key( unsigned short key_pin ) 
    :
    m_key_pin( key_pin ),
    m_last_press_millis( 0 )
{
    this->m_speaker = new cw_osc::speaker();
    pinMode( key_pin, INPUT );
}

key::~key()
{
    delete this->m_speaker;
}

void 
key::last_press_millis( unsigned long millis )
{
    this->m_last_press_millis = millis;
}

unsigned long 
key::last_press_millis()
{
    return this->m_last_press_millis;
}

unsigned short
key::key_pin()
{
    return this->m_key_pin;
}

bool 
key::is_key_down()
{
    return !( this->is_key_up() );
}

bool
key::is_key_up()
{
    return digitalRead( this->key_pin() );
}

void
key::beat()
{
    if ( this->is_key_down() )
    {
        if ( 0 == this->last_press_millis() && millis() - this->last_press_millis() )
        {
            this->last_press_millis( millis() );
        }

        this->speaker()->tone_on();
    }
    else if ( this->is_key_up() )
    {
        // shut off the tone
        this->last_press_millis( 0 );
        this->speaker()->tone_off();
    }
}

const speaker*
key::speaker()
{
    return this->m_speaker;
}