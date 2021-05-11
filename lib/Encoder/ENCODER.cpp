#include "ENCODER.h"

ENCODER::ENCODER()
{
}

ENCODER::~ENCODER()
{
}

void ENCODER::begin(int pins[2], int pulses_per_revolution)
{
    _pins[0] = pins[0];
    _pins[1] = pins[1];
    radians_per_interruption = 6.283185 / pulses_per_revolution;
    pinMode(_pins[0], INPUT_PULLUP);
    pinMode(_pins[1], INPUT_PULLUP);
}

void ENCODER::interruption_1()
{
    interruption = true;
    number_of_interruptions += 1;
    
    if (digitalRead(_pins[1]) == LOW)
    {
        direction = COUNTERCLOCKWISE;
    }

    else
    {
        direction = CLOCKWISE;
    }
}

void ENCODER::calculate_velocity()
{
    delta_time = time[1] - time[0];
    angular_velocity = 1000 * radians_per_interruption / (delta_time);
}

void ENCODER::calculate_position()
{
    position = number_of_interruptions * radians_per_interruption;
}