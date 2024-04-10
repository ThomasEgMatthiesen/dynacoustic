int mic = 0;
int pot = 0;
int ldr = 0;
int buttons = 0;

int ledAdaptive = 0;
int ledAdditive = A4;
int ledAutomatic = A5;
int ledLight = 11;
int ledTime = 12;
int ledSound = 13;

int state = 0;

int motor1 = 10;
int motor2 = 9;
int motor3 = 8;
int motor4 = 7;
int motor5 = 6;
int motor6 = 5;
int motor7 = 4;
int motor8 = 3;
int motor9 = 2;
int motor10 = 1;

int counter = 0;

void setup() 
{
    pinMode(ledAdaptive, OUTPUT);
    pinMode(ledAdditive, OUTPUT);
    pinMode(ledAutomatic, OUTPUT);
    pinMode(ledLight, OUTPUT);
    pinMode(ledTime, OUTPUT);
    pinMode(ledSound, OUTPUT);
    //Serial.begin(9600);           //Serial monitor used to determine limit values

    pinMode(motor1, OUTPUT);
    pinMode(motor2, OUTPUT);
    pinMode(motor3, OUTPUT);
    pinMode(motor4, OUTPUT);
    pinMode(motor5, OUTPUT);
    pinMode(motor6, OUTPUT);
    pinMode(motor7, OUTPUT);
    pinMode(motor8, OUTPUT);
    pinMode(motor9, OUTPUT);
    pinMode(motor10, OUTPUT);
}

void loop() {
  pot = analogRead(A1);
  buttons = analogRead(A3);

    
  if (buttons > 10) {
    if (buttons > 800) {
      state = 0;
    } else if (buttons > 200) {
      state = 1;
    } else {
      state = 2;
    } 
  }


  if (state == 0) {

    // set LEDs
    digitalWrite(ledAdaptive, HIGH);
    digitalWrite(ledAdditive, LOW);
    digitalWrite(ledAutomatic, LOW);
    
    automaticMode(0);
    
  } else if (state == 1) {

    // set LEDs
    digitalWrite(ledAdaptive, LOW);
    digitalWrite(ledAdditive, HIGH);
    digitalWrite(ledAutomatic, LOW);
    
    automaticMode(0);
    
  } else {
    
    // set LEDs
    digitalWrite(ledAdaptive, LOW);
    digitalWrite(ledAdditive, LOW);
    digitalWrite(ledAutomatic, HIGH);

    automaticMode(1);
    
  }
  
  //Serial.println(pot);               //Display the read value in the Serial monitor
  setPrisms();
}

void setPrisms() {

  if (state == 0) {
    if (pot > 5) {
    
      if (counter < 1) {
        digitalWrite(motor2, HIGH);
        delay(730);
        digitalWrite(motor2, LOW);
        delay(800);

        digitalWrite(motor4, HIGH);
        delay(700);
        digitalWrite(motor4, LOW);
        delay(800);
        
        digitalWrite(motor6, HIGH);
        delay(360);
        digitalWrite(motor6, LOW);
        delay(800);

        digitalWrite(motor8, HIGH);
        delay(540);
        digitalWrite(motor8, LOW);
        delay(800);

     //   digitalWrite(motor10, HIGH);
     //   delay(1200);
     //   digitalWrite(motor10, LOW);
     //   delay(800);


        
        counter = counter + 1;
      }
    
   } else if (pot < 5) {
       counter = 0;
   }
    
  }

}

void setState() {
  
}

void automaticMode(int x) {

  // if in other states turn off LEDs
  if (x == 0) {
    // set LEDs
    digitalWrite(ledSound, LOW);
    digitalWrite(ledTime, LOW);
    digitalWrite(ledLight, LOW);
    return;
  }
  
  if (pot > 500) { 
    
    // set LEDs
    digitalWrite(ledSound, HIGH);
    digitalWrite(ledTime, LOW);
    digitalWrite(ledLight, LOW);

    // sound-based acoustics
    mic = analogRead(A0);

    if (mic < 500) {
      // Serial.println(mic);
    }        
    delay(10);
    
  } else if (pot > 150) {

    // set LEDs
    digitalWrite(ledSound, LOW);
    digitalWrite(ledTime, HIGH);
    digitalWrite(ledLight, LOW);

    // time-based acoustics
    
  } else {

    // set LEDs
    digitalWrite(ledSound, LOW);
    digitalWrite(ledTime, LOW);
    digitalWrite(ledLight, HIGH);

    // light-based acoustics
    
    ldr = analogRead(A2);
    //Serial.println(ldr);               //Display the read value in the Serial monitor
    delay(100);
  }
}
