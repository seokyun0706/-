#include <LedControl.h>
LedControl lc = LedControl(12, 11, 10, 1); //LedControl(DIN, CLK, CS, NUM); (NUM은 연결된 도트매트릭스의 개수)

int aa = 6;
int ab = 5;

byte happy[] = {
  B00000000,
  B01000010,
  B10100101,
  B00000000,
  B00000000,
  B01000010,
  B00111100,
  B00000000
};

byte bad[] = {
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
  lc.setIntensity(0, 7); //밝기 설정
  lc.clearDisplay(0);  //화면 clear

  pinMode(aa, OUTPUT); //모터 드라이브 A-A
  pinMode(ab, OUTPUT); //모터 드라이브 A-B

  pinMode(sound, INPUT); //소리센서

  pinMode(rec, OUTPUT); //녹음
  pinMode(plye, OUTPUT); //출력
}

void loop() {
  int moisture = analogRead(A0);
  int sound = analogRead(A1);

  swith() {
    
  }

  if (sound > 600) {
    if (moisture > 600) {
      
      draw(bad);
      delay(100);
      digitalWrite(aa, HIGH);
      digitalWrite(ab, LOW);
      delay(1000);
    } else {

      draw(happy);
      delay(100);
      digitalWrite(aa, LOW);
      digitalWrite(ab, LOW);
      delay(1000);
    }
  } else {
    lc.clearDisplay(0);
  }
}

void draw(byte arr[]) {
  for (int i = 0; i < 8; i++) {
    lc.setColumn(0, 7-i, arr[i]);
  }
}
