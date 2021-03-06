#include <Adafruit_CircuitPlayground.h>

//Hardware Config
#define LED_PIN 1 //digital PWM output pin
#define LED_COUNT 8 //total number of NeoPixels
#define ANALOG_PIN 3 //analog seed pin used to generate random #'s
#define BRIGHTNESS 127 //led brightness

//Delay perameters 
#define DELAY  10; //delay interval between next loop iteration
#define lowDel 5; //low delay interval in ms
#define highDel 400; //high delay interval in ms
#define RANDLOW 30; //lowest random RGB value
#define RANDHI 256; //highest random RGB value

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int red;
int blue;
int green;

void setup()
{
  strip.begin(); //initiate the strip
  strip.setBrightness(BRIGHTNESS); //set the brightness
  strip.show() //start the strip
  randomSeed(analogRead(ANALOG_PIN)); //random number seed generation
}
 
void loop()
{ 
    red = random(RANDLOW, RANDHI); //random red color
    blue = random(RANDLOW, RANDHI); //random blue color
    green = random(RANDLOW, RANDHI); //random green color

    //sets the color of each light
    for (int light = 0; light < LED_COUNT; light ++)
    {
      strip.setPixelColor(light, red, blue, green);
    }
    delay(random(lowDel,highDel)); 
}
