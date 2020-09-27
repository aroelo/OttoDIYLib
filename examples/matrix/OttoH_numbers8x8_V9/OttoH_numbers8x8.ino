//-- First step: Configure the pins where the servos are attached
/*             -------- 
  RIGHT ARM 7 |  O  O  | LEFT ARM 6
              |--------|
  RIGHT LEG 3 |        | LEFT LEG 2
               -------- 
               ||     ||
RIGHT FOOT 5 |---     ---| LEFT FOOT 4  
*/

#include <Otto9Humanoid.h>

Otto9Humanoid Otto;
Otto_Matrix Otto_matrix;

int distance; // variable for the distance measurement

#define PIN_YL 2 // left leg, servo[0]
#define PIN_YR 3 // right leg, servo[1]
#define PIN_RL 4 // left foot, servo[2]
#define PIN_RR 5 // right foot, servo[3]
#define PIN_LA 6 // left arm, servo[4]  
#define PIN_RA 7 // right arm, servo[5]
#define PIN_Trigger 8 // ultrasound
#define PIN_Echo 9 // ultrasound
#define PIN_NoiseSensor A6 //noisesensor
#define PIN_Buzzer  13 //buzzer
#define DIN_PIN A3 // matrix din pin
#define CS_PIN A2 // matrix cs pin
#define CLK_PIN A1 // matrix clk pin
#define LED_DIRECTION 1 // matrix led direction

void setup() {
    Otto.initHUMANOID(PIN_YL, PIN_YR, PIN_RL, PIN_RR, PIN_LA, PIN_RA, true, PIN_NoiseSensor, PIN_Buzzer, PIN_Trigger, PIN_Echo);
    Otto.initMATRIX(DIN_PIN, CS_PIN, CLK_PIN, LED_DIRECTION, "8x8");
    Serial.begin(9600); // setup serial port information
    // using the Arduino IDE serial monitor (set to 9600 BAUD RATE) you will see Otto's responses
    Serial.println("hello"); // output via serial port HELLO,
}

void loop() {
    //-- Display numbers from 0-999
    // for (int counter=0; counter<=999; counter++){
    //     delay(500);
    //     Otto.putLedNumber(counter);
    // }
    //-- Function to read distance sensor
    distance = Otto.getDistance(); // get the distance from the object - value will be between 99cm and 4cm
    // Serial.println(distance); // send the distance measured to the serial port so you can see the distance as a number 
    Otto.putLedNumber(distance);
    delay(2000); 
}