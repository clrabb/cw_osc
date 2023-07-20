#include "key_state_up.h"
#include "singleton_t.h"
#include "speaker.h"

using namespace cw_osc;

key_state_up::key_state_up()
{
}

void
key_state_up::mark_entering_state()
{
    key_state_abc::mark_entering_state();
    speaker& s = singleton_t< speaker >::instance();
    s.tone_off();
}
