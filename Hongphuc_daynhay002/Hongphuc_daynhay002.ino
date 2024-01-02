

#include <FastLED.h>
#include <SimpleKalmanFilter.h>
SimpleKalmanFilter simpleKalmanFilter1(2, 2, 0.01);
SimpleKalmanFilter simpleKalmanFilter2(2, 2, 0.01);
SimpleKalmanFilter simpleKalmanFilter3(2, 2, 0.01);
SimpleKalmanFilter simpleKalmanFilter4(2, 2, 0.01);
const long SERIAL_REFRESH_TIME = 100;
#define ArrayLength 20
#define LED_PIN 7
#define NUM_LEDS 32
int arr[100];

int val1OfZero, val1Of90, val1Of180, val2OfZero, val2Of90, val2Of180, val3OfZero, val3Of90, val3Of180, val4OfZero, val4Of90, val4Of180;
CRGB leds[NUM_LEDS];
void setup() {
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  leds[5] = CRGB::Black;
  leds[6] = CRGB::Black;
  leds[7] = CRGB::Black;
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(A4, INPUT);
  pinMode(A7, INPUT);
   pinMode(A6, INPUT);
  // pinMode(10, OUTPUT);
  // pinMode(13, OUTPUT);
  // pinMode(12, OUTPUT);
  Serial.println("Yeu cau hieu chinh");
  delay(3000);
  Serial.println("chuanbi");
  // val1OfZero = calculateOriginalAngleValue1();
  // val2OfZero = calculateOriginalAngleValue2();
  // val3OfZero = calculateOriginalAngleValue3();
  //  val4OfZero = calculateOriginalAngleValue3();
  // val1OfZero = calculateOriginalAngleValue1();
  // val2OfZero = calculateOriginalAngleValue2();
  // val3OfZero = calculateOriginalAngleValue3();
  Serial.println("ve 0 do");
  leds[2] = CRGB::Purple;
  leds[5] = CRGB::Purple;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[2] = CRGB::Black;
  leds[5] = CRGB::Black;
  FastLED.show();

  delay(2000);
  val1OfZero = calculateOriginalAngleValue1();
  val2OfZero = calculateOriginalAngleValue2();
  val3OfZero = calculateOriginalAngleValue3();
  val4OfZero = calculateOriginalAngleValue3();
  Serial.println("ve 90 do");
  leds[2] = CRGB::Purple;
  leds[5] = CRGB::Purple;

  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[2] = CRGB::Black;
  leds[5] = CRGB::Black;
  FastLED.show();

  delay(2000);
  val1Of90 = calculateOriginalAngleValue1();
  val2Of90 = calculateOriginalAngleValue2();
  val3Of90 = calculateOriginalAngleValue3();
   val4Of90 = calculateOriginalAngleValue3();
  Serial.println("ve 180 do");
  leds[2] = CRGB::Purple;
  leds[5] = CRGB::Purple;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[2] = CRGB::Black;
  leds[5] = CRGB::Black;
  FastLED.show();
  delay(2000);
  val1Of180 = calculateOriginalAngleValue1();
  val2Of180 = calculateOriginalAngleValue2();
  val3Of180 = calculateOriginalAngleValue3();
  val4Of180 = calculateOriginalAngleValue3();
  Serial.println("Done....");

  // Turn the LED on, then pause
  leds[2] = CRGB::White;
  leds[5] = CRGB::White;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[2] = CRGB::Black;
  leds[5] = CRGB::Black;
  FastLED.show();
  delay(500);
  leds[2] = CRGB::White;
  leds[5] = CRGB::White;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[2] = CRGB::Black;
  leds[5] = CRGB::Black;
  FastLED.show();
  delay(500);

  Serial.print(val1OfZero);
  Serial.print(val1Of90);
  Serial.println(val1Of180);
  delay(5000);
  FastLED.setBrightness(20);
}

