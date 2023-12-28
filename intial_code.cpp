const int livingRoomPIR = 2;
const int outdoorPIR = 3;
const int livingRoomLED = 4;
const int outdoorLED = 5;
const int livingRoomBuzzer = 6;
const int outdoorBuzzer = 7;

void setup() {
  pinMode(livingRoomPIR, INPUT);
  pinMode(outdoorPIR, INPUT);
  pinMode(livingRoomLED, OUTPUT);
  pinMode(outdoorLED, OUTPUT);
  pinMode(livingRoomBuzzer, OUTPUT);
  pinMode(outdoorBuzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int livingRoomMotion = digitalRead(livingRoomPIR);
  int outdoorMotion = digitalRead(outdoorPIR);

  if (livingRoomMotion == HIGH && outdoorMotion == LOW) {
    digitalWrite(livingRoomLED, HIGH);
    digitalWrite(livingRoomBuzzer, LOW);
  } else if (livingRoomMotion == LOW && outdoorMotion == HIGH) {
    digitalWrite(outdoorLED, HIGH);
    digitalWrite(outdoorBuzzer, LOW);
  } else if (livingRoomMotion == HIGH && outdoorMotion == HIGH) {
    digitalWrite(livingRoomLED, HIGH);
    digitalWrite(outdoorLED, HIGH);
    digitalWrite(livingRoomBuzzer, HIGH);
    digitalWrite(outdoorBuzzer, HIGH);
    delay(5000);
    digitalWrite(livingRoomBuzzer, LOW);
    digitalWrite(outdoorBuzzer, LOW);
  } else {
    digitalWrite(livingRoomLED, LOW);
    digitalWrite(outdoorLED, LOW);
    digitalWrite(livingRoomBuzzer, LOW);
    digitalWrite(outdoorBuzzer, LOW);
  }

  Serial.print("Living Room Motion: ");
  Serial.println(livingRoomMotion);
  Serial.print("Outdoor Motion: ");
  Serial.println(outdoorMotion);
  delay(1000);
}
