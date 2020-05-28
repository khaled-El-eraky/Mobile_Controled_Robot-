/*
 *Author: Khaled 
 *Created:30/5/2018
 */

 char state = 0; 
 #define motor1Pin1 3
 #define motor1Pin2 4
 #define motor2Pin1 7
 #define motor2Pin2 8
 #define enable1Pin 5
 #define enable2Pin 6

void setup() 
{
    // sets the pins as outputs:
    pinMode(motor1Pin1 , OUTPUT);
    pinMode(motor1Pin2 , OUTPUT);
    pinMode(motor2Pin1 , OUTPUT);
    pinMode(motor2Pin2 , OUTPUT);
    pinMode(enable1Pin , OUTPUT);
    pinMode(enable2Pin , OUTPUT);
    //Buad rate
    Serial.begin(9600);
}

void loop() 
{
    //if some date is sent, reads it and saves in state
    if(Serial.available() > 0)
    {     
      state = Serial.read();   
    }   
    // if the state is 'F' the DC motor will go forward
    if (state == 'F')
    {
        digitalWrite(motor1Pin1 , HIGH);
        digitalWrite(motor1Pin2 , LOW); 
        digitalWrite(motor2Pin1 , HIGH);
        digitalWrite(motor1Pin2 , LOW);
        analogWrite(enable1Pin , 150);
        analogWrite(enable2Pin , 140);    
    }
    
    // if the state is 'R' the Robot will turn Right
    else if (state == 'R')
    {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        analogWrite(enable1Pin, 150);
        analogWrite(enable2Pin, 0);
        delay(500);
        digitalWrite(motor1Pin1 , HIGH);
        digitalWrite(motor1Pin2 , LOW); 
        digitalWrite(motor2Pin1 , HIGH);
        digitalWrite(motor1Pin2 , LOW);
        analogWrite(enable1Pin , 150);
        analogWrite(enable2Pin , 140);
    }

    // if the state is 'L' the Robot will turn Left
    else if (state == 'L') 
    {
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        analogWrite(enable1Pin, 0);
        analogWrite(enable2Pin, 140);
        delay(500);
        digitalWrite(motor1Pin1 , HIGH);
        digitalWrite(motor1Pin2 , LOW); 
        digitalWrite(motor2Pin1 , HIGH);
        digitalWrite(motor1Pin2 , LOW);
        analogWrite(enable1Pin , 150);
        analogWrite(enable2Pin , 140);
    }
    
    // if the state is 'S' the motor will Stop
    else if (state == 'S') 
    {
        analogWrite(enable1Pin, 0);
        analogWrite(enable2Pin, 0);   
    }
    
    // if the state is 'B' the Robot will Back
    else if (state == 'B') 
    {
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        analogWrite(enable1Pin, 150);
        analogWrite(enable2Pin, 140);
    }
}
