/**
 * StepperMotor.h
 * 
 * @author: Wilson Tovar <twilson@uninorte.edu.co> github.com/krthr
 * @version: 0.1.0 6/11/2019
 * 
 * Every time measure is made using microseconds.
 */

#ifndef StepperMotor_h
#define StepperMotor_h

#include "Arduino.h"

class StepperMotor
{
public:
    StepperMotor(int id, int p, int dir, int en);
    StepperMotor(int id, int p, int dir, int en, int interval);
    StepperMotor() = default;

    int id;
    int dir;
    int total_steps;
    int actual_steps;
    int interval;
    int state;
    bool moving;

    void nextStep(unsigned long current_micros);
    void nextStep();
    void resetSteps();
    void stopMotor();

    void setSteps(long long steps);
    void setDir(int dir);
    void setInterval(unsigned long interval);

private:
    unsigned long last_micros;
    int _pulse_pin;
    int _dir_pin;
    int _enable_pin;
};

#endif
