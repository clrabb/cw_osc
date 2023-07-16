#ifndef KEY_H
#define KEY_H

#include "speaker.h"

class key
{
private:
    unsigned long m_last_press_millis;
    unsigned short m_key_pin;
    speaker m_speaker;

public:
    key( unsigned short key_pin );

    void beat();
    unsigned long last_press_millis();
    void last_press_millis( unsigned long millis );
    unsigned short key_pin();
    const speaker& speaker();
    bool is_pressed();


private:
    key( const key& );
    key& operator=( const key& );
};

#endif // KEY_H