# 통신 프로토콜

* UART 설정

| PARAMETER         | TYP      |
| ----------------- | -------- |
| Baud Rate (Fixed) | 9600 bps |
| Data Bits         | 8        |
| Parity            | None     |
| Stop Bits         | 1        |
| Flow Control      | None     |



* Uart 전체 Command

<figure><img src="../../../../.gitbook/assets/all_uart_command.PNG" alt=""><figcaption></figcaption></figure>

## Mode 설정

* 초기 Mode default 설정: Passive Mode
* 전원 off 후에도 변경된 통신모드로 저장됨

| Mode          | Command (HEX)              | Description         | Response |
| ------------- | -------------------------- | ------------------- | -------- |
| Passive(Q\&A) | FF 01 78 40 00 00 00 00 47 | 센서 값 요청시에만 데이터 값 전송 |          |
| Active        | FF 01 78 41 00 00 00 00 46 | 연속적으로 데이터 값을 전송     |          |
| Sleep 들어가기    | AF 53 6C 65 65 70          | Sleep mode 들어감      | 4F 4B    |
| Sleep 나오기     | AF 45 78 69 74             | Sleep mode 나옴       | 4F 4B    |



Sleep Mode 나올 경우, 모듈 정상동작에 5초 소요 (5초 동안 data x)

## 모듈 정보 읽기

| 기 능      | Command (HEX) |
| -------- | ------------- |
| 모듈 정보 읽기 | D7            |



* 모듈 정보 읽기 응답

<figure><img src="../../../../.gitbook/assets/module_information_response.PNG" alt=""><figcaption></figcaption></figure>

가스 값 자리수 예제:

※     가스 값 응답 데이터는 가스 값 읽기 응답 참고

Ex) 01

\->정수로 표시

Ex) 11

\->가스 값 응답 데이터/10

Ex) 21

\->가스 값 응답 데이터/100

Ex) 31

\->가스 값 응답 데이터/1000



<figure><img src="../../../../.gitbook/assets/gas_type.PNG" alt=""><figcaption></figcaption></figure>

&#x20;가스 센서 값 읽기

| 기 능     | Command (HEX)              |
| ------- | -------------------------- |
| 가스 only | FF 01 86 00 00 00 00 00 79 |



## 가스 센서 값 읽기 응답:

<figure><img src="../../../../.gitbook/assets/module_gas_value_response.PNG" alt=""><figcaption></figcaption></figure>

## 가스 센서 값 + 온습도 값 읽기

| 기 능      | Command (HEX)              |
| -------- | -------------------------- |
| 가스+온도+습도 | FF 01 87 00 00 00 00 00 78 |

* 가스 센서 값 + 온습도 값 읽기 응답:

<figure><img src="../../../../.gitbook/assets/module_gas_value_and_temp_response.PNG" alt=""><figcaption></figcaption></figure>

온도 습도 예제:

Ex) - 0B 24 : 0x0B(11\*256=2816) + 0x24(36) = 2852 / 100 => 28.52 ℃ (온도)

&#x20;\- 06 DB : 0x06(6\*256=1536) + 0xDB(219) = 1755 / 100 => 17.55 %RH (습도)

## &#x20;LED 제어

&#x20;

| 기 능     | Command (HEX)              | Response |
| ------- | -------------------------- | -------- |
| LED off | FF 01 88 00 00 00 00 00 77 | 4F FB    |
| LED on  | FF 01 89 00 00 00 00 00 76 | 4F FB    |

체크섬(Checksum) 설명

&#x20;

<figure><img src="../../../../.gitbook/assets/checksum_one.PNG" alt=""><figcaption></figcaption></figure>

Data 1\~7 byte 값을 전부 더 하고 1의 보수를 취하고 1을 더함

Ex.1)

| <p>Data 1~7 byte 전부 더함 = 0x01 +0x86 = 0x87 = 1000 0111</p><p>= 0111 1000 = 0x78</p><p>= 0x78 +1</p><p>= 0x79</p> |
| ---------------------------------------------------------------------------------------------------------------- |

&#x20;

<figure><img src="../../../../.gitbook/assets/checksum_two.PNG" alt=""><figcaption></figcaption></figure>

&#x20;

Ex.2)

| <p>Data 1~7 byte 전부 더함 = 0x86 +0x2A+0x20 = 0xD0 = 1101 0000</p><p>= 0010 1111 = 0x2f</p><p>= 0x2f +1</p><p>= 0x30</p> |
| --------------------------------------------------------------------------------------------------------------------- |







