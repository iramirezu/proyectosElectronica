/* IR remote and receiver with Arduino and character LCD example code. More info: https://www.makerguides.com/ */
#include <IRremote.h> // include the IRremote library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#define RECEIVER_PIN 2 // define the IR receiver pin
IRrecv receiver(RECEIVER_PIN); // create a receiver object of the IRrecv class
decode_results results; // create a results object of the decode_results class
unsigned long key_value = 0; // variable to store the key value


byte Corazon[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

byte barra0[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte barra1[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};

byte barra2[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};

byte barra3[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};

byte barra4[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
};

byte barra5[] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte barra6[] = {
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte barra7[] = {
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte barra8[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};


void animacionBarra(int posX, int poxY){
  for(int i = 0; i <= 8; i++){
    
  }
}
void setup() {
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Alooo!");

  Serial.begin(9600); //inicializamos el puerto serial a 9600
  receiver.enableIRIn(); // enable the receiver
  receiver.blink13(true); // enable blinking of the built-in LED when an IR signal is received
}


void loop() {
  if (receiver.decode(&results)) { // decode the received signal and store it in results
    lcd.setCursor(0,0);
    lcd.print("Comando recibido:");
    if (results.value == 0xFFFFFFFF) { // if the value is equal to 0xFFFFFFFF
      results.value = key_value; // set the value to the key value
    }
    switch (results.value) { // compare the value to the following cases
      case 0xFD00FF: // if the value is equal to 0xFD00FF
        lcd.setCursor(0,0);
        lcd.print("");
        break;
      case 0xFFE01F: // subir volumen
        lcd.setCursor(0,1);
        lcd.print("Bajar volumen");
        Serial.println(results.value, HEX);
        delay(1000);
        lcd.setCursor(0,1);
        lcd.print("                                    ");
        
        break;
      case 0xFFA857:
        lcd.setCursor(0,1);
        lcd.print("Subir volumen");
        Serial.println(results.value, HEX);
        delay(1000);
        lcd.setCursor(0,1);
        lcd.print("                                    ");
        break;
    }
    key_value = results.value; // store the value as key_value
    receiver.resume(); // reset the receiver for the next code
  }
}
