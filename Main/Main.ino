#include <SoftwareSerial.h>
int analogPin = A0;    
int AlearmPin = 13;                
int val = 0;  

//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2

void setup(){
  pinMode(AlearmPin, OUTPUT);
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, i t will back to OK
  updateSerial();
  
  
}

void loop(){

  val = analogRead(analogPin);  
  //Serial.println(val);   

  if(val < 300){
    digitalWrite(AlearmPin, HIGH);
    mySerial.println("ATD+ +8801715629560;"); //  change ZZ with country code and xxxxxxxxxxx with phone number to dial
    updateSerial();
    delay(20000); // wait for 20 seconds...
    mySerial.println("ATH"); //hang up
    updateSerial();
    digitalWrite(AlearmPin, LOW);
  }   

  else{
    digitalWrite(AlearmPin, LOW);
  }  
}




void updateSerial(){
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}