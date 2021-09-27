#include <Servo.h>  // Librería de datos de servomotor
#define PIRS 3      // Declaramos el sensor PIR jabón en el pin 11
#define BUS  9      // Declaramos el buzzer del jabón en el pin 9
#define bombilla 12 // Declaramos el led en el pin 12 del Arduino
#define sensor 11   // Declaramos el sensor PIR luz en el pin 11
int valor = 0;      // Variable para asignar la lectura del sensor PIR

Servo SVS;  //Declaramos nombre del servo
int LEPIRS; //Declaramos como entero el LEPIRS

void setup(){ 
  pinMode (PIRS, INPUT); //Declaramos como entrada el PIRS
  pinMode (BUS, OUTPUT); //Declaramos como salida el BUS
  SVS.attach(10);
  SVS.write(0);
  pinMode(bombilla, OUTPUT); //El pin 12 del arduino lo asignamos como salida para la bombilla
  pinMode(sensor, INPUT);     //El pin 11 lo asignamos como entrada para la señal del sensor
}

void loop(){
 LEPIRS = digitalRead(PIRS); //Lee el valor de la variable (LEPIRS)

  if (LEPIRS == 0){ //Si detecta que no hay movimiento permanece quieto el servomotor conectado en el pin 10 del Arduino
    SVS.write(0);
    delay (1000);
  }
  else if (LEPIRS == 1){ //Si detecta que hay movimiento manda a girar 90° el servomotor conectado en el pin 10 del Arduino 
                         //y a reproducir música predeterminada
    SVS.write(90);
    tone (BUS, 300, 500);
  	 delay (500);
    tone (BUS, 250, 500);
  	 delay (500);
    tone (BUS, 440, 500);
  	 delay (500);
  }
  
 valor = digitalRead(sensor); //Lee el valor de la variable (valor)
  if (valor == HIGH){ //Si detecta que hay movimiento manda activar la bombilla que hay conectado en el pin 12 del Arduino
   digitalWrite(bombilla, HIGH);
  }
  else{ //Si la condición anterior no se cumple manda apagar la bombilla
   digitalWrite(bombilla, LOW);
  }
}
