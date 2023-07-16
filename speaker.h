#ifndef SPEAKER_H
#define SPEAKER_H

class speaker
{
private:
    unsigned short m_tone_pin;

public:
    speaker();
    unsigned short tone_pin() { return this->m_tone_pin; }
    void beat();

private:
    speaker( const speaker& );
    speaker& operator=( const speaker& );
};

#endif // SPEAKER_H