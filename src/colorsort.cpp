#include "main.h"
#include "subsystems.hpp"

#define BLUE_HUE_MIN 210
#define BLUE_HUE_MAX 225


 void ejectblue() {

    // Turn on LED for better color detection
    colorsorter.set_led_pwm(100);

    // Continuous loop for detection
    while (true) {
        // Get hue value from the optical sensor
        double hue = colorsorter.get_hue();

        // Check if the hue is in the range for red
        if (hue >= BLUE_HUE_MIN && hue <= BLUE_HUE_MAX) {
            // Activate piston when a red ring is detected
            intake.move(0);

            // Wait to avoid multiple activations for the same ring
            pros::delay(500); // add delay

            // Deactivate piston after a short duration
            intake.move(127);
        }

        // Short delay for sensor reading stability
        pros::delay(20);
    }
}






