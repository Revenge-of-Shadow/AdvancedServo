#include <Servo.h>

int getInt(){
  String inString = "";
  
  while(Serial.available() <= 0){}
  
  for(;;){
    char inChar = Serial.read();
    if(isDigit(inChar)){
      inString += inChar;
    }
    if (inChar=='\n'){
      return inString.toInt();
    }
  }
}

Servo srv;

void setup() {
  Serial.begin(9600);
  while(!Serial){;}
  Serial.println("Enter the servo pin.");
  int srvPin = getInt();
  Serial.print("Setting servo on D");
  Serial.println(srvPin);
  srv.attach(srvPin);
}

void loop() {
  Serial.println("Enter the servo angle.");
  int angle = getInt();

  Serial.print("Setting servo to ");
  Serial.print(angle);
  Serial.println(" degrees.");
  srv.write(angle);
  
  delay(50);
}
