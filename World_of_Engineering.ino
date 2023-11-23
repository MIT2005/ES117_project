#include<NewPing.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 6;
const int echoPin2 = 7;
const int trigPin3 = 4;
const int echoPin3 = 5;
const int speaker = 8;
const int led = 13;
const int btrx = 0;
const int bttx = 1;
const int dfrx = 11;
const int dftx = 12;

int max_distance = 700;
int safe_distance = 500;
int distancel;
int distancer;
int distancef;

NewPing sensorl(trigPin1, echoPin1, max_distance);
NewPing sensorr(trigPin2, echoPin2, max_distance);
NewPing sensorf(trigPin3, echoPin3, max_distance);

SoftwareSerial BTserial(btrx, bttx);
SoftwareSerial myserial(dfrx, dftx);
DFRobotDFPlayerMini musicPlayer;


void setup() {
  pinMode(speaker, OUTPUT);
  pinMode(btrx, INPUT);
  pinMode(bttx, OUTPUT);

  Serial.begin(9600);
  BTserial.begin(9600);
  myserial.begin(9600);

  musicPlayer.volume(20);
}

void loop() {
  delay(50);

  distancel = sensorl.ping_cm();
  distancer = sensorr.ping_cm();
  distancef = sensorf.ping_cm();

  if (BTserial.available()) {
    if (distancel < safe_distance){
      musicPlayer.playFolder(1, 1);
      delay(1000);
    }

    if (distancer < safe_distance){
      musicPlayer.playFolder(1, 2);
      delay(1000);
    }

    if (distancef < safe_distance){
      musicPlayer.playFolder(1, 3);
      delay(1000);
    }
  }
  
}
