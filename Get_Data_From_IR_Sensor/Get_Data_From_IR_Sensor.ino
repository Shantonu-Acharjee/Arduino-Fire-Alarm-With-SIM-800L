int analogPin = A0;    
int AlearmPin = 13;                
int val = 0;  

void setup() {
  Serial.begin(9600);  
  pinMode(AlearmPin, OUTPUT);      
}

void loop() {

  val = analogRead(analogPin);  
  Serial.println(val);   

  if(val < 300){
    digitalWrite(AlearmPin, HIGH);
    delay(3000);
  }   

  else{
    digitalWrite(AlearmPin, LOW);
  }  
}