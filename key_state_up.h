#ifndef KEY_STATE_UP_H
#define KEY_STATE_UP_H

#include "key_state_abc.h"

namespace cw_osc
{
    class key_state_up : public key_state_abc
    {
    public:
        key_state_up();
        virtual void mark_entering_state();

    private:
        key_state_up( const key_state_up& );
        key_state_up& operator=( const key_state_up& );
    };
}


#endif // KEY_STATE_UP_H