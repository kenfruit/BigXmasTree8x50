//
// This is for the ATMega Pro Micro 5 Volt
//


#include <FastLED.h>



// Watchdog Timer Library
#include <avr/wdt.h>
enum {
  GRB_Black=0x000000,   GRB_Navy=0x000080,   GRB_DarkBlue=0x00008B,   GRB_MediumBlue=0x0000CD,   GRB_Blue=0x0000FF,   GRB_DarkGreen=0x640000,   GRB_Green=0x800000,   GRB_Teal=0x800080,
  GRB_DarkCyan=0x8B008B,   GRB_DeepSkyBlue=0xBF00FF,   GRB_DarkTurquoise=0xCE00D1,   GRB_MediumSpringGreen=0xFA009A,   GRB_Lime=0xFF0000,   GRB_SpringGreen=0xFF007F,   GRB_Aqua=0xFF00FF,   GRB_Cyan=0xFF00FF,
  GRB_MidnightBlue=0x191970,   GRB_DodgerBlue=0x901EFF,   GRB_LightSeaGreen=0xB220AA,   GRB_ForestGreen=0x8B2222,   GRB_SeaGreen=0x8B2E57,   GRB_DarkSlateGray=0x4F2F4F,   GRB_DarkSlateGrey=0x4F2F4F,   GRB_LimeGreen=0xCD3232,
  GRB_MediumSeaGreen=0xB33C71,   GRB_Turquoise=0xE040D0,   GRB_RoyalBlue=0x6941E1,   GRB_SteelBlue=0x8246B4,   GRB_DarkSlateBlue=0x3D488B,   GRB_MediumTurquoise=0xD148CC,   GRB_Indigo=0x004B82,   GRB_DarkOliveGreen=0x6B552F,
  GRB_CadetBlue=0x9E5FA0,   GRB_CornflowerBlue=0x9564ED,   GRB_MediumAquamarine=0xCD66AA,   GRB_DimGray=0x696969,   GRB_DimGrey=0x696969,   GRB_SlateBlue=0x5A6ACD,   GRB_OliveDrab=0x8E6B23,   GRB_SlateGray=0x807090,
  GRB_SlateGrey=0x807090,   GRB_LightSlateGray=0x887799,   GRB_LightSlateGrey=0x887799,   GRB_MediumSlateBlue=0x687BEE,   GRB_LawnGreen=0xFC7C00,   GRB_Chartreuse=0xFF7F00,   GRB_Aquamarine=0xFF7FD4,   GRB_Maroon=0x008000,
  GRB_Purple=0x008080,   GRB_Olive=0x808000,   GRB_Gray=0x808080,   GRB_Grey=0x808080,   GRB_SkyBlue=0xCE87EB,   GRB_LightSkyBlue=0xCE87FA,   GRB_BlueViolet=0x2B8AE2,   GRB_DarkRed=0x008B00,
  GRB_DarkMagenta=0x008B8B,   GRB_SaddleBrown=0x458B13,   GRB_DarkSeaGreen=0xBC8F8F,   GRB_LightGreen=0xEE9090,   GRB_MediumPurple=0x7093DB,   GRB_DarkViolet=0x0094D3,   GRB_PaleGreen=0xFB9898,   GRB_DarkOrchid=0x3299CC,
  GRB_Amethyst=0x6699CC,   GRB_YellowGreen=0xCD9A32,   GRB_Sienna=0x52A02D,   GRB_Brown=0x2AA52A,   GRB_DarkGray=0xA9A9A9,   GRB_DarkGrey=0xA9A9A9,   GRB_LightBlue=0xD8ADE6,   GRB_GreenYellow=0xFFAD2F,
  GRB_PaleTurquoise=0xEEAFEE,   GRB_LightSteelBlue=0xC4B0DE,   GRB_PowderBlue=0xE0B0E6,   GRB_FireBrick=0x22B222,   GRB_DarkGoldenrod=0x86B80B,   GRB_MediumOrchid=0x55BAD3,   GRB_RosyBrown=0x8FBC8F,   GRB_DarkKhaki=0xB7BD6B,
  GRB_Silver=0xC0C0C0,   GRB_MediumVioletRed=0x15C785,   GRB_Plaid=0x55CC33,   GRB_IndianRed=0x5CCD5C,   GRB_Peru=0x85CD3F,   GRB_Chocolate=0x69D21E,   GRB_Tan=0xB4D28C,   GRB_LightGrey=0xD3D3D3,
  GRB_Thistle=0xBFD8D8,   GRB_Orchid=0x70DAD6,   GRB_Goldenrod=0xA5DA20,   GRB_PaleVioletRed=0x70DB93,   GRB_Crimson=0x14DC3C,   GRB_Gainsboro=0xDCDCDC,   GRB_Plum=0xA0DDDD,   GRB_BurlyWood=0xB8DE87,
  GRB_LightCyan=0xFFE0FF,   GRB_Lavender=0xE6E6FA,   GRB_DarkSalmon=0x96E97A,   GRB_Violet=0x82EEEE,   GRB_PaleGoldenrod=0xE8EEAA,   GRB_LightCoral=0x80F080,   GRB_Khaki=0xE6F08C,   GRB_AliceBlue=0xF8F0FF,
  GRB_Honeydew=0xFFF0F0,   GRB_Azure=0xFFF0FF,   GRB_SandyBrown=0xA4F460,   GRB_Wheat=0xDEF5B3,   GRB_Beige=0xF5F5DC,   GRB_WhiteSmoke=0xF5F5F5,   GRB_MintCream=0xFFF5FA,   GRB_GhostWhite=0xF8F8FF,
  GRB_Salmon=0x80FA72,   GRB_AntiqueWhite=0xEBFAD7,   GRB_Linen=0xF0FAE6,   GRB_LightGoldenrodYellow=0xFAFAD2,   GRB_OldLace=0xF5FDE6,   GRB_Red=0x00FF00,   GRB_Fuchsia=0x00FFFF,   GRB_Magenta=0x00FFFF,
  GRB_DeepPink=0x14FF93,   GRB_OrangeRed=0x45FF00,   GRB_Tomato=0x63FF47,   GRB_HotPink=0x69FFB4,   GRB_Coral=0x7FFF50,   GRB_DarkOrange=0x8CFF00,   GRB_LightSalmon=0xA0FF7A,   GRB_Orange=0xA5FF00,
  GRB_LightPink=0xB6FFC1,   GRB_Pink=0xC0FFCB,   GRB_Gold=0xD7FF00,   GRB_PeachPuff=0xDAFFB9,   GRB_NavajoWhite=0xDEFFAD,   GRB_Moccasin=0xE4FFB5,   GRB_Bisque=0xE4FFC4,   GRB_MistyRose=0xE4FFE1,
  GRB_BlanchedAlmond=0xEBFFCD,   GRB_PapayaWhip=0xEFFFD5,   GRB_LavenderBlush=0xF0FFF5,   GRB_Seashell=0xF5FFEE,   GRB_Cornsilk=0xF8FFDC,   GRB_LemonChiffon=0xFAFFCD,   GRB_FloralWhite=0xFAFFF0,   GRB_Snow=0xFAFFFA,
  GRB_Yellow=0xFFFF00,   GRB_LightYellow=0xFFFFE0,  GRB_Ivory=0xFFFFF0,  GRB_White=0xFFFFFF, GRB_KRFWhite=0xFF60FF,   GRB_KRFDarkGreen=0x400000, GRB_KRFDarkPurple=0x004040, GRB_KRFDarkDarkPurple=0x000810
};

