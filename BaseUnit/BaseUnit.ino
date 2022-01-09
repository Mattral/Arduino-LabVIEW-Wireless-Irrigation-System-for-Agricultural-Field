#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define MOTOR_RELAY 7
#define SM_SENSOR A0
#define TEMP_SENSOR A1
String SWITCH_STRING = "";       choose string to HOLD data
boolean SWITCH_stringComplete = false; 
void setup()
{ 
 Serial.begin(9600);
 lcd.begin(20,4);
 pinMode(MOTOR_RELAY, OUTPUT);
 SWITCH_STRING.reserve(200);
 lcd.setCursor(0,0);
 lcd.print("WIRELESS IRREGATION ");
 lcd.setCursor(0,1);
 lcd.print("SYSTEM at UPES......");
 delay(1000);
}
void loop()
{
 if (SWITCH_stringComplete) 
      {
        lcd.clear();    
        delay(10);
              if ((SWITCH_STRING[0]=='1')&&(SWITCH_STRING[1]=='0'))
                          
              {  
               lcd.clear();     
               lcd.setCursor(0,2);
               lcd.print("MOTOR ON");
               digitalWrite(MOTOR_RELAY, HIGH);
               delay(20);
              } 
                         
               else if ((SWITCH_STRING[0]=='2')&&(SWITCH_STRING[1]=='0'))
              {
               lcd.clear(); 
               lcd.setCursor(0,2);
               lcd.print("MOTOR OFF");
               digitalWrite(MOTOR_RELAY, LOW);
               delay(20);
                               
              }
               else if ((SWITCH_STRING[0]=='3')&&(SWITCH_STRING[1]=='0'))
              {
               int ANALOG_READ_SM_SENSOR_LEVEL=analogRead(SM_SENSOR);
               int ANALOG_READ_SM_SENSOR_PPM=ANALOG_READ_SM_SENSOR_LEVEL/10;
               int ANALOG_READ_TEMP_SENSOR_LEVEL=analogRead(TEMP_SENSOR);
               int ANALOG_READ_TEMP_SENSOR_0C=ANALOG_READ_TEMP_SENSOR_LEVEL/2;
                                 
               lcd.setCursor(0,3);
               lcd.print("SMSENSOR:");
             lcd.print(ANALOG_READ_SM_SENSOR_PPM);
                                 
             lcd.setCursor(0,2);
             lcd.print("TEMP");
             lcd.print(ANALOG_READ_TEMP_SENSOR_0C);
                                 
             Serial.print("SMSENSOR:");
             Serial.print(ANALOG_READ_SM_SENSOR_PPM);
             Serial.print("TEMP:");
             Serial.println(ANALOG_READ_TEMP_SENSOR_0C);
             delay(20); 
              }
         if((SWITCH_STRING[0]==0x0A))
            {
              if ((SWITCH_STRING[1]=='1')&&(SWITCH_STRING[2]=='0'))
                          
               {  
                lcd.clear();     
                lcd.setCursor(0,2);
                lcd.print("MOTOR ON");
                digitalWrite(MOTOR_RELAY, HIGH);
                delay(20);
               } 
                         
               else if ((SWITCH_STRING[1]=='2')&&(SWITCH_STRING[2]=='0'))
               {
                lcd.clear(); 
                lcd.setCursor(0,2);
                lcd.print("MOTOR OFF");
                digitalWrite(MOTOR_RELAY, LOW);
                delay(20);
                            
               }
                else if ((SWITCH_STRING[1]=='3')&&(SWITCH_STRING[2]=='0'))
               {
                int ANALOG_READ_SM_SENSOR_LEVEL=analogRead(SM_SENSOR);
                int ANALOG_READ_SM_SENSOR_PPM=ANALOG_READ_SM_SENSOR_LEVEL/10;

                int ANALOG_READ_TEMP_SENSOR_LEVEL=analogRead(TEMP_SENSOR);
                int ANALOG_READ_TEMP_SENSOR_0C=ANALOG_READ_TEMP_SENSOR_LEVEL/2;
                                 
                lcd.setCursor(0,3);
               lcd.print("SMSENSOR:");
               lcd.print(ANALOG_READ_SM_SENSOR_PPM);
                                 
                lcd.setCursor(0,2);
                lcd.print("TEMP");
               lcd.print(ANALOG_READ_TEMP_SENSOR_0C);
                                 
                Serial.print("SMSENSOR:");
                Serial.print(ANALOG_READ_SM_SENSOR_PPM);
                Serial.print("TEMP:");
                Serial.println(ANALOG_READ_TEMP_SENSOR_0C);
                delay(20); 
               }
                                             
              }
    
     SWITCH_STRING = "";
     SWITCH_stringComplete = false;
     }
  delay(10);
  }
   
 void serialEvent() 
    {
     while (Serial.available()) 
      {
       char inChar = (char)Serial.read(); 
       SWITCH_STRING += inChar;
     if (inChar == 0x0D) 
       {
     SWITCH_stringComplete = true;
       } 
      }
    }
