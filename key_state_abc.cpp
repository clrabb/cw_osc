#include <Arduino.h>
#include "key_state_abc.h"
#include "key.h"


using namespace cw_osc;

key_state_abc::key_state_abc()
  :
    m_state_change_time( millis() )
{

}

unsigned long
key_state_abc::mills_since_state_change()
{
    return millis() - this->state_change_time();
}

void
key_state_abc::mark_leaving_state()
{
    this->clear_state_change_time();
}

void
key_state_abc::mark_entering_state()
{
    this->state_change_time( millis() );
}