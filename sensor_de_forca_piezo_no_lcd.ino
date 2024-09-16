const int piezoBefore = A1;
const int piezoAfter = A2;
const int threshold = 10;

int readingBefore = 0;
int readingAfter = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  readingBefore = analogRead(piezoBefore);
  readingAfter = analogRead(piezoAfter);
  
  float piezoVBefore = readingBefore / 1023.0 * 5.0;
  float piezoVAfter = readingAfter / 1023.0 * 5.0;

if (readingBefore >= threshold) {
    Serial.print("P1: ");
    Serial.println(piezoVBefore, 2);
    
    Serial.print("P2: ");
    
    if (readingAfter > 0) {
      Serial.println(piezoVAfter, 2);
    } else {
      Serial.print("0.00");
    }
    delay(5000);

  } else {
    Serial.print("Aguardando...");
    delay(800);
  }
}