void loop() {
  int real_value1 = analogRead(A1);
  int real_value2 = analogRead(A4);
  int real_value3 = analogRead(A7);
   int real_value4 = analogRead(A6);
  // put your main code here, to run repeatedly:
  int estimated_value1 = simpleKalmanFilter1.updateEstimate(real_value1);
  int estimated_value2 = simpleKalmanFilter2.updateEstimate(real_value2);
  int estimated_value3 = simpleKalmanFilter3.updateEstimate(real_value3);
 int estimated_value4 = simpleKalmanFilter3.updateEstimate(real_value4);
  // Serial.print("flex1:");
  Serial.print(estimated_value1);
  Serial.print(",");
  Serial.print(real_value1);
  Serial.print(",");
  Serial.print(val1OfZero);
  Serial.print(",");
  Serial.print(val1Of90);
  Serial.print(",");
  Serial.print(val1Of180);
  Serial.print("\t flex2:");
  Serial.print(estimated_value2);
  Serial.print(",");
  Serial.print(real_value2);
  Serial.print(",");
  Serial.print(val2OfZero);
  Serial.print(",");
  Serial.print(val2Of90);
  Serial.print(",");
  Serial.print(val2Of180);
  Serial.print("\t flex3:");
  Serial.print(estimated_value3);
  Serial.print(",");
  Serial.print(real_value3);
  Serial.print(",");
  Serial.print(val3OfZero);
  Serial.print(",");
  Serial.print(val3Of90);
  Serial.print(",");
  Serial.print(val3Of180);
   Serial.print("\t flex4:");
  Serial.print(estimated_value4);
  Serial.print(",");
  Serial.print(real_value4);
  Serial.print(",");
  Serial.print(val4OfZero);
  Serial.print(",");
  Serial.print(val4Of90);
  Serial.print(",");
  Serial.print(val4Of180);
  Serial.println();


  if (abs(estimated_value1 - val1OfZero) < 30) {
    ledxanh(0, 1);
     ledxanh(2, 3);
      ledxanh(4, 5);
       ledxanh(6, 7);
  } else if (abs(estimated_value1 - val1Of90) < 30) {
     ledvang(0, 1);
     ledvang(2, 3);
      ledvang(4, 5);
       ledvang(6, 7);
  } else if (abs(estimated_value1 - val1Of180) < 30) {
     leddo(0, 1);
     leddo(2, 3);
      leddo(4, 5);
       leddo(6, 7);
  } else {
     leddo(0, 1);
     leddo(2, 3);
      leddo(4, 5);
       leddo(6, 7);
  }

  if (abs(estimated_value2 - val2OfZero) < 30) {
   ledxanh(8, 9);
     ledxanh(10, 11);
      ledxanh(12, 13);
       ledxanh(14, 15);
  } else if (abs(estimated_value2 - val2Of90) < 30) {
    ledvang(8, 9);
     ledvang(10, 11);
      ledvang(12, 13);
       ledvang(14, 15);
  } else if (abs(estimated_value2 - val2Of180) < 30) {
     leddo(8, 9);
     leddo(10, 11);
      leddo(12, 13);
       leddo(14, 15);
  } else {
     leddo(8, 9);
     leddo(10, 11);
      leddo(12, 13);
       leddo(14, 15);
  }

  if (abs(estimated_value3 - val3OfZero) < 30) {
    ledxanh(16, 17);
     ledxanh(18, 19);
      ledxanh(20, 21);
       ledxanh(22, 23);
  } else if (abs(estimated_value3 - val3Of90) < 30) {
     ledvang(16, 17);
     ledvang(18, 19);
      ledvang(20, 21);
       ledvang(22, 23);
  } else if (abs(estimated_value3 - val3Of180) < 30) {
    leddo(16, 17);
     leddo(18, 19);
      leddo(20, 21);
       leddo(22, 23);
  } else {
     leddo(16, 17);
     leddo(18, 19);
      leddo(20, 21);
       leddo(22, 23);
  }
if (abs(estimated_value4 - val4OfZero) < 30) {
    ledxanh(24, 25);
     ledxanh(26, 27);
      ledxanh(28, 29);
       ledxanh(30, 31);
  } else if (abs(estimated_value4 - val4Of90) < 30) {
    ledvang(24, 25);
     ledvang(26, 27);
      ledvang(28, 29);
       ledvang(30, 31);
  } else if (abs(estimated_value4 - val4Of180) < 30) {
    leddo(24, 25);
     leddo(26, 27);
      leddo(28, 29);
       leddo(30, 31);
  } else {
    leddo(24, 25);
     leddo(26, 27);
      leddo(28, 29);
       leddo(30, 31);
  }


  delay(SERIAL_REFRESH_TIME);
}

int calculateOriginalAngleValue1() {
  int tong;
  int k = 0;
  for (int i = 0; i < ArrayLength; i++) {
    tong += simpleKalmanFilter1.updateEstimate(analogRead(A1));

    delay(100);
  }

  return tong / ArrayLength;
}
int calculateOriginalAngleValue2() {
  int tong;
  for (int i = 0; i < ArrayLength; i++) {
    tong += simpleKalmanFilter2.updateEstimate(analogRead(A4));
    delay(100);
  }
  return tong / ArrayLength;
}
int calculateOriginalAngleValue3() {
  int tong;
  for (int i = 0; i < ArrayLength; i++) {
    tong += simpleKalmanFilter3.updateEstimate(analogRead(A7));
    delay(100);
  }
  return tong / ArrayLength;
}
int calculateOriginalAngleValue4() {
  int tong;
  for (int i = 0; i < ArrayLength; i++) {
    tong += simpleKalmanFilter4.updateEstimate(analogRead(A6));
    delay(100);
  }
  return tong / ArrayLength;
}

void resetToZero(int* arr, int length) {
  for (int i = 0; i < length; i++) {
    arr[i] = 0;
  }
}



void ledxanh(int i, int j) {
  leds[i] = CRGB(0, 255, 0);  // xanh
  leds[j] = CRGB(0, 255, 0);
  FastLED.show();
}
void ledtrang(int i, int j) {
  leds[i] = CRGB(255, 255, 255);  // xanh
  leds[j] = CRGB(255, 255, 255);
  FastLED.show();
}

void ledvang(int i, int j) {
  leds[i] = CRGB(255, 255, 0);  // vàng
  leds[j] = CRGB(255, 255, 0);
  FastLED.show();
}
void leddo(int i, int j) {
  leds[i] = CRGB(255, 0, 0);  // đỏ
  leds[j] = CRGB(255, 0, 0);
  FastLED.show();
}


/*
0 độ : xanh
90 độ : vàng
180 độ : đỏ
*/
