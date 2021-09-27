#include <Servo.h> //librería de datos de servomotor
#define PIRS 3
#define BUS  9

Servo SVS;
int LEPIRS;

void setup(){ 
  pinMode (PIRS, INPUT);
  pinMode (BUS, OUTPUT);
  SVS.attach(11);
  SVS.write(0);
}
void loop(){
 LEPIRS = digitalRead(PIRS);

  
  if (LEPIRS == 0){
    SVS.write(0);
    delay (1000);
  }
  else if (LEPIRS == 1){
    SVS.write(90);
    tone (BUS, 300, 500);
  	 delay (500);
    tone (BUS, 250, 500);
  	 delay (500);
    tone (BUS, 440, 500);
  	 delay (500);
  }
}
