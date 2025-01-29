#include "main.h"
#include "ladybrown.hpp"

const int numStates = 3;
int states[numStates] = {0, 36, 160};
int currState = 0;
double target = 0;

void nextState() {
    currState += 1;
    if (currState == numStates) {
        currState = 0;
    }
    target = states[currState];
}

void liftControl() {
    double kp = 2;
    double error = target - rotator.get_position();
    double velocity = kp * error;
    lift.move(velocity);
}