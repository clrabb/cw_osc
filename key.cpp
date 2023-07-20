#include <arduino.h>
#include "key.h"
#include "key_state_down.h"
#include "key_state_up.h"


using namespace cw_osc;

key::key( unsigned short key_pin ) 
    :
    m_key_pin( key_pin ),
    m_state_down( new key_state_down() ),
    m_state_up( new key_state_up() )
{
    this->current_state( this->state_up() );
    pinMode( key_pin, INPUT );
}

key::~key()
{
    delete this->state_down();
    delete this->state_up();
}


unsigned short
key::key_pin()
{
    return this->m_key_pin;
}

bool 
key::is_key_pin_low()
{
    return !( this->is_key_pin_high() );
}

bool
key::is_key_pin_high()
{
    return HIGH == digitalRead( this->key_pin() );
}

void
key::current_state( key_state_abc* state )
{
    this->current_state()->mark_leaving_state();
    this->current_state( state );
    this->current_state()->mark_entering_state();
}

void
key::beat()
{
    if ( this->current_state()->is_up() && this->is_key_pin_low() )
    {
        this->current_state( this->state_down() );
    }
    else if ( this->current_state()->is_down() && this->is_key_pin_high() )
    {
        this->current_state( this->state_up() );
    }

    this->current_state()->beat();
}
