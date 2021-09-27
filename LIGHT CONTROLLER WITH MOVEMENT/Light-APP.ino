#define bombilla 12 // declaramos el led en el pin 12 del arduino
#define sensor 11 // declaramos el sensor PIR en el pin 11
int valor = 0; //variable para asignar la lectura del sensor PIR

void setup(){
 pinMode(bombilla, OUTPUT); //El pin 12 del arduino lo asignamos como salida para la bombilla
 pinMode(sensor, INPUT);//El pin 11 lo asignamos como entrada para la señal del sensor	
 
 }

void loop(){
 valor = digitalRead(sensor); //Lee el valor de la variable (valor)
  if (valor == HIGH){ //Si detecta que hay movimiento manda activar la bombilla que hay conectado en el pin 12 del arduino
   digitalWrite(bombilla, HIGH);
  }
  else{ //Si la condición anterior no se cumple manda apagar la bombilla
   digitalWrite(bombilla, LOW);
  }
}
