#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <Servo.h> 

int RECV_PIN = 2; //declaramos el pin que recibira la señal
IRrecv irrecv(RECV_PIN);
decode_results results;


int led = 13;
int servoPin = 10; 
Servo Servo1; 

int grados = 0;

void setup() {
  Serial.begin(9600); //inicializamos el puerto serial a 9600
  irrecv.enableIRIn(); // Comienza a recibir los datos

  Servo1.attach(servoPin); 
  //Servo1.write(0); // 10 grados
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); // imprime el valor en codigo hexadecimal
    irrecv.resume(); // Se preparar para recibir el siguiente valor
    delay(10);
    // 0xFF30CF == 1
    // 0xFF6897 == 0
    // 0xFFE01F == -
    // 0xFFA857 == +
    
    if(results.value == 0xFF6897){
        digitalWrite(led, HIGH);
    }

    if(results.value == 0xFF30CF){
        digitalWrite(led, LOW);
    }

    if(results.value == 0xFFA857){
        //grados = grados + 10;
        //if(grados >= 180){
        //  grados = 180;
        //}else{
        //  Servo1.write(grados); // 10 grados
        //} 
        Servo1.write(180); // 10 grados
        delay(500);
    }

    if(results.value == 0xFFE01F){
        
        Servo1.write(0); // 10 grados
        delay(500);
    }

    

    
  };
  
  
}
