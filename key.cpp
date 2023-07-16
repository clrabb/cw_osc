#include <arduino.h>
#include "key.h"


key::key( unsigned short key_pin ) 
    :
    m_key_pin( key_pin ),
    m_last_press_millis( 0 )
{
    pinMode( key_pin, INPUT );
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
key::is_pressed()
{
    return !( digitalRead( this->key_pin() ) );
}

void
key::beat()
{
    bool pressed = this->is_pressed();
}

const speaker&
key::speaker()
{
    return this->m_speaker;
}