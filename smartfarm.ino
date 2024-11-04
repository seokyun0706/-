#include <LedControl.h>
LedControl lc = LedControl(12, 11, 10, 1); //LedControl(DIN, CLK, CS, NUM); (NUM은 연결된 도트매트릭스의 개수)

unsigned long delaytime = 100;

byte happy[] = {. //매투락스값이 8개가 아님(8줄로 고침)
  B00000000,
  B01000010,
  B10100101,
  B00000000,
  B00000000,
  B01000010,
  B00111100,
  B00000000
};

byte bad[] = {. //8줄로 고침
  B00000000,
  B10100101,
  B01000010,
  B00000000,
  B00000000,
  B00111100,
  B01000010,
  B00000000
};

void setup() {
  lc.shutdown(0, false);  //절전모드를 꺼줌(원래는 절전모드임)  (0,false)에서 0은 도트매트릭스 번호 의미(하나만 사용하면 0번째임)
  lc.setIntensity(0, 8); //밝기 설정
  lc.clearDisplay(0);  //화면 clear
}

void loop() {
  //소리 감지 센서, 부저 연결 및 코딩 해야함

  int moisture = analogRead(A0);
  if (moisture > 600) {
    draw(bad);
    delay(delaytime);
  } else {
    draw(happy);
    delay(delaytime);
  }
}

void draw(byte arr[]) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, arr[i]);
  }
}







