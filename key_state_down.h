#ifndef KEY_STATE_DOWN_H
#define KEY_STATE_DOWN_H

#include "key_state_abc.h"

namespace cw_osc
{
    class key_state_down : key_state_abc
    {
    public:
        bool is_down() { return true; }
        
    };
}



#endif // KEY_STATE_DOWN_H