---
description: CozIR-LP2를 선택해 주셔서 감사합니다. 제품 활용 방법에 도움이 되는 모든 문서를 제공하였습니다.
---

# CozIR-LP2

![CozIR-LP2](../../.gitbook/assets/CozIR-LP2ex.jpg)

## 1.Overview

#### 1)제품 설명

: CozIR-LP2는 최첨단 Solid-State LED 광학 기술을 이용한 초 저전력 NDIR CO₂ 센서입니다.

#### 2)제품 특징

* 최대 1%(10,000ppm) CO₂ 농도 측정
* Solid-State, 움직이는 부품 없음, 가열된 필라멘트 없음
* 진동 및 충격에 강하고 비가열성
* 디지털(UART) 및 I2C 출력
* 일반 NDIR CO₂ 센서보다 최대 50배 낮은 전력
* 간편한 계측 통합을 위한 작은 크기
* 긴 수명, 낮은 유지 보수
* 무선, 휴대용, 웨어러블 및 배터리에 이상적
* 에너지 효율적인 스마트 홈 환경 지원
* IAQ, HVAC, 빌딩 자동화, 계측, 농업, MAP, 자동차, 항공우주 및 안전과 같은 애플리케이션에 쉽게 통합

#### 3)Documents

* Datasheet[(PDF링크)](https://cdn.shopify.com/s/files/1/0019/5952/files/CozIR-LP2\_Data\_Sheet\_Rev\_4.10.pdf)
* User Guide[(PDF링크)](https://cdn.shopify.com/s/files/1/0019/5952/files/CO2Meter-GSS-COZIR-LP2-User-Guide-Rev-4.0.pdf)
* 치수 도면[(PDF링크)](https://cdn.shopify.com/s/files/1/0019/5952/files/Mechanical\_Diagram\_-\_CozIR-LP2-CO2Meter.pdf)

## 2.Quickstart

#### 1)전제 조건

: CozIR-LP2를 사용하는 각 단계를 진행하기 전에 아래 나열된 필수 항목을 준비해야 합니다. (CozIR-LP2 CO₂ Sensor 중에 Pin이 부착되어 있는 센서는 Allsensing에서 자체 제작한 PCB가 같이 있으면 작업이 더욱 수월합니다.)

**하드웨어**

* CozIR-LP2 CO₂ Sensor.
* [CozIR용 PCB](https://www.allsensing.com/product/detail.html?product\_no=1171\&cate\_no=65\&display\_group=1)(Connector 포함 / Allsensing 자체 제작)
* Arduino Due.
* Arduino Jumper wires Female-male 20cm 4pcs.
* USB 2.0 Micro B Cable

**소프트웨어(Arduino IDE를 통한 프로그래밍)**

* [Arduino IDE 설치](https://www.arduino.cc/en/software)
* [Arduino Due 시작하기](https://www.arduino.cc/en/Guide/ArduinoDue)
* Arduino 실행 -> Tools -> Board -> Board Manager -> Filter your search 창에 Due를 입력한 후 설치합니다.

#### 2)제품 구성

![](<../../.gitbook/assets/cozir lp2 connecting with arduino due.jpg>)

1. 위 그림과 같이 Arduino Due와 PCB를 연결합니다.
2. PCB와 CozIR-LP2 CO₂ Sensor를 연결합니다.(단, Sensor의 Vcc, GND, Rx, Tx는 확인하고 부착)
3. Arduino Due 뒷면에서 Programming Port와 Native USB Port 중에서는 원하시는 Port에 Micro-B USB Cable을 연결하세요.(Allsensing은 Programming Port에 연결)
4. 사용자 Board, Port를 알맞게 설정합니다.
5. 예제 Code를 넣은 후 컴파일 및 시리얼 모니터를 확인합니다.

## 3. 예제 Code(Arduino Due Base)

```arduino
void setup(){
  Serial.begin(9600); //시리얼 통신 초기화
   Serial1.begin(9600); //DUE Tx Rx (18 19) = Serial1
  delay(500); //0.5초 지연
  while(!Serial1){}
  Serial1.println("K 2"); //Polling 모드로 변경     
  delay(500);
   Serial1.println("Z"); //CO2값 읽기 명령
}

void loop(){
  //수신받은 데이터가 0 초과, 즉 데이터가 존재한다면
  if(Serial1.available()>0) //코드수행
  {
    String str = Serial1.readStringUntil('\n');// 들어오는 문자열 읽기
    Serial.println(str);//CO2값 읽기 명령
    delay(1000);//1초 지연
    Serial1.println("Z");//CO2값 읽기 명령
  }
}
```

![](<../../.gitbook/assets/CozIR serial monitor ex.jpg>)

Z:디지털 필터링 후 CO₂ 농도

z:디지털 필터링이 없는 즉각적인 CO₂ 농도

## 4.Currently CozIR-LP2 Monitoring

## 5.참조

* [Sensor Datasheet](https://www.co2meter.com/products/copy-of-cozir-lp-miniature-5-000ppm-co2-sensor)
