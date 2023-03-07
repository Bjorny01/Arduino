const int relay1Pin = 8;
const int relay2Pin = 9;

void setup() {
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  Serial.begin(9600); // start serial communication
}

void loop() {
  if (Serial.available() > 0) { // check if data is available to read
    char command = Serial.read(); // read the command
    if (command == '1') {
      // turn on relay 1, turn off relay 2
      digitalWrite(relay1Pin, HIGH);
      digitalWrite(relay2Pin, HIGH);
      delay(1000);
    } else if (command == '2') {
      // turn on relay 2, turn off relay 1
      digitalWrite(relay2Pin, LOW);
      digitalWrite(relay1Pin, LOW);
      delay(1000);
    } else {
      Serial.println("Wrong command, use 1 for state 1, or 2 for state 2");
      // Wrong command
    }
  }
}
