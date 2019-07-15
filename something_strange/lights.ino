
#include <FastLED.h>
#define DATA_PIN 6  //this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
#define NUM_LEDS 50 //change this for the number of LEDs in the strip
#define COLOR_ORDER RGB
#define ONDELAY 750
#define OFFDELAY 500

CRGB leds[NUM_LEDS];

int r = 1;  
int b = 237;  
int g = 234;

// Array to handle colors of alphabet, 3 element subarrays represent rgb
const int colors[26][3] {
  {255, 100, 0}, // a
  {0, 100, 255}, // b
  {255, 0, 100}, // c
  {100, 255, 0}, // d
  {0, 100, 255}, // e
  {255, 100, 0}, // f
  {255, 0, 100}, // g
  {100, 255, 0}, // h
  {0, 100, 255}, // i
  {255, 0, 100}, // j
  {0, 100, 255}, // k
  {100, 255, 0}, // l
  {255, 100, 0}, // m
  {255, 0, 100}, // n
  {255, 0, 100}, // o
  {100, 255, 0}, // p
  {255, 0, 100}, // q
  {100, 255, 0}, // r
  {255, 100, 0}, // s
  {255, 100, 0}, // t
  {0, 100, 255}, // u
  {255, 0, 100}, // v
  {0, 100, 255}, // w
  {255, 100, 0}, // x
  {255, 0, 100}, // y
  {255, 0, 100}, // z
};

// Array to transpose incoming ascii positions to corresponding positions in light fixture
const int charPos[25] {
  19,   //A
  20,   //B
  21,   //C
  22,   //D
  23,   //E
  24,   //F
  18,   //G
  17,   //H
  16,   //I
  15,   //J
  14,   //K
  13,   //L
  12,   //M
  5,    //N
  6,    //O
  7,    //P
  8,    //Q
  9,    //R
  10,   //S
  11,   //T
  4,    //U
  3,    //V
  2,    //W
  1,    //X
  0,    //Y
};

void setup(){
  
  FastLED.addLeds<WS2811, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS); //setting up the FastLED
    randomSeed(analogRead(0)); //seeding my random numbers to make it more random.  If you just use the random function it will repeat the same pattern every time it is loaded.
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
}

void loop(){
//
//   if (Serial.available()) {      // If anything comes in Serial (USB),
//      Serial.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
//    }

  ALL();
  LOWREDUP();
  RUN();

}

void ALL() {
  FastLED.clear();
  
  for(int x = 0; x < NUM_LEDS; x++){
      leds[x] = CRGB(1,237,234);
      FastLED.show();
      delay(50);
  }
  
}
 
void glowup() {
  FastLED.clear();
  //Setting i determines your lowest power value. the second condition determines the max value and the y determines your step
  for( int i = 60; i < 255; i = i + y ) {

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
          
      FastLED.show();
      delay(50); 
    }
}

void glowdown() {
  //Same thing as glowup, except in reverse
  for (int i = 255; i > 60; i = i - y){

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
          
      FastLED.show();
      delay(50); 
    }      
}

void RUN() {
      FastLED.clear();
  leds[33] = CRGB(r,g,b);
  leds[34] = CRGB(r,g,b);
        FastLED.show();
      delay(500); 
  leds[33] = CRGB (0,0,0);
  leds[34] = CRGB (0,0,0);
        FastLED.show();
      delay(500); 
  leds[33] = CRGB(r,g,b);
  leds[34] = CRGB(r,g,b);
        FastLED.show();
      delay(300); 
  leds[33] = CRGB (0,0,0);
  leds[34] = CRGB (0,0,0);
        FastLED.show();
      delay(600); 
  leds[33] = CRGB(r,g,b);
  leds[34] = CRGB(r,g,b);
        FastLED.show();
      delay(400); 
  leds[33] = CRGB (0,0,0);
  leds[34] = CRGB (0,0,0);
        FastLED.show();
      delay(500); 
  leds[33] = CRGB(r,g,b);
  leds[34] = CRGB(r,g,b);
        FastLED.show();
      delay(2000); 
  leds[23] = CRGB(r,g,b);
  leds[24] = CRGB(r,g,b);
        FastLED.show();
      delay(2000); 
  leds[45] = CRGB(r,g,b);
  leds[46] = CRGB(r,g,b);
        FastLED.show();
      delay(1000); 
leds[34] = CRGB (0,0,0);
 FastLED.show();
      delay(300); 
leds[45] = CRGB (0,0,0);
FastLED.show();
     delay(500); 
leds[23] = CRGB (0,0,0);
FastLED.show();
     delay(1000); 
leds[46] = CRGB (0,0,0);
FastLED.show();
     delay(2000); 
leds[33] = CRGB (0,0,0);
FastLED.show();
     delay(300); 
leds[24] = CRGB (0,0,0);
FastLED.show();
     delay(500); 
    FastLED.clear();  
}



void LOWREDUP(){
     for( int i = 20; i < 150; i = i + y ) {

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
          
      FastLED.show();
      delay(100); 
    } 
}
void LOWREDDOWN(){
     for(int i = 150; i > 20; i = i - y) {

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
          
      FastLED.show();
      delay(100); 
    } 
}

void BLACKOUT(){
      int r = 0;  
      int b = 0;  
      int g = 0;   

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
          
      FastLED.show();
      delay(30000); 
      
}
