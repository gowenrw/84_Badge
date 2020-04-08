// Blink LEDs alternating between groups

#include <ch554.h>
#include <debug.h>

#define LEDY30_PIN 0
#define LEDR31_PIN 1
#define LEDB32_PIN 2
#define LEDR33_PIN 3
#define LEDR34_PIN 4

#define LEDB14_PIN 4
#define LEDY15_PIN 5
#define LEDB16_PIN 6
#define LEDB17_PIN 7

#define BUTTON11_PIN 1

// P1 = 0x90 P3 = 0xB0
SBIT(LEDY30, 0xB0, LEDY30_PIN);
SBIT(LEDR31, 0xB0, LEDR31_PIN);
SBIT(LEDB32, 0xB0, LEDB32_PIN);
SBIT(LEDR33, 0xB0, LEDR33_PIN);
SBIT(LEDR34, 0xB0, LEDR34_PIN);
SBIT(LEDB14, 0x90, LEDB14_PIN);
SBIT(LEDY15, 0x90, LEDY15_PIN);
SBIT(LEDB16, 0x90, LEDB16_PIN);
SBIT(LEDB17, 0x90, LEDB17_PIN);
SBIT(BUTTON11, 0x90, BUTTON11_PIN);

void main() {
    CfgFsys();

    P3_DIR_PU &= 0x0C;
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

    P1_DIR_PU &= 0x0C;
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

    while (1) {
      // Setting the LEDs to on or off
      LEDY30 = 1;
      LEDY15 = 1;
      LEDR31 = 0;
      LEDR33 = 0;
      LEDR34 = 0;
      LEDB32 = 0;
      LEDB14 = 0;
      LEDB16 = 0;
      LEDB17 = 0;
      // Delay controls blink speed
      mDelaymS(300);
      // Setting the LEDs to on or off
      LEDY30 = 0;
      LEDY15 = 0;
      LEDR31 = 1;
      LEDR33 = 1;
      LEDR34 = 1;
      LEDB32 = 0;
      LEDB14 = 0;
      LEDB16 = 0;
      LEDB17 = 0;
      // Delay controls blink speed
      mDelaymS(300);
      // Setting the LEDs to on or off
      LEDY30 = 0;
      LEDY15 = 0;
      LEDR31 = 0;
      LEDR33 = 0;
      LEDR34 = 0;
      LEDB32 = 1;
      LEDB14 = 1;
      LEDB16 = 1;
      LEDB17 = 1;
      // Delay controls blink speed
      mDelaymS(300);
    }
}
