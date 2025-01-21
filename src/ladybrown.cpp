#include "main.h"

const int numStates = 3;
int states[numStates] = {0, 300, 2000};
int currState = 0;
int target = 0;

void nextState() {
    currState += 1;
    if (currState == numStates) {
        currState = 0;
    }
    target = states[currState];
}

void liftControl() {
    double kp = 0.5;
    double error = target - rotator.get_position();
    double velocity = kp * error;
    lift.move(velocity);
}