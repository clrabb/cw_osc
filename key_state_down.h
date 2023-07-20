#ifndef KEY_STATE_DOWN_H
#define KEY_STATE_DOWN_H

#include "key_state_abc.h"
#include "speaker.h"

namespace cw_osc
{
    class key_state_down : public key_state_abc
    {
    public:
        key_state_down(){}
        bool is_down() { return true; }
        void beat();

        virtual void mark_entering_state();   

    private:
        key_state_down( const key_state_down& );
        key_state_down& operator=( const key_state_down& );
    };
}



#endif // KEY_STATE_DOWN_H