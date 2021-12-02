void setup(){
  SerialUSB.begin(115200);
  while(!SerialUSB){} //USB native-serial 초기화 시간 필요


  Serial.begin(9600);//Serial:0(Rx),1(Tx), Serial1:19(Rx),18(Tx)
  delay(500); //센서에서 High 구간 인식할 시간 필요
  while(!Serial){}
  Serial.println("K 2\r\n");//센서를 Polling mode로 변경
  delay(500);
   Serial.println("Z"); CO2값 읽기 명령
}

void loop(){
  if(Serial.available()>0)//데이터가 들어오기 시작
  {
    String str = Serial.readStringUntil('\n');//LF가 들어올 때까지 읽고
    SerialUSB.println(str);//모든 내용을 시리얼 모니터로 보냄
    delay(1000);//1초간 대기
     Serial.println("Z");//CO2값 읽기 명령
  }
}
