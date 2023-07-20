#ifndef  KEY_STATE_ABC_H
#define KEY_STATE_ABC_H

namespace cw_osc
{
    class key;

    class key_state_abc
    {
    private:
        unsigned long m_state_change_time;
    
    public:
        key_state_abc();
        ~key_state_abc(){}

        unsigned long state_change_time() { return this->m_state_change_time; }
        unsigned long mills_since_state_change();
        virtual bool is_down() { return false; }
        virtual bool is_up() { return false; }
        virtual void beat(){}
        virtual void mark_leaving_state();
        virtual void mark_entering_state();


    private:
        void state_change_time( unsigned long time ) { this->m_state_change_time = time; }
        void clear_state_change_time() { this->m_state_change_time = 0; }     

    private:
        key_state_abc( const key_state_abc& );
        key_state_abc& operator=( const key_state_abc& );
    };
}

#endif // KEY_STATE_ABC_H