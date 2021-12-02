void setup(){
  SerialUSB.begin(115200);
  while(!SerialUSB){}


Serial.begin(9600);
delay(500);
while(!Serial){}
Serial.println("K 2\r\n");
delay(500);
Serial.println("Z");
}

void loop(){
  if(Serial.available()>0)
  {
    String str = Serial.readStringUntil('\n');
    SerialUSB.println(str);
    delay(1000);
     Serial.println("Z");
  }
}
