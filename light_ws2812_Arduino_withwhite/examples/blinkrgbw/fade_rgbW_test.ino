#include <cRGBW.h>

/*
 * light_ws2812 example
 * Fade LEDs in R, G, B order; demonstrate functions for changing color order.
 *
 * Created: September 6, 2014
 * Author: Windell Oskay (www.evilmadscientist.com)
 */

#include <WS2812w.h>

#define outputPin 10  // Digital output pin (default: 7)
#define LEDCount 40   // Number of LEDs to drive (default: 9)


WS2812W LED(LEDCount); 
cRGB value;

byte intensity;
byte sign;

void setup() {
	  LED.setOutput(outputPin); // Digital Pin 7

	/* You may uncomment one of the following three lines to switch 
	to a different data transmission sequence for your addressable LEDs.
	(These functions can be used at any point in your program as needed.)   */

	//LED.setColorOrderRGB();  // Uncomment for RGB color order
	//LED.setColorOrderBRG();  // Uncomment for BRG color order
  //LED.setColorOrderGRB();  // Uncomment for GRB color order (Default; will be used if none other is defined.)
  LED.setColorOrderGRBW();  // Uncomment for GRB color order (Default; will be used if none other is defined.)

	intensity = 0;
	sign = 1;
}


void loop() {
  value.b = 255; value.g = 0; value.r = 0; value.w = 0; // RGB Value -> Blue
  LED.set_crgb_at(0, value); // Set value at LED found at index 0
  LED.sync(); // Sends the value to the LED
  delay(500); // Wait 500 ms
  
  value.b = 0; value.g = 255; value.r = 0; value.w = 0; // RGB Value -> Red
  LED.set_crgb_at(0, value); // Set value at LED found at index 0
  LED.sync(); // Sends the value to the LED
  delay(500); // Wait 500 ms

  value.b = 0; value.g = 0; value.r = 255; value.w = 0; // RGB Value -> Red
  LED.set_crgb_at(0, value); // Set value at LED found at index 0
  LED.sync(); // Sends the value to the LED
  delay(500); // Wait 500 ms

  value.b = 0; value.g = 0; value.r = 0; value.w = 255; // RGB Value -> Red
  LED.set_crgb_at(0, value); // Set value at LED found at index 0
  LED.sync(); // Sends the value to the LED
  delay(500); // Wait 500 ms
	}

