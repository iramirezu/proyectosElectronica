/*

Reports a tone the number of times a speaker is tapped
Speaker is connected between A0 and ground
Don't push the speaker too hard!!
Add a potentiometer for setting the threshold pulse from speaker
A piezo disk can be used with a 10k resistor in parallel with the disk
the threshold signal must be adjusted for a disk and you can tape
it to a table or box to help it sound louder
Created by Dorian McIntire - dorianmc@gmail.com

*/

byte tapCount = 0;
long int tapTime = millis();

void setup()
{
}

int B2 = 123;
      int D3 = 146;
      int E3 = 164;
      int G3 = 196;
      int Fs3 = 185;
void loop()
{
int sensorValue = analogRead(A1);
Serial.println(sensorValue);


if(sensorValue > 3) //detect a tap
  {
    delay(110);
    tapCount = tapCount + 1; //increment tap count
    tapTime = millis(); //record current system time
  } //end if 1
pinMode(A1,OUTPUT);

if (tapTime < (millis() - 10)) //if more than 0.4 seconds have elapsed since last tap
{
  for(int x=0; x < tapCount; x++)
    {
      // B2, D3, E3, G3, G3, F3#, G3, F3#, G3, F3#, E3
      
      
      tone(A1,B2);
      delay(50);
      tone(A1,D3);
      delay(50);
      tone(A1,E3);
      delay(50);
      tone(A1,G3);
      delay(50);
      tone(A1,G3);
      delay(50);
      noTone(A1);
      delay(15);
      tone(A1,Fs3);
      delay(50);
      tone(A1,G3);
      delay(35);
      tone(A1,Fs3);
      delay(50);
      tone(A1,G3);
      delay(35);
      tone(A1,Fs3);
      delay(50);
      tone(A1,E3);
      delay(65);
      noTone(A1);


    }//end for
  pinMode(A1,INPUT);
  tapCount = 0;
}//end if 2

delay(5); // delay in between reads for stability
} // end loop
