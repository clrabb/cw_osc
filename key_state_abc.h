#ifndef  KEY_STATE_ABC_H
#define KEY_STATE_ABC_C

namespace cw_osc
{
    class key_state_abc
    {
    private:
        unsigned long m_creation_time;
    
    public:
        key_state_abc();
        ~key_state_abc(){}

        unsigned long creation_time() { return this->m_creation_time; }
        unsigned long mills_since_creation();
        virtual bool is_down() { return false; }
        virtual bool is_up() { return false; }
        virtual void beat();

    private:
        key_state_abc( const key_state_abc& );
        key_state_abc& operator=( const key_state_abc& );
    };
}

#endif // KEY_STATE_ABC_H