# 통신프로토콜

* UART 설정

|     PARAMETER     |    TYP    |
| :---------------: | :-------: |
| Baud Rate (Fixed) | 38400 bps |
|     Data Bits     |     8     |
|       Parity      |    None   |
|     Stop Bits     |     1     |
|    Flow Control   |    None   |



* MPS Sensor Data Format 방식 : IEEE 754 Format ( 부동소수점), Little Endian 형식(최하위 바이트(LSB)가 먼저 전송)



### 전체 요청(Request) Command&#x20;

<figure><img src="../../.gitbook/assets/요청_커맨드_전체.PNG" alt=""><figcaption></figcaption></figure>

* Payload는 사용에 있어서 전송되는 데이터 자체를 의미함(헤더나, 체크썸, 패리티비트, 등 제외)



* 요청(Request) Command  Packet 구조

<figure><img src="../../.gitbook/assets/요청_커맨드_세부.PNG" alt=""><figcaption></figcaption></figure>

ex) 현재 센서 상태 요청 Command

<figure><img src="../../.gitbook/assets/요청_커맨드_예시.PNG" alt=""><figcaption></figcaption></figure>

### 응답(Reply) Command  Packet 구조

<figure><img src="../../.gitbook/assets/응답_프로토콜.PNG" alt=""><figcaption></figcaption></figure>

ex) 현재 센서 상태 응답(정상일 경우만)&#x20;

<figure><img src="../../.gitbook/assets/응답_커맨드_1.PNG" alt=""><figcaption></figcaption></figure>

ex) 응답 Command 예시(정상일 경우만)&#x20;

<figure><img src="../../.gitbook/assets/응답_커맨드_2.PNG" alt=""><figcaption><p>&#x3C; 상태, 모드 설정, 가스 농도 응답 예시></p></figcaption></figure>

* 센서 Status(상태)값이 변하면 Checksum값이 변함

### < Command rely Status 표 >

<figure><img src="../../.gitbook/assets/센서_상태_커맨드1.PNG" alt=""><figcaption></figcaption></figure>

<figure><img src="../../.gitbook/assets/센서_상태_커맨드2.PNG" alt=""><figcaption><p>&#x3C; Command reply Status 표></p></figcaption></figure>

* 가장 빈번하게 발생하는 Command reply Status :

1\.     0x26(센서 초기화): 센서 초기화 시간 최대 20초까지 나타남

2\.     0x35( 호흡 or 습도 급증): 센서를 사람의 호흡이나 습도가 급증하는 환경에 노출되면 센서 값이 정확하게 나오지 않을 수 있음



### Checksum 알고리즘: 16bit CRC CCITT 알고리즘&#x20;

&#x20;  \-  Checksum이란 데이터의 오류를 검사하는데 사용되는 일련의 숫자와 문자

* 다항식 0x1021 (x^(16)+x^(12)+x^5+x )
* 시작 바이트 : 0Xffff
* 전체 패킷(헤더 및 페이로드)에 대해 계산됨, 페이로드가 없으면 헤더만으로 계산
* Checksum을 계산하기 전에 Checksum값은 0x00으로 초기화 &#x20;

참고: Checksum 계산하는 [사이트](http://www.sunshine2k.de/coding/javascript/crc/crc\_js.html)



Ex) 현재 상태 응답 Checksum 계산

<figure><img src="../../.gitbook/assets/CRC_계산_사이트_예시.PNG" alt="" width="563"><figcaption><p>&#x3C; Checksum 계산 예시 > </p></figcaption></figure>

Checksum 예제 코드

\-> [Sample code](https://nevadanano.com/wp-content/uploads/2022/10/EN-TN-0002-04-MPS-Flammable-Gas-Sensor-Sample-Code.tar.gz)



초기화 및 측정 Sequence

1\.     센서 전원은 켠 후 센서가 부팅될 때까지 기다림(\~3초)

2\.     센서 상태 확인(0x41 Command) – 초기화 완료(0x00)

3\.     센서 상태 확인이 완료되면 연속 측정 모드로 설정(0x61 Command ISO 규격 권장)

4\.     첫번째 측정이 완료될 때까지 2초 기다림



<figure><img src="../../.gitbook/assets/동작_Sequence.PNG" alt=""><figcaption></figcaption></figure>



