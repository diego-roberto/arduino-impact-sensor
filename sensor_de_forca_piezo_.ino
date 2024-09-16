#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

const int buttonPin = A0;
const int UP_THRESHOLD_MIN = 99;
const int UP_THRESHOLD_MAX = 200;
const int DOWN_THRESHOLD_MIN = 250;
const int DOWN_THRESHOLD_MAX = 300;
const int SELECT_THRESHOLD_MIN = 650;
const int SELECT_THRESHOLD_MAX = 750;

const int piezoBefore = A1;
const int piezoAfter = A2;

int threshold = 10;
int readingBefore = 0;
int readingAfter = 0;

void setup() {
  lcd.begin(16, 2);  
  lcd.print("Sensor de Forca");
  delay(2000);
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  readingBefore = analogRead(piezoBefore);
  readingAfter = analogRead(piezoAfter);
  int buttonValue = analogRead(buttonPin);
  
  float piezoVBefore = readingBefore / 1023.0 * 5.0;
  float piezoVAfter = readingAfter / 1023.0 * 5.0;

if (readingBefore >= threshold) {
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print("P1: ");
    lcd.print(piezoVBefore, 2);
    
    lcd.setCursor(0, 1);
    lcd.print("P2: ");
    
    if (readingAfter > 0) {
      lcd.print(piezoVAfter, 2);
    } else {
      lcd.print("0.00");
    }
    delay(5000);

  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Aguardando...");
    lcd.setCursor(0, 1);
    lcd.print("Sensib.:");
    lcd.print(threshold);
    delay(800);
  }

  if (buttonValue >= UP_THRESHOLD_MIN && buttonValue <= UP_THRESHOLD_MAX) {
    threshold += 5;
    if (threshold > 1023) {
      threshold = 1023;
    }
  }
  
  if (buttonValue >= DOWN_THRESHOLD_MIN && buttonValue <= DOWN_THRESHOLD_MAX) {
    threshold -= 5;
    if (threshold < 1) {
      threshold = 1;
    }
  }

  if (buttonValue >= SELECT_THRESHOLD_MIN && buttonValue <= SELECT_THRESHOLD_MAX) {
    lcd.clear();
    piezoVBefore = 0;
    piezoVAfter = 0;
    threshold = 10;
  }
}


//    Serial.print("piezoBf: ");
//    Serial.println(piezoVBefore);
