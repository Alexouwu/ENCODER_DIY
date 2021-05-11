#include <Arduino.h>

#define CLOCKWISE 1
#define COUNTERCLOCKWISE 0

class ENCODER
{
private:
    
public:
    uint32_t number_of_interruptions = 0;
    bool interruption;
    byte _pins[2];
    int direction = CLOCKWISE;
    double angular_velocity = 0;
    double radians_per_interruption;
    unsigned long time[2], delta_time;
    double position = 0;
    ENCODER();
    ~ENCODER();
    void interruption_1();
    void begin(int pins[2], int pulses_per_revolution);
    void calculate_velocity();
    void calculate_position();
};