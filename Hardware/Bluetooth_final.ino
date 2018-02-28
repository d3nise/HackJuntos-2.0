#include <SoftwareSerial.h>
#include <Servo.h>

const int button1 = 8; //User button
const int button2 = 9; //User button
//const int button3 = 5; //Nurse Button
const int pled = 12;
int buttonState = 0; //Indicates button state
int buttonState2 = 0; //Indicates button state

int tx = 1;
int rx = 0;
//int inSerial[5];

int BluetoothData;

void setup() {
  Serial.begin(9600);
  //Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);

}

void loop() {
  if (Serial.available()) {
    BluetoothData = Serial.read();
    delay(100);
    
    if (BluetoothData == 3) {
      digitalWrite(13, HIGH);
      Serial.println("Light On");
    }
    
    if (BluetoothData == 2) {
      digitalWrite(13, LOW);
      Serial.println("Light Off");
    }

    Serial.println("In Button Loop");
    buttonState = digitalRead(button1);
  }
  delay(500);
  if (digitalRead(button1) == 1) {
    Serial.println(100);
  }
}
