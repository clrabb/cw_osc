#include "key_state_down.h"
#include "constants.h"
#include "singleton_t.h"
#include "speaker.h"

using namespace cw_osc;


void
key_state_down::beat()
{
    if ( this->mills_since_state_change() > KEY_DOWN_TUNE_THRESHOLD )
    {
        speaker& s = singleton_t< speaker >::instance();
        s.set_tone_from_pot();
    }
}

void
key_state_down::mark_entering_state()
{
    key_state_abc::mark_entering_state();
    speaker& s = singleton_t< speaker >::instance();
    s.tone_on();
}
