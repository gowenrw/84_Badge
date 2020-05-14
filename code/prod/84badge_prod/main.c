// 84 Badge
// This is the main production code for the badge

#include <ch554.h>
#include <debug.h>

// define the sub-pins for pin 3
#define LEDY30_PIN 0
#define LEDR31_PIN 1
#define LEDB32_PIN 2
#define LEDR33_PIN 3
#define LEDR34_PIN 4
// define the sub-pins for pin 1
#define BUTTON11_PIN 1
#define LEDB14_PIN 4
#define LEDY15_PIN 5
#define LEDB16_PIN 6
#define LEDB17_PIN 7

// assign sub-pins to pins
// P1 = 0x90 P3 = 0xB0
SBIT(LEDY30, 0xB0, LEDY30_PIN);
SBIT(LEDR31, 0xB0, LEDR31_PIN);
SBIT(LEDB32, 0xB0, LEDB32_PIN);
SBIT(LEDR33, 0xB0, LEDR33_PIN);
SBIT(LEDR34, 0xB0, LEDR34_PIN);
SBIT(BUTTON11, 0x90, BUTTON11_PIN);
SBIT(LEDB14, 0x90, LEDB14_PIN);
SBIT(LEDY15, 0x90, LEDY15_PIN);
SBIT(LEDB16, 0x90, LEDB16_PIN);
SBIT(LEDB17, 0x90, LEDB17_PIN);

// 1 byte integer for putton push flag - no bool type available
uint8_t button11push=0;

// 1 byte integer for LED Mode (controlled by button)
// Modes 1 is the default start mode
uint8_t ledmode=1;

void main() {
    CfgFsys();

    // setup pin 3
    // Configure pin 3.0 as GPIO output
    P3_MOD_OC = P3_MOD_OC & ~(1<<LEDY30_PIN);
    P3_DIR_PU = P3_DIR_PU |	(1<<LEDY30_PIN);
    // Configure pin 3.1 as GPIO output
    P3_MOD_OC = P3_MOD_OC & ~(1<<LEDR31_PIN);
    P3_DIR_PU = P3_DIR_PU |	(1<<LEDR31_PIN);
    // Configure pin 3.2 as GPIO output
    P3_MOD_OC = P3_MOD_OC & ~(1<<LEDB32_PIN);
    P3_DIR_PU = P3_DIR_PU |	(1<<LEDB32_PIN);
    // Configure pin 3.3 as GPIO output
    P3_MOD_OC = P3_MOD_OC & ~(1<<LEDR33_PIN);
    P3_DIR_PU = P3_DIR_PU |	(1<<LEDR33_PIN);
    // Configure pin 3.4 as GPIO output
    P3_MOD_OC = P3_MOD_OC & ~(1<<LEDR34_PIN);
    P3_DIR_PU = P3_DIR_PU |	(1<<LEDR34_PIN);

    // setup pin 1
    // Configure pin 1.4 as GPIO output
    P1_MOD_OC = P1_MOD_OC & ~(1<<LEDB14_PIN);
    P1_DIR_PU = P1_DIR_PU |	(1<<LEDB14_PIN);
    // Configure pin 1.5 as GPIO output
    P1_MOD_OC = P1_MOD_OC & ~(1<<LEDY15_PIN);
    P1_DIR_PU = P1_DIR_PU |	(1<<LEDY15_PIN);
    // Configure pin 1.6 as GPIO output
    P1_MOD_OC = P1_MOD_OC & ~(1<<LEDB16_PIN);
    P1_DIR_PU = P1_DIR_PU |	(1<<LEDB16_PIN);
    // Configure pin 1.7 as GPIO output
    P1_MOD_OC = P1_MOD_OC & ~(1<<LEDB17_PIN);
    P1_DIR_PU = P1_DIR_PU |	(1<<LEDB17_PIN);

    // Setting all LEDs to off at start
    LEDY30 = 0;
    LEDY15 = 0;
    LEDR31 = 0;
    LEDR33 = 0;
    LEDR34 = 0;
    LEDB32 = 0;
    LEDB14 = 0;
    LEDB16 = 0;
    LEDB17 = 0;

    // ********************************
    // ********* Primary Loop *********
    // ********************************
    while (1) {
        // ********************************
        // ********** LED MODE 3 **********
        // ********************************
        if (ledmode == 3) {
          // *****
          // ***** This mode keeps all LEDs ON
          // *****
          // Delay to display previous LED state
          mDelaymS(300);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY30 = 1, LEDY15 = 1, LEDR31 = 1, LEDR33 = 1, LEDR34 = 1, LEDB32 = 1, LEDB14 = 1, LEDB16 = 1, LEDB17 = 1;
          // ***** End of this LED mode
        }
        // ********************************
        // ********** LED MODE 2 **********
        // ********************************
        if (ledmode == 2) {
          // *****
          // ***** This mode blinks LEDs in color groups
          // *****
          // Delay to display previous LED state
          mDelaymS(300);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY30 = 1, LEDY15 = 1, LEDR31 = 0, LEDR33 = 0, LEDR34 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(300);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY30 = 0, LEDY15 = 0, LEDR31 = 1, LEDR33 = 1, LEDR34 = 1, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(300);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY30 = 0, LEDY15 = 0, LEDR31 = 0, LEDR33 = 0, LEDR34 = 0, LEDB32 = 1, LEDB14 = 1, LEDB16 = 1, LEDB17 = 1;
          // ***** End of this LED mode
        }
        // ********************************
        // ********** LED MODE 1 **********
        // ********************************
        if (ledmode == 1) {
          // *****
          // ***** This mode is the LED artwork mode
          // ***** It should alternate Yellow LEDs on the lasso for a glow effect
          // ***** It should chase Blue LEDs on the lazers for a shooting effect
          // ***** It should use Red LEDs on the eye and explosions as lazers hit
          // *****
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 0, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 0, LEDB32 = 1, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 0, LEDB32 = 1, LEDB14 = 1, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 0, LEDB32 = 0, LEDB14 = 1, LEDB16 = 1, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 1, LEDB17 = 1;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 1;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 1, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 1, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 0, LEDR33 = 1, LEDR34 = 1, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 1, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 1, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 0, LEDR31 = 1, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 1, LEDR34 = 1, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 0, LEDR34 = 0, LEDR31 = 1, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // Delay to display previous LED state
          mDelaymS(70);
          // If we see button push set button push flag
          if (BUTTON11 == 0) { button11push = 1; }
          // ***** Set LED states to on or off
          LEDY15 = 1, LEDY30 = 1, LEDR33 = 0, LEDR34 = 1, LEDR31 = 0, LEDB32 = 0, LEDB14 = 0, LEDB16 = 0, LEDB17 = 0;
          // *****
          // ***** End of this LED mode
          // *****
        }
        // ********************************
        // ***** LED MODE ADJUSTMENTS *****
        // ********************************
        // If button was pushed during the cycle above then flag should be set
        if (button11push == 1) {
          // Increase LED Mode value
          ledmode = ledmode + 1;
          // Check if LED Mode value is beyond max value and if so set to min value
          if (ledmode > 3) { ledmode = 1; }
          // Reset button push flag
          button11push = 0;
        }
        // ********************************
        // ****** END OF MODE LOOPS *******
        // ********************************
    }
    // ********************************
    // ***** END OF PRIMARY LOOP ******
    // ********************************
}