enum { setNone, setEven, setOdd, setBoth};

//#define DEBUG1 1
//#define DEBUG2 2
//#define DEBUG3 3

#define NUM_STRIPS 8
#define NUM_LEDS_PER_STRIP 50

#define NEXT_TO_LAST_ROW (NUM_LEDS_PER_STRIP-1)

#define TWINKLE_NUM_LIGHTS_ON  150
#define RED_LED 30
#define RANDOM_LOC_MAX 200

#define CYCLE_TIME_LONG 7
#define CYCLE_TIME_SHORT 5


uint8_t randomRow[RANDOM_LOC_MAX];
uint8_t randomColumn[RANDOM_LOC_MAX];

uint8_t randomPoint1 = TWINKLE_NUM_LIGHTS_ON;
uint8_t randomPoint2 = 0;


bool heartBeat = true;

char stringDash[] = " - ";


//This has set up a two dimensional array. 
//If you want to access the first led on the first strip, you would use leds[0][0].
//If you wanted to access the third led on the second strip, you would use leds[1][2] and so. 
//Setup looks mostly the same, except now we have to tell it which array to use for each strip: 

CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

CRGB scratchPad[NUM_LEDS_PER_STRIP];


unsigned long diagnosticCount = 1;

void setup() 
{
  Serial.begin(115200); // open the Serial port at 9600 bps:

  pinMode(RED_LED, OUTPUT);

  // Set-up the arrays of random rows and columns
  for( uint8_t i = 0; i < RANDOM_LOC_MAX; i++)
  {
    randomRow[i] = random(50);
    randomColumn[i] = random(8);
  }


  /*    Sparkfun
  FastLED.addLeds<NEOPIXEL, 2>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 3>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 4>(leds[2], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 5>(leds[3], NUM_LEDS_PER_STRIP);  
  FastLED.addLeds<NEOPIXEL, 6>(leds[4], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 7>(leds[5], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 8>(leds[6], NUM_LEDS_PER_STRIP);  
  FastLED.addLeds<NEOPIXEL, 9>(leds[7], NUM_LEDS_PER_STRIP);
  */

  FastLED.addLeds<NEOPIXEL, 0>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 2>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 4>(leds[2], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 5>(leds[3], NUM_LEDS_PER_STRIP);  
  FastLED.addLeds<NEOPIXEL, 12>(leds[4], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 13>(leds[5], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 14>(leds[6], NUM_LEDS_PER_STRIP);  
  FastLED.addLeds<NEOPIXEL, 16>(leds[7], NUM_LEDS_PER_STRIP);


  testPattern1();

  int hue = 5;
  for( int ijk = 0; ijk < 10; ijk++)
  {
    scratchPad[ijk] =CHSV( hue, 255, 255);
    hue += 151;
    hue %= 256;
  }
  scratchPad[20] = GRB_Black;

  // Enable the watchdog timer;

  
  wdt_enable(WDTO_8S);



#ifdef DEBUG1
  //Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(1);
#endif
  return;
}


////
////
//// void loop() {
////
////

void loop() 
{
  lightProgram();
}

// Repeat this pattern forever

void lightProgram(void)
{
  FastLED.clear();
  
  wdt_reset();                    // Reset the watchdog
  horzColorBandsDiag(GRB_KRFDarkGreen,8, GRB_KRFWhite,8, 2, CYCLE_TIME_LONG,100);
#ifdef DEBUG1
  toggleHeartBeat();
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(3);
#endif

  wdt_reset();                    // Reset the watchdog
  dazzle(GRB_KRFDarkGreen, GRB_KRFDarkDarkPurple, CYCLE_TIME_LONG);
#ifdef DEBUG1
  toggleHeartBeat();
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(4);
#endif

  wdt_reset();                    // Reset the watchdog
  garland(GRB_KRFWhite, GRB_DarkRed, GRB_KRFWhite, GRB_DarkRed, true, true);
#ifdef DEBUG1
    Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(5);
#endif

  wdt_reset();                    // Reset the watchdog
  rotateArrayLeft(CYCLE_TIME_LONG, 100);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(6);
#endif


  wdt_reset();                    // Reset the watchdog
twinkleLights(GRB_Red, GRB_Yellow, GRB_Blue, GRB_Purple,CYCLE_TIME_LONG);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(7);
#endif

  wdt_reset();                    // Reset the watchdog
  RainbowSegueVert2(CYCLE_TIME_LONG,50);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(8);
#endif

  wdt_reset();                    // Reset the watchdog
  garland(GRB_Blue, GRB_Purple, GRB_Blue, GRB_Purple, true, true);   
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(9);

  wdt_reset();                    // Reset the watchdog
  rotateArrayLeft(CYCLE_TIME_LONG, 100);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(10);
#endif
  
  wdt_reset();                    // Reset the watchdog
  twinkleLights2(GRB_Red, GRB_Yellow, GRB_Blue, GRB_Purple, CYCLE_TIME_LONG);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(11);
#endif

  wdt_reset();                    // Reset the watchdog
  dazzle(GRB_KRFDarkGreen, GRB_Red, CYCLE_TIME_LONG);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(12);
#endif

  wdt_reset();                    // Reset the watchdog
  garland(GRB_KRFWhite, GRB_DarkRed, GRB_Blue, GRB_Purple, true, true);
#ifdef DEBUG1
    Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(13);
#endif

  wdt_reset();                    // Reset the watchdog
  rotateArrayLeft(CYCLE_TIME_LONG, 100);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(14);
#endif


  wdt_reset();                    // Reset the watchdog
  twinkleLights(GRB_Red, GRB_Yellow, GRB_Blue, GRB_Purple,CYCLE_TIME_LONG);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(15);
#endif

  wdt_reset();                    // Reset the watchdog
  horzColorBandsDiag(GRB_KRFDarkGreen,8, GRB_KRFDarkPurple,2, 2, CYCLE_TIME_LONG,100);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(16);
#endif

  wdt_reset();                    // Reset the watchdog
  dazzle(GRB_KRFDarkGreen, GRB_Blue, CYCLE_TIME_LONG);
#ifdef DEBUG2
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(17);
#endif

  wdt_reset();                    // Reset the watchdog
  garland(GRB_KRFWhite, GRB_Blue, GRB_KRFWhite, GRB_Blue, true, true);
#ifdef DEBUG2
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(18);
#endif

  wdt_reset();                    // Reset the watchdog
  rotateVarySpeed();
#ifdef DEBUG2
  toggleHeartBeat();  
  Serial.print(diagnosticCount++);   Serial.print(stringDash); Serial.println(19);
#endif

  wdt_reset();                    // Reset the watchdog
  dazzle(GRB_DarkRed, GRB_Blue, CYCLE_TIME_LONG);
#ifdef DEBUG2
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(20);
#endif


  wdt_reset();                    // Reset the watchdog
  twinkleLights2(GRB_Red, GRB_Yellow, GRB_Blue, GRB_Purple, CYCLE_TIME_LONG);
#ifdef DEBUG2
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(21);
#endif

  wdt_reset();                    // Reset the watchdog
  dazzle(GRB_KRFDarkGreen, GRB_Yellow, CYCLE_TIME_LONG);
#ifdef DEBUG2
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(22);
#endif

  wdt_reset();                    // Reset the watchdog
  garland(GRB_Blue, GRB_DarkRed, GRB_Blue, GRB_DarkRed, true, true);  
#ifdef DEBUG2
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(23);
#endif

  wdt_reset();                    // Reset the watchdog
  rotateArrayLeft(CYCLE_TIME_LONG, 100);
#ifdef DEBUG2
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(24);
#endif

  wdt_reset();                    // Reset the watchdog
  spiral(scratchPad, CYCLE_TIME_SHORT, 2);
#ifdef DEBUG2
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(25);
#endif

  wdt_reset();                    // Reset the watchdog
  twinkleLights2(GRB_KRFWhite, GRB_KRFWhite, GRB_Blue, GRB_Blue, CYCLE_TIME_LONG);
#ifdef DEBUG1
  toggleHeartBeat();
 Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(2);
#endif

  wdt_reset();                    // Reset the watchdog
  garlandWithSlide(GRB_KRFWhite, GRB_DarkRed, GRB_KRFWhite, GRB_DarkRed, CYCLE_TIME_LONG, 200);
#ifdef DEBUG2
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(27);
#endif

  wdt_reset();                    // Reset the watchdog
  dazzle(GRB_KRFDarkGreen, GRB_KRFWhite,CYCLE_TIME_LONG);
#ifdef DEBUG2
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(28);
#endif

  wdt_reset();                    // Reset the watchdog
  garland(GRB_KRFWhite, GRB_Purple, GRB_KRFWhite, GRB_Purple, true, true);  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(29);

  wdt_reset();                    // Reset the watchdog
  rotateVarySpeed();
#ifdef DEBUG2
  toggleHeartBeat();
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(30);
#endif

  wdt_reset();                    // Reset the watchdog
  RainbowSegueHorz(CYCLE_TIME_LONG,200,2);
#ifdef DEBUG2
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(31);
#endif

  wdt_reset();                    // Reset the watchdog
  twinkleLights2(GRB_Red, GRB_Yellow, GRB_Blue, GRB_Purple, CYCLE_TIME_LONG);
#ifdef DEBUG2
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(32);
#endif

  wdt_reset();                    // Reset the watchdog
  horzColorBandsDiag(GRB_KRFDarkGreen, 4, GRB_DarkRed, 4, 2, CYCLE_TIME_LONG,100);
#ifdef DEBUG2
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(33);
#endif

  wdt_reset();                    // Reset the watchdog
  dazzle(GRB_Blue, GRB_KRFWhite,CYCLE_TIME_LONG);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(34);
#endif

  wdt_reset();                    // Reset the watchdog
  horzColorBandsDiag(GRB_KRFDarkGreen,8, GRB_Yellow,2, 2, CYCLE_TIME_LONG,100);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(35);
#endif

  wdt_reset();                    // Reset the watchdog
  garland(GRB_KRFWhite, GRB_Yellow, GRB_KRFWhite, GRB_Yellow, true, true);  
#ifdef DEBUG1
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(36);
#endif

  wdt_reset();                    // Reset the watchdog
  rotateVarySpeed();
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(37);
#endif

  wdt_reset();                    // Reset the watchdog
  twinkleLights(GRB_Red, GRB_Yellow, GRB_Blue, GRB_Purple,CYCLE_TIME_LONG);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(38);
#endif

  wdt_reset();                    // Reset the watchdog
  dazzle(GRB_Blue, GRB_Red,CYCLE_TIME_LONG);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(39);
#endif

  wdt_reset();                    // Reset the watchdog
  garlandWithSlide(GRB_KRFWhite, GRB_Blue, GRB_KRFWhite, GRB_Blue, CYCLE_TIME_LONG, 200);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(40);
#endif

  wdt_reset();                    // Reset the watchdog
  dazzle(GRB_DarkRed, GRB_KRFWhite, CYCLE_TIME_LONG);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(40);
#endif

  
  wdt_reset();                    // Reset the watchdog
  dazzle(GRB_DarkRed, GRB_Teal, CYCLE_TIME_LONG);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(41);
#endif

  wdt_reset();                    // Reset the watchdog
  twinkleLights2(GRB_Red, GRB_Yellow, GRB_Blue, GRB_Purple, CYCLE_TIME_LONG);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(42);
#endif

  wdt_reset();                    // Reset the watchdog
  garlandWithSlide(GRB_KRFWhite, GRB_Purple, GRB_KRFWhite, GRB_Purple, CYCLE_TIME_LONG, 200);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(43);
#endif

  wdt_reset();                    // Reset the watchdog
  dazzle(GRB_DarkRed, GRB_Teal, CYCLE_TIME_LONG);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(44);
#endif

  wdt_reset();                    // Reset the watchdog
  twinkleLights(GRB_Red, GRB_Yellow, GRB_Blue, GRB_Purple,CYCLE_TIME_LONG);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(45);
#endif

  wdt_reset();                    // Reset the watchdog
  garland(GRB_KRFWhite, GRB_Yellow, GRB_KRFWhite, GRB_Yellow, true, true);  
#ifdef DEBUG1
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(46);
#endif

  wdt_reset();                    // Reset the watchdog
  rotateVarySpeed();
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(47);
#endif

  wdt_reset();                    // Reset the watchdog
  garlandWithSlide(GRB_KRFWhite, GRB_DarkRed, GRB_Blue, GRB_Purple, CYCLE_TIME_LONG, 200);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(48);
#endif

  wdt_reset();                    // Reset the watchdog
  RainbowSegueVert(CYCLE_TIME_LONG,200);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(49);
#endif


  wdt_reset();                    // Reset the watchdog
  garland(GRB_Blue, GRB_Purple, GRB_Blue, GRB_Purple, true, true);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(51);
#endif

  wdt_reset();                    // Reset the watchdog
  rotateArrayLeft(CYCLE_TIME_LONG, 100);  
#ifdef DEBUG1
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(52);
#endif

  wdt_reset();                    // Reset the watchdog
  garland(GRB_Blue, GRB_Lime, GRB_Blue, GRB_Lime, true, true);  
#ifdef DEBUG1
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(53);
#endif

  wdt_reset();                    // Reset the watchdog
  rotateArrayLeft(CYCLE_TIME_LONG, 100);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(54);
#endif

  wdt_reset();                    // Reset the watchdog
  spiral2(scratchPad, CYCLE_TIME_SHORT, 2);
#ifdef DEBUG1
  toggleHeartBeat();  
  Serial.print(diagnosticCount++); Serial.print(stringDash); Serial.println(55);
#endif

  return; 

}




void garlandWithSlide(CRGB color0, CRGB color1,CRGB color2, CRGB color3, unsigned long timeInSec, int msecDelay) 
{
  //Serial.println(101);
  garland(color0, color1, color2, color3, true, true);
  //garlandSlide(color0, color1, color2, color3, timeInSec, msecDelay);

  rotateArrayLeft(timeInSec, msecDelay);
  
}



void horzColorBandsDiag(CRGB color1, int rows1, CRGB color2, int rows2, int diagCount, unsigned long timeInSec, int msecDelay)
{
  ////Serial.println(102);
  setHorzColorBands(color1, rows1, color2, rows2);
  diagonalize(diagCount);
  rotateDown(timeInSec, msecDelay);
  return;
} 

void toggleHeartBeat(void)
{
  heartBeat = !heartBeat;
  digitalWrite(RED_LED,(heartBeat ? HIGH : LOW));
  return; 
}


void rotateVarySpeed(void)
{
  ////Serial.println("rotateVarySpeed");
  wdt_reset();  

  rotateArrayLeft(CYCLE_TIME_SHORT, 100);
  wdt_reset();  

  rotateArrayLeft(CYCLE_TIME_SHORT, 50);
  wdt_reset();  

  rotateArrayLeft(CYCLE_TIME_SHORT, 100);
  wdt_reset();  
  
  rotateArrayLeft(CYCLE_TIME_SHORT, 50);
  wdt_reset();  
  
  return;  
}



////
////
//// void rotateDown(int msecDelay)
////
//// Slide the colors down repeatedly
////
void rotateDown(unsigned long timeInSec, int msecDelay)
{
  //Serial.println("rDown");
  int loopCount = 0;


  unsigned long exitTime = millis() + timeInSec * 1000L;
 
  while( millis() < exitTime)
  {
    rotateDownOneRow();
    FastLED.show();
    delay(msecDelay);  
    
    loopCount++;
  }
  return;
}


////
////
//// void rotateDownOneRow()
////
//// Save the bottom row, slide the rows down, reset to top row from the saved bottom
////

void rotateDownOneRow()
{
  //Serial.println("rDown1");
  int col;

  // Save the current Bottom Row
  for(col = 0; col < NUM_STRIPS; col++)
  {
    scratchPad[col] = leds[col][0];
  }

  // Slide everything down, old bottom goes to the top
  shiftAllRowsDown();
  setTopColor(scratchPad, setBoth);

  return;
}






//// 
//// void rotateArrayLeft(int rotateCount, int msecDelay);
//// 
//// Rotate column into the next column with wrap
//// 

void rotateArrayLeft(unsigned long timeInSec, int msecDelay)
{
  //////Serial.println("rotateArrayLeft");

  unsigned long exitTime = millis() + timeInSec * 1000L;
  int loopCount = 0;
      
  // Now slide it up
  while( millis() < exitTime)
  {
    // Save existing column 0
    for(int row = 0; row < NUM_LEDS_PER_STRIP; row++)
    {
      scratchPad[row] = leds[0][row];
    }

    slideColLeft();
    setColorLeft(scratchPad);

    FastLED.show();
    delay(msecDelay);  
    loopCount++;
   
  }
  return;
}


////
////
//// void setHorzColorBands(CRGB color1, CRGB color2, int width1, int width2, int evenOdd)
////
////
////  

void setHorzColorBands(CRGB color1, int width1, CRGB color2, int width2)
{
  ////Serial.println("setHorzColorBands");
  int col;
  int totalRowsSet = 0;
  int loopCount = 0;

  do
  {
    for(col = 0; col < width1; col++)
    {
      shiftAllRowsDown();
      setTopColor(color1, setBoth);
    }

    for(col = 0; col < width2; col++)
    {
      shiftAllRowsDown();
      setTopColor(color2, setBoth);
    }
    loopCount++;
    
  }while(totalRowsSet++ < NUM_LEDS_PER_STRIP);

  FastLED.show();
  delay(100);
  return;
}



////
////
//// void setVertColorBands(CRGB color[]);
////
////
////
void setVertColorBands(CRGB color[])
{
  ////Serial.println("setVertColorBands");
  for(int col = 0; col < NUM_STRIPS; col++)
  {      
    for(int row = 0; row < 50; row++)
    {
      leds[col][row] = color[col];
    }
  }
  return;
}
  




void garland(CRGB color0, CRGB color1,  CRGB color2,  CRGB color3, bool clearToGreen, bool slideUp)
{
  //Serial.println(103);
  // Do a zig-zag garland from top to bottom, then slide it up 
  int col;

  CRGB color;

  // Do I want to repaint the tree all green before I start?
  if(clearToGreen)
  {
  //Serial.println(104);
    setHorzColorBands(GRB_Green, 5, GRB_DarkGreen, 5);
  //Serial.println(105);
  }

  // Turn on a string of lights from top to bottom
  for(int row = 0; row < NUM_LEDS_PER_STRIP; row++) 
  {
    switch(row%4)
    {
        case 0:
          color = color0;
          break;
        case 1:
          color = color1;    
          break;
        case 2:
          color = color2;      
          break;
        case 3:
          color = color3;
          break;
        default:
          break;
    }
      
    col = row%8;   
    leds[col][NEXT_TO_LAST_ROW - row] = color;
  }
  return;
}


void garlandSlide(CRGB color0, CRGB color1,  CRGB color2,  CRGB color3, long int timeInSec, int msecDelay) 
{
  //Serial.println(106);
  int row;
  int col;
  int k;

  CRGB dummy;

  unsigned long exitTime = millis() + timeInSec * 1000L;
  int loopCount = 0;
 
  while( millis() < exitTime)
  {
    for(col = 0; col < NUM_STRIPS; col++)
    {
      for(row = 0; row < NUM_LEDS_PER_STRIP; row++)
      {
        //Serial.print(row); Serial.print(" "); Serial.println(col);
      
        if(leds[col][row] ==  color0)
              leds[col][row] = color1;
        else if(leds[col][row] ==  color1)
              leds[col][row] = color2;
        else if(leds[col][row] ==  color2)
              leds[col][row] = color3;
        else if(leds[col][row] ==  color3)
              leds[col][row] = color0;
      }
    }
    //Serial.println(107);
    FastLED.show();
    delay(msecDelay);  
  //Serial.println(108);
    loopCount++;

  }
  //Serial.println(108);
  return;
}




//====================================

//void setColColorRight(int col, CRGB color[])
//{
//  for(int row = 0; row < NUM_LEDS_PER_STRIP; row++)
//  {
//     if(isOdd(row))
//     { 
//       leds[col][row+1] = color[row]; 
//     }     
//  }
//}

//void setColColorLeft(int col, CRGB color[])
//{
//  for(int row = 0; row < NUM_LEDS_PER_STRIP; row++)
//  {
//     if(isEven(row))
//     { 
//       leds[col][row] = color[row]; 
//     }     
//  }
//}

////
////
//// void setColColorRight(int col, CRGB color)
////
//// For the given column, set the odd numbered bulbs to the color
////
//void setColColorRight(int col, CRGB color)
//{
//  for(int row = 0; row < NUM_LEDS_PER_STRIP; row++)
//  {
//     if(isOdd(row))
//     { 
//       leds[col][row] = color; 
//     }     
//  }
//}

////
////
//// void setColColorLeft(int col, CRGB color)
////
//// For the given column, set the even numbered bulbs to the color
////
//void setColColorLeft(int col, CRGB color)
//{
//  for(int row = 0; row < NUM_LEDS_PER_STRIP; row++)
//  {
//     if(isEven(row))
//     { 
//       leds[col][row] = color; 
//     }     
//  }
//}
//






////
////
//// void shiftAllRowsDown()
////
////  Set the color in each cell in a row to the color of the cell above it.
////
void shiftAllRowsDown(void)
{
  //Serial.println("shiftAllD");
  
  for(int row = 0; row < NEXT_TO_LAST_ROW; row++)   // Loop the rows
  {
    for(int col = 0; col < NUM_STRIPS; col++)       // Loop the columns
    {
      //Serial.print(row); Serial.print(" "),Serial.println(col);
      leds[col][row] = leds[col][row+1]; 
    }
  }
  //Serial.println("shiftAllDone");
  return;
}


void setTopColor(CRGB color, int evenOdd)
{

  //Serial.println("setTopC");
  for(int col = 0; col < NUM_STRIPS; col++)
  {
       //Serial.println(col);
       //   if( (isEven(col) && (evenOdd & setEven)) || (isOdd(col) && (evenOdd & setOdd)) ) 
       leds[col][NEXT_TO_LAST_ROW] = color;
  }
  //Serial.println("setTopCDone");
  return;
}

void setTopColor(CRGB color[], int evenOdd)
{
  //Serial.println("setTopC[]");

  for(int col = 0; col < NUM_STRIPS; col++)
  {
    if( (isEven(col) && (evenOdd & setEven)) || (isOdd(col) && (evenOdd & setOdd)) ) 
      leds[col][NEXT_TO_LAST_ROW] = color[col];
  }
  //Serial.println("setTopC[]Done");
  return;
}



////
////
////  void slideColLeft()
////
////  Move colors from column n+1 to column n
////

void slideColLeft()
{
  // Loop the columns
  for(int col = 0; col < NUM_STRIPS-1; col++)
  {
    //Loop the rows
    
    // This inner loop will go over each led in the current strip, one at a time
    for(int row = 0; row < NUM_LEDS_PER_STRIP; row++) 
    {
      leds[col][row] = leds[col+1][row]; 
    }
  }
  return;
}


////
////
////  void setColorLeft(CRGB color)
////
////  Set the odd numberd bulbs on the high numbered column to the color
////
////


void setColorLeft(CRGB color)
{

  for(int row = 0; row < NUM_LEDS_PER_STRIP; row++)
  {
    leds[NUM_STRIPS-1][row] = color;
  }
  return;
}

void setColorLeft(CRGB color[])
{
  for(int row = 0; row < NUM_LEDS_PER_STRIP; row++)
  {
    leds[NUM_STRIPS-1][row] = color[row];
  }
  return;
}



////
////
//// void twinkleLights(CRGB color0, CRGB color1, CRGB color2, CRGB color3, unsigned long timeInSec)
////
//// Paint the tree green, then randomly turn lights off and on.
////
void twinkleLights(CRGB color0, CRGB color1, CRGB color2, CRGB color3, unsigned long timeInSec)
{
  ////Serial.println("twinkleLights");
  unsigned long exitTime = millis() + timeInSec * 1000L;
  
   uint8_t row;
   uint8_t col;

   CRGB currentColor;
   
   // First, set the tree all green 
   setHorzColorBands(GRB_Green, 5, GRB_DarkGreen, 5);
   
   
   int loopCount = 0;
   while( millis() < exitTime) 
   {
      // There are two pointers into the array of random numbers.
      // randomPoint1 is the next light to be turned on.
      // randomPoint2 trails randomPoint1 by NUM_LIGHTS_ON
    
      // Next Light to turn off
      row = randomRow[randomPoint2];
      col = randomColumn[randomPoint2];
      
      leds[col][row] = GRB_Green;          
      
      // Next Light to turn on
      int8_t row = randomRow[randomPoint1];
      int8_t column = randomColumn[randomPoint1];

      switch (loopCount % 4) 
      {
        case 0:
          currentColor = color0;
          break;
        case 1:
          currentColor = color1;    
          break;
        case 2:
          currentColor = color2;      
          break;
        case 3:
          currentColor = color3;
          break;
        default:
          break;
      }

      leds[col][row] = currentColor;

      //advance and rollover
      randomPoint1++;
      randomPoint1 %= RANDOM_LOC_MAX;
      
      randomPoint2++;
      randomPoint2 %= RANDOM_LOC_MAX;

      // Set up all the light before displaying
      if(TWINKLE_NUM_LIGHTS_ON < loopCount)
      {
        FastLED.show();
        delay(5);
      }

      loopCount++;
   }

  return;
}


// Paint the tree green, then randomly turn lights off and on.
void twinkleLights2(CRGB color0, CRGB color1, CRGB color2, CRGB color3, unsigned long timeInSec)
{
  //Serial.println("tL2");

  uint8_t row;
  uint8_t col;

  CRGB randomColor0;
  CRGB randomColor1;

  unsigned long exitTime = millis() + timeInSec * 1000L;
 
  // First, set the tree all green 
  setHorzColorBands(GRB_Green, 5, GRB_DarkGreen, 5);
  //Serial.println("tL2PG");
   int loopCount = 0;
   while( millis() < exitTime) 
   {
      //Serial.println(loopCount);
    
      // Set the colors
      switch (loopCount % 6) 
      {
        case 0:
          randomColor0 = color0;
          randomColor1 = color1;
          break;
        case 1:
          randomColor0 = color2;    
          randomColor1 = color3;
          break;
        case 2:
          randomColor0 = color0;
          randomColor1 = color2;      
          break;
        case 3:
          randomColor0 = color1;
          randomColor1 = color3;
          break;
        case 4:
          randomColor0 = color0;
          randomColor1 = color3;
        case 5:
          randomColor0 = color1;
          randomColor1 = color2;
          break;
       default:
          break;
      }
 
      setTopColor(GRB_DarkGreen,  setBoth);
  
    
      // Next Light to turn off
      col = random(8);
      leds[col][49] = randomColor0;         
      
      col = random(8);
      leds[col][49] = randomColor1;
              
      rotateDownOneRow();
      FastLED.show();
      delay(50);  

      loopCount++;
      
      //wdt_reset();        

      if(loopCount%20)
      {
        //Serial.println(loopCount);
      }
      
   }
  //Serial.println("tL2Done");
  return;
}



////
////
//// void testPattern1(void)
////
//// Turn on a single light running up each strip 

void testPattern1(void)
{
  int row;
  int col;

 long unsigned int colorPalate[] = {GRB_Green, GRB_Red, GRB_Blue, GRB_Purple, GRB_Yellow, GRB_KRFWhite, GRB_Cyan, GRB_Green};
  
  // Loop the columns, Loop the rows

  for(col = 0; col < NUM_STRIPS; col++)
  {
    for(row = 0; row < NUM_LEDS_PER_STRIP; row++) 
    {
      leds[col][row] = colorPalate[col];    //GRB_Green;                     /// This is displaying Green
      FastLED.show();
      leds[col][row] = GRB_Black;
    }
  }
  FastLED.show();   // Clear the last bulb  
}



bool isOdd(int testValue)
{
  return (testValue%2==1);
}
bool isEven(int testValue)
{
  return !isOdd(testValue);
}

void diagonalize(int offset)
{
  int workingOffset;

  for(int col = 0; col < 8; col++)
  {
    workingOffset = (col*offset)%NUM_LEDS_PER_STRIP;
    slideColDown(col, workingOffset);
  }
}

void diagonalize2(int offset)
{
  int workingOffset;

  for(int row = 0; row < 50; row++)
  {
    workingOffset = (row*offset)%NUM_STRIPS;
    slideRowLeft(row, workingOffset);
  }
}



////
////
//// void slideColDown(int col, int numRows)
////
//// Slice the given column down n Rows by calling SlideColDownOne() n times
////
void slideColDown(int col, int numRows)
{
  for(int rowCount = 0; rowCount < numRows; rowCount++)
  {
    slideColDownOne(col);
  }
}


////
////
//// void slideColDownOne(int col)
////
//// Slice the given column down 1 Row
////
void slideColDownOne(int col)
{
  CRGB temp;
  temp = leds[col][0];
  for(int row = 0; row < NUM_LEDS_PER_STRIP-1; row++)
  {
    leds[col][row] = leds[col][row+1];
  }
  leds[col][NUM_LEDS_PER_STRIP-1] = temp;
}

////
////
//// void slideRowLeft(int row, int numCols)
////
//// Slice the given column down n Rows by calling SlideColDownOne() n times
////
void slideRowLeft(int row, int numCols)
{
  for(int colCount = 0; colCount < numCols; colCount++)
  {
    slideRowLeftOne(row);
  }
}


////
////
//// void slideRowLeftOne(int row)
////
//// Slice the given column down 1 Row
////
void slideRowLeftOne(int row)
{
  CRGB temp;
  temp = leds[0][row];
  for(int col = 0; col < NUM_STRIPS-1; col++)
  {
    leds[col][row] = leds[col+1][row];
  }
  leds[NUM_STRIPS-1][row] = temp;
}



/////////////////////////////  Fromn small tree

void RainbowSegueVert(unsigned long timeInSec, int msecDelay)
{
  //////Serial.println("RainbowSegueVert");
  unsigned long exitTime = millis() + timeInSec * 1000L;
 
  int hue0 = 0;  
  int hue1 = hue0 + 25;
  int hue2 = hue1 + 25;
  int hue3 = hue2 + 25;
  int hue4 = hue3 + 25;
  int hue5 = hue4 + 25;
  int hue6 = hue5 + 25;
  int hue7 = hue6 + 25;
  bool oddEven = true;
  
  int loopCount = 0;
  while( millis() < exitTime)
  {
    for(int row = 0; row < 50; row++)
    {
        leds[0][row] = CHSV( hue0, 255, 255);
        leds[1][row] = CHSV( hue1, 255, 255);
        leds[2][row] = CHSV( hue2, 255, 255);        
        leds[3][row] = CHSV( hue3, 255, 255);
        leds[4][row] = CHSV( hue4, 255, 255);
        leds[5][row] = CHSV( hue5, 255, 255);
        leds[6][row] = CHSV( hue6, 255, 255);
        leds[7][row] = CHSV( hue7, 255, 255);

    }
    FastLED.show();
    delay(msecDelay);
    
    hue0 = hue1;
    hue1 = hue2;
    hue2 = hue3;
    hue3 = hue4;
    hue4 = hue5;
    hue5 = hue6;
    hue6 = hue7;
    hue7 = (hue7 + 10) % 255 ;

    loopCount++;
    
    
  }
  return;
  
}

void RainbowSegueVert2(unsigned long timeInSec, int msecDelay)
{
  //////Serial.println("RainbowSegueVert2");
  unsigned long exitTime = millis() + timeInSec * 1000L;
 
  int hue0 = 0;  
  int hue1 = hue0 + 5;
  int hue2 = hue1 + 5;
  int hue3 = hue2 + 5;
  int hue4 = hue3 + 5;
  int hue5 = hue4 + 5;
  int hue6 = hue5 + 5;
  int hue7 = hue6 + 5;
   
  int loopCount = 0;
  while( millis() < exitTime)
  {
    for(int row = 0; row < 50; row++)
    {
        leds[0][row] = CHSV( hue0, 255, 255);
        leds[1][row] = CHSV( hue1, 255, 255);
        leds[2][row] = CHSV( hue2, 255, 255);        
        leds[3][row] = CHSV( hue3, 255, 255);
        leds[4][row] = CHSV( hue4, 255, 255);
        leds[5][row] = CHSV( hue5, 255, 255);
        leds[6][row] = CHSV( hue6, 255, 255);
        leds[7][row] = CHSV( hue7, 255, 255);

    }
    FastLED.show();
    delay(msecDelay);
    
    hue0 = hue1;
    hue1 = hue2;
    hue2 = hue3;
    hue3 = hue4;
    hue4 = hue5;
    hue5 = hue6;
    hue6 = hue7;
    hue7 = (hue7 + 5) % 255 ;

    loopCount++;
    
  }
  return;
  
}





void RainbowSegueHorz(unsigned long timeInSec, int msecDelay, int diag)
{
  //////Serial.println("RainbowSegueHorz");
  unsigned long exitTime = millis() + timeInSec * 1000L;
 
  int hue0 = 0;  // base color for each rep
  int hue1 = 0;
  int loopCount = 0;
  while( millis() < exitTime)
  {
    for(int col =0; col < 8; col++)
    { 
      hue1 = hue0;
      for(int row = 0; row < 50; row++)
      {
        leds[col][row] = CHSV( hue1, 255, 255);
        hue1 = (hue1 + 10)%255;
      }
    }
    hue0 =  (hue0 + 10)%255;

    diagonalize(diag);

    FastLED.show();
    delay(msecDelay);

    loopCount++;
   
  }



  
  return;
  
}


void dazzle(CRGB color0,CRGB color1, unsigned long timeInSec)
{
  ////Serial.println("dazzle");
  horzColorBandsDiag(color0, 2, color1, 2, 2, timeInSec,100);
  return;
}



void CandyCane(uint16_t countMax)
{
//  for(int loops = 0; loops < countMax; loops++)
//  {
//    for(int row = 0; row < 50; row++)
//    {
////      leds[0][row] = CHSV( hue0, 255, 255);
////      leds[1][row] = CHSV( hue1, 255, 255);
////      leds[2][row] = CHSV( hue2, 255, 255);        
////      leds[3][row] = CHSV( hue3, 255, 255);
////      leds[4][row] = CHSV( hue4, 255, 255);
////      leds[5][row] = CHSV( hue5, 255, 255);
////      leds[6][row] = CHSV( hue6, 255, 255);
////      leds[7][row] = CHSV( hue7, 255, 255);
//
//      if(row < 6)
//      else if (row < 12)
//      else if (row < 18)
//      else if (row < 24)
//      else if (row < 30)
//      else if (row < 36)
//      else if (row < 42)
//      else
////        leds[0][row] = CHSV( hue0, 255, 255);
////        leds[1][row] = CHSV( hue1, 255, 255);
////        leds[2][row] = CHSV( hue2, 255, 255);        
////        leds[3][row] = CHSV( hue3, 255, 255);
////        leds[4][row] = CHSV( hue4, 255, 255);
////        leds[5][row] = CHSV( hue5, 255, 255);
////        leds[6][row] = CHSV( hue6, 255, 255);
////        leds[7][row] = CHSV( hue7, 255, 255);
//
//    }
//    FastLED.show();
//    delay(200);
//    
//
//  }
  return;
  
}


void spiral(CRGB color[], unsigned long timeInSec, int msecDelay)
{
  ////Serial.println("spiral[]");
  FastLED.clear();
      
      spiral(GRB_DarkGreen, timeInSec, msecDelay);
      wdt_reset();                    // Reset the watchdog

      spiral(GRB_Magenta, timeInSec, msecDelay);
      wdt_reset();                    // Reset the watchdog

      spiral(GRB_KRFWhite, timeInSec, msecDelay);
      wdt_reset();                    // Reset the watchdog

      spiral(GRB_Navy, timeInSec, msecDelay);
      wdt_reset();                    // Reset the watchdog

      spiral(GRB_Teal, timeInSec, msecDelay);
      wdt_reset();                    // Reset the watchdog
    
}

void spiral2(CRGB color[], unsigned long timeInSec, int msecDelay)
{
  ////Serial.println("spiral2[]");
  FastLED.clear();
      
      mirrorSpiral(GRB_DarkGreen, timeInSec, msecDelay);
      wdt_reset();                    // Reset the watchdog

      mirrorSpiral(GRB_Magenta, timeInSec, msecDelay);
      wdt_reset();                    // Reset the watchdog

      mirrorSpiral(GRB_KRFWhite, timeInSec, msecDelay);
      wdt_reset();                    // Reset the watchdog

      mirrorSpiral(GRB_Navy, timeInSec, msecDelay);
      wdt_reset();                    // Reset the watchdog

      mirrorSpiral(GRB_Teal, timeInSec, msecDelay);
      wdt_reset();                    // Reset the watchdog

    
}


void spiral(CRGB color, unsigned long timeInSec, int msecDelay)
{
  ////Serial.println("spiral");
  int i;
  int col;
  unsigned long exitTime = millis() + timeInSec * 1000L;
//  while( millis() < exitTime)
//  {

    //wdt_reset();                    // Reset the watchdog
    FastLED.clear();
  
  
    //Loop 1  --- Col 0, Row 49, Col 7, Row 0
    for(i=0; i < 50; i++)
    {
      leds[0][i] = color;
      FastLED.show();
      delay(msecDelay);
    }
    for(col=1;col < 8; col++)
    {
      leds[col][49] = color;
      leds[col][48] = color;
      FastLED.show();
      delay(msecDelay);
    }    
    for(i=48; -1 < i; i--)
    {
      leds[7][i] = color;
      FastLED.show();
      delay(msecDelay);
    }
    for(col=6; 0 < col; col--)
    {
      leds[col][0] = color;
      leds[col][1] = color;
      FastLED.show();
      delay(msecDelay);
    }    



      
    //Loop 2  --- Col 1, Row 48, Col 6, Row 1
    for(i=2; i < 48; i++)
    {
      leds[1][i] = color;
      FastLED.show();
      delay(msecDelay);
    }
    for(col=2; col < 7; col++)
    {
      leds[col][47] = color;
      leds[col][46] = color;
      FastLED.show();
      delay(msecDelay);
    }    
    for(i=48; 0 < i; i--)
    {
      leds[6][i] = color;
      FastLED.show();
      delay(msecDelay);
    }
    for(col=5; 1 < col; col--)
    {
      leds[col][2] = color;
      leds[col][3] = color;
      FastLED.show();
      delay(msecDelay);
    }


        
    //Loop 3  --- Col 2, Row 47, Col 5, Row 2
    for(i=4; i < 46; i++)
    {
      leds[2][i] = color;
      FastLED.show();
      delay(msecDelay);
    }
    for(col=3;col < 6; col++)
    {
      leds[col][45] = color;
      leds[col][44] = color;
      FastLED.show();
      delay(msecDelay);
    }    
    for(i=48; -1 < i; i--)
    {
      leds[5][i] = color;
    FastLED.show();
    delay(msecDelay);
    }
    for(col=6; 0 < col; col--)
    {
      leds[col][4] = color;
      leds[col][5] = color;
    FastLED.show();
    delay(msecDelay);
    }    


    
    //Loop 4  --- Col 3, Row 46, Col 4, Row 2
    for(i=6; i < 44; i++)
    {
      leds[3][i] = color;
      FastLED.show();
      delay(msecDelay);
    }
    for(col=4;col < 5; col++)
    {
      leds[col][47] = color;
      FastLED.show();
      delay(msecDelay);
    }    
    for(i=48; -1 < i; i--)
    {
      leds[4][i] = color;
    FastLED.show();
    delay(msecDelay);
    }

//  }  
 
}





void mirrorSpiral(CRGB color, unsigned long timeInSec, int msecDelay)
{
  //////Serial.println("mirrorSpiral");
  int i;
  int col;
  FastLED.clear();
 
  
    //Loop 1  --- Col 0, Row 49, Col 7, Row 0
    for(i=0; i < 50; i++)
    {
      leds[0][i] = color;
      leds[7][i] = color;
      FastLED.show();
      delay(msecDelay);
    }
    for(col=1;col < 8; col++)
    {
      leds[col][49] = color;
      leds[col][48] = color;
      FastLED.show();
      delay(msecDelay);
    }    
    for(i=48; -1 < i; i--)
    {
      leds[3][i] = color;
      leds[4][i] = color;
      FastLED.show();
      delay(msecDelay);
    }
    for(col=6; 0 < col; col--)
    {
      leds[col][0] = color;
      leds[col][1] = color;
      FastLED.show();
      delay(msecDelay);
    }    



      
    //Loop 2  --- Col 1, Row 48, Col 6, Row 1
    for(i=2; i < 48; i++)
    {
      leds[1][i] = color;
      leds[6][i] = color;
      FastLED.show();
      delay(msecDelay);
    }
    for(col=2; col < 7; col++)
    {
      leds[col][47] = color;
      leds[col][46] = color;
      FastLED.show();
      delay(msecDelay);
    }    
    for(i=48; 0 < i; i--)
    {
      leds[2][i] = color;
      leds[5][i] = color;
      FastLED.show();
      delay(msecDelay);
    }
    for(col=5; 1 < col; col--)
    {
      leds[col][2] = color;
      leds[col][3] = color;
      FastLED.show();
      delay(msecDelay);
    }

}
