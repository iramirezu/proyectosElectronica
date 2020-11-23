#include <IRremote.h>

char* UP = "FFA857"; // Change Key Code for UP Here
char* DOWN = "FFE01F"; // Change Key Code for DOWN Here
char* MUTE = "26775"; // Change Key Code for MUTE Here

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
decode_results results;



void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results)) 
  {
    switch(results.value)
    {
      case "FFA857":  
        Serial.print("A");
        break;
      case "FFE01F": 
        Serial.print("B");
        break;
      case "FFE111":  
        Serial.print("C");
        break;
      default:
        Serial.print("");
    }
    irrecv.resume(); // Receive the next value 
  }
}
