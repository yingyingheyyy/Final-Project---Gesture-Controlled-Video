//Creative Coding 2022 Fall Final Project 
//Yingying He
//inspo:https://www.youtube.com/watch?v=NkoReWaP2NU

const int trig = 11;
const int echo = 12;
int t1 = 5;
int duration = 0;
int distance = 0;

int i;

void setup() {

  //ultrasonic sensor
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);

  //LEDS
  for (i = 2; i <= 5; i++) {

  pinMode(i, OUTPUT);

  }
  Serial.begin(9600);

}


void loop() {

  digitalWrite(trig , HIGH);

  delayMicroseconds(1000);

  digitalWrite(trig , LOW);

  duration = pulseIn(echo , HIGH);

  distance = (duration / 2) / 29.1 ;

  Serial.println(distance);

  delay(100);

// Control which light to blink from different distances

if (distance <= 5) {
      flashingLight(); 
       
  } else if (distance >= 6 && distance <= 19) {
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    

  } else if (distance >= 20 && distance <= 34 ) {

    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);

  } else if (distance >= 35 && distance <= 49) {
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
  } else if (distance >= 50 && distance <= 64){
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
  }

}

//flash lighhts from left to right and right to left
  void flashingLight() {
    for (int i = 2; i <= 5; i++) {
      digitalWrite(i, HIGH);
      delay(t1);
      digitalWrite(i + 1, HIGH);
      delay(t1);
      digitalWrite(i + 2, HIGH);
      delay(t1);
      digitalWrite(i, LOW);
      delay(t1);
      digitalWrite(i + 1, LOW);
      delay(t1);
    }
    for (int i = 5; i >= 2; i--) {
      digitalWrite(i, HIGH);
      delay(t1);
      digitalWrite(i - 1, HIGH);
      delay(t1);
      digitalWrite(i - 2, HIGH);
      delay(t1);
      digitalWrite(i, LOW);
      delay(t1);
      digitalWrite(i - 1, LOW);
      delay(t1);
    }
  }
  
  // function to switch all LEDs off
  void switchoffLed(void) {
    for (int i = 2; i <= 5; i++) {
      digitalWrite(i, LOW);
    }
  }
