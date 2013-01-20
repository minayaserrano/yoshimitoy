// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo servoh;  // create servo object to control a servo 
Servo servov;  // a maximum of eight servo objects can be created 
 
int pos, vpos = 0;    // variable to store the servo position 

void setup() 
{ 
  Serial.begin(9600);
  
  servoh.attach(11);  // attaches the servo on pin 9 to the servo object 
  servov.attach(9);
} 
 
 
void loop() 
{ 
  pos = 10;
  vpos = 10;
  for(pos = 10; pos < 100; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servoh.write(pos);              // tell servo to go to position in variable 'pos' 
    vpos = pos % 45;
    Serial.println(pos);
    servov.write(vpos);
    delay(50);                       // waits 15ms for the servo to reach the position 
  } 

  for(pos = 100; pos>=10; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servoh.write(pos);              // tell servo to go to position in variable 'pos' 
    vpos = pos%45;
    servov.write(vpos);
    delay(50);                       // waits 15ms for the servo to reach the position 
  }
  
  pos = 55;
  vpos = 10;
  
  for (vpos = 10; vpos >=35; vpos += 1)
  {
    servov.write(vpos);
    delay(100);
  }

  for (vpos = 35; vpos >=10; vpos -= 1)
  {
    servov.write(vpos);
    delay(100);
  }  
}

