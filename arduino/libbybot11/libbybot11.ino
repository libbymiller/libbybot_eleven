#include <Servo.h>

#define SERVOPIN1 4
#define SERVOPIN2 5
#define SERVOPIN3 6
#define SERVOPIN4 7

Servo myservo;  // create servo object to control a servo

// variable to store the servo position

int last_pos1 = 0;

int last_pos2 = 0;

//not currently used
int last_pos3 = 0;
int last_pos4 = 0;

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

}

int which_motor;
int motor_position;
String sign;
String str;

void loop() 
{
    if(Serial.available() > 0)
    {
        str = Serial.readStringUntil('\n');
        Serial.println("str is ");
        Serial.println(str);
        String xval = getValue(str, ' ', 0);
        String yval = getValue(str, ' ', 1);

        //for relative values
        String rval = getValue(str, ' ', 2);
        Serial.println(rval);
        
        which_motor = xval.toInt();
        motor_position = yval.toInt();
        sign = rval;
        
        Serial.println("which_motor is ");
        Serial.println(which_motor);
        Serial.println("motor_position is ");
        Serial.println(motor_position);
        
        switch(which_motor){
        case 1:
          myservo.attach(SERVOPIN1);  
          if(sign == "p"){
             motor_position = last_pos1 + motor_position;
          }else if(sign == "n"){
             motor_position = last_pos1 - motor_position;   
          }
          if(last_pos1 < motor_position){
           for (int pos = last_pos1; pos <= motor_position; pos += 1) { // goes from 0 degrees to 180 degrees
             // in steps of 1 degree
             myservo.write(pos);// tell servo to go to position in variable 'pos'
             delay(15);          // waits 15ms for the servo to reach the position
             last_pos1 = pos;
           }
          }else{
           for (int pos = last_pos1; pos >= motor_position; pos -= 1) { // goes from 0 degrees to 180 degrees
             // in steps of 1 degree
             myservo.write(pos);// tell servo to go to position in variable 'pos'
             delay(15);                       // waits 15ms for the servo to reach the position
             last_pos1 = pos;
           }              
          }
          myservo.detach();
          break;
        case 2:
          myservo.attach(SERVOPIN2);
          if(sign == "p"){
             motor_position = last_pos2 + motor_position;
          }else if(sign == "m"){
             motor_position = last_pos2 - motor_position;   
          }
          if(last_pos2 < motor_position){
           for (int pos = last_pos2; pos <= motor_position; pos += 1) { // goes from 0 degrees to 180 degrees
             // in steps of 1 degree
             myservo.write(pos);// tell servo to go to position in variable 'pos'
             delay(15);                       // waits 15ms for the servo to reach the position
             last_pos2 = pos;
           }
          }else{
           for (int pos = last_pos2; pos >= motor_position; pos -= 1) { // goes from 0 degrees to 180 degrees
             // in steps of 1 degree
             myservo.write(pos);// tell servo to go to position in variable 'pos'
             delay(15);                       // waits 15ms for the servo to reach the position
             last_pos2 = pos;
           }              
          }
          myservo.detach();
          break;
        case 3:
          myservo.attach(SERVOPIN3);          
          if(sign == "p"){
             motor_position = last_pos3 + motor_position;
          }else if(sign == "m"){
             motor_position = last_pos3 - motor_position;   
          }
          if(last_pos3 < motor_position){
           for (int pos = last_pos3; pos <= motor_position; pos += 1) { // goes from 0 degrees to 180 degrees
             // in steps of 1 degree
             myservo.write(pos);// tell servo to go to position in variable 'pos'
             delay(15);                       // waits 15ms for the servo to reach the position
             last_pos3 = pos;
           }
          }else{
           for (int pos = last_pos3; pos >= motor_position; pos -= 1) { // goes from 0 degrees to 180 degrees
             // in steps of 1 degree
             myservo.write(pos);// tell servo to go to position in variable 'pos'
             delay(15);                       // waits 15ms for the servo to reach the position
             last_pos3 = pos;
           }              
          }
          break;
          myservo.detach();
        case 4:
          myservo.attach(SERVOPIN4);          
          if(sign == "p"){
             motor_position = last_pos4 + motor_position;
          }else if(sign == "m"){
             motor_position = last_pos4 - motor_position;  
          }
          if(last_pos4 < motor_position){
           for (int pos = last_pos4; pos <= motor_position; pos += 1) { // goes from 0 degrees to 180 degrees
             // in steps of 1 degree
             myservo.write(pos);// tell servo to go to position in variable 'pos'
             delay(15);                       // waits 15ms for the servo to reach the position
             last_pos4 = pos;
           }
          }else{
           for (int pos = last_pos4; pos >= motor_position; pos -= 1) { // goes from 0 degrees to 180 degrees
             // in steps of 1 degree
             myservo.write(pos);// tell servo to go to position in variable 'pos'
             delay(15);                       // waits 15ms for the servo to reach the position
             last_pos4 = pos;
           }              
          }
          myservo.detach();
          break;
        }        
        //blink(x);
    }
}


int blink(int i){
        if(i){
          for(int j=0; j< i; j++){
           digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
           delay(1000);                       // wait for a second
           digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
           delay(1000);
          } 
        }
}

// https://arduino.stackexchange.com/questions/1013/how-do-i-split-an-incoming-string
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

