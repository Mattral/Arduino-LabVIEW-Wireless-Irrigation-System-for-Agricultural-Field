#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
#define BUTTON_MODE_SELECTION 7
#define BUTTON_PIN_MOTORON 6
#define BUTTON_PIN_MOTOROFF 5
String SM_TEMP_STRING = "";  // a string to hold incoming data
boolean SM_TEMP_stringComplete = false;  // whether the string 
is complete
void setup()
{ 
 lcd.begin(20,4);
 Serial.begin(9600);
 pinMode(BUTTON_MODE_SELECTION,INPUT_PULLUP);
 pinMode(BUTTON_PIN_MOTORON,INPUT_PULLUP);
 pinMode(BUTTON_PIN_MOTOROFF,INPUT_PULLUP);
 SM_TEMP_STRING.reserve(200);
 lcd.setCursor(0,0);
 lcd.print("WIRELESS IRREGATION ");
 lcd.setCursor(0,1);
 lcd.print("SYSTEM at UPES......");
 delay(1000);
}
void loop() 
{
int BUTTON_MODE_SELECTION_digital=digitalRead(BUTTON_MODE_ 
SELECTION);
 if (BUTTON_MODE_SELECTION_digital==LOW)
   { 
    Serial.println(30);
     if (SM_TEMP_stringComplete) 
     {
       lcd.clear();     
       lcd.setCursor(0,3);
       lcd.print(SM_TEMP_STRING );
       delay(10); 
                           
     SM_TEMP_STRING  = "";
     SM_TEMP_stringComplete = false;
     }
   }
else if(BUTTON_MODE_SELECTION_digital==HIGH)
         {
           int BUTTON_PIN_MOTORON_digital=digitalRead(BUTTON_ 
PIN_MOTORON);
           int BUTTON_PIN_MOTOROFF_digital=digitalRead(BUTTON_ 
PIN_MOTOROFF);
           if(BUTTON_PIN_MOTORON_digital==LOW)
             {
              lcd.clear();     
              lcd.setCursor(0,2);
              lcd.print("MOTOR ON");
              Serial.println(10);
             }
                 
           if(BUTTON_PIN_MOTOROFF_digital==LOW)
             {
              lcd.clear();     
              lcd.setCursor(0,2);
              lcd.print("MOTOR OFF");
              Serial.println(20);
             }
                 
         }
                   
}
  void serialEvent() 
    {
     while (Serial.available()) 
     {
      char inChar = (char)Serial.read(); 
      SM_TEMP_STRING  += inChar;
     if (inChar == 0x0D) 
     {
     SM_TEMP_stringComplete = true;
     } 
    }
    }
