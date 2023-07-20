#include <Arduino.h>
#include "key_state_abc.h"


using namespace cw_osc;

key_state_abc::key_state_abc()
  :
    m_creation_time( millis() )
{

}

unsigned long
key_state_abc::mills_since_creation()
{
    return millis() - this->creation_time();
}

void
key_state_abc::beat()
{
    // This space intentionally left blank
}