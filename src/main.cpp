#include <Arduino.h>
#include "ENCODER.h"

ENCODER encoder;
int ENCODER_PINS[2] = {2, 3};
int pulses_per_revolution = 3;
bool take_velocity;

void interrupt_1()
{
  encoder.interruption_1();
}

void setup()
{
  encoder.begin(ENCODER_PINS, pulses_per_revolution);
  take_velocity = false;
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(encoder._pins[0]), interrupt_1, RISING);
}

void loop()
{

  if (encoder.interruption)
  {
    if (take_velocity)
    {
      encoder.time[1] = millis();
      encoder.calculate_velocity();
      take_velocity = false;
    }

    else
    {
      take_velocity = true;
      encoder.time[0] = millis();
      
    }

    encoder.interruption = false;

    encoder.calculate_position();
    
    Serial.println(encoder.angular_velocity);
    Serial.println(encoder.position);
    Serial.println(encoder.direction);
  }
}