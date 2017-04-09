
/*
 * This project was about making a small vehicle follow a black line around a course, 
 * using an arduino uno, some motors, wheels, batteries and light dependent resistors.
 */


#define E1 10  // Enable   Pin for motor 1
#define E2 11  // Enable Pin for motor 2

#define I1 8  // Control pin 1 for motor 1
#define I2 9  // Control pin 2 for motor 1
#define I3 12  // Control pin 1 for motor 2
#define I4 13  // Control pin 2 for motor 2

#define VOL 7
#define GND 6

#define L2 5
#define L1 4
#define MD 3
#define R2 1

/*
 * Here we setup the appropriate pins using predefined arduino functions.
 */


void setup() {

  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(VOL, OUTPUT);
  pinMode(GND, OUTPUT);

  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);

 /*
  * Originally the vehicle was running on 5 light dependent resistors, 
  * but one burnt out and couldn't be replaced just before the final run.
  */

  pinMode(L2, INPUT);
  pinMode(L1, INPUT);
  pinMode(MD, INPUT);
  //pinMode(R1, INPUT);
  pinMode(R2, INPUT);
}

void loop() {
  digitalWrite(VOL, HIGH);
  digitalWrite(GND, LOW);

/*
 * The logic is fairly straightforward, we define the base cases that the sensors can detect,
 * and we write the logic that we want the vehicle to follow. Since we had five sensors at the start,
 * there should be corresponding values read to the arduino.
 */

  //straight
  if ((digitalRead(L2) == HIGH) && (digitalRead(L1) == HIGH) && (digitalRead(MD) == LOW) && 
  //(digitalRead(R1) == HIGH) && 
  (digitalRead(R2) == HIGH)) {
    analogWrite(E1, 100);
    analogWrite(E2, 113);
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
  }

  /*
   * Navigate turns by writing different speeds to the left and right motors using Pulse Width Modulation (PWM)
   */

  //left gentle turn
  else if ((digitalRead(L2) == HIGH) && (digitalRead(L1) == LOW) && (digitalRead(MD) == LOW) && 
  //(digitalRead(R1) == HIGH) && 
  (digitalRead(R2) == HIGH)) {

    analogWrite(E1, 75);
    analogWrite(E2, 130);
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
  }

  //right gentle turn
  else if ((digitalRead(L2) == HIGH) && (digitalRead(L1) == HIGH) && (digitalRead(MD) == LOW) && 
  //(digitalRead(R1) == LOW) && 
  (digitalRead(R2) == LOW)) {

    analogWrite(E1, 117);
    analogWrite(E2, 75);
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
  }

  //left sharp turn
  else if ((digitalRead(L2) == LOW) && (digitalRead(L1) == LOW) && (digitalRead(MD) == LOW) && 
  //(digitalRead(R1) == HIGH) && 
  (digitalRead(R2) == HIGH)) {

    analogWrite(E1, 75);
    analogWrite(E2, 80);
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
    delay(64);

    analogWrite(E1, 100);
    analogWrite(E2, 113);
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
    delay(32);
  }

/*
 * Commented out codeblock left here to show what was the ideal case for the vehicle.
 */
  
/*
  //right sharp turn
  else if ((digitalRead(L2) == HIGH) && (digitalRead(L1) == HIGH) && (digitalRead(MD) == LOW) && 
  //(digitalRead(R1) == LOW) && 
  (digitalRead(R2) == LOW)) {

    analogWrite(E1, 75);
    analogWrite(E2, 80);
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
    delay(64);

    analogWrite(E1, 100);
    analogWrite(E2, 113);
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
    delay(32);
  }
*/
  //confused left
  else if ((digitalRead(L2) == HIGH) && (digitalRead(L1) == LOW) && (digitalRead(MD) == LOW) && 
  //(digitalRead(R1) == LOW) && 
  (digitalRead(R2) == LOW)) {

    analogWrite(E1, 100);
    analogWrite(E2, 113);
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
    delay(32);
  }

/*
  //confused right
  else if ((digitalRead(L2) == LOW) && (digitalRead(L1) == LOW) && (digitalRead(MD) == LOW) && 
  //(digitalRead(R1) == LOW) &&
  (digitalRead(R2) == HIGH)) {

    analogWrite(E1, 100);
    analogWrite(E2, 113);
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
    delay(32);
  }
*/
  //annoying left
  else if ((digitalRead(L2) == LOW) && (digitalRead(L1) == LOW) && (digitalRead(MD) == HIGH) && 
  //(digitalRead(R1) == HIGH) && 
  (digitalRead(R2) == HIGH)) {

    analogWrite(E1, 100);
    analogWrite(E2, 113);
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
    delay(32);
  }

  //annoying right
  else if ((digitalRead(L2) == HIGH) && (digitalRead(L1) == HIGH) && (digitalRead(MD) == HIGH) &&
  //(digitalRead(R1) == LOW) && 
  (digitalRead(R2) == LOW)) {

    analogWrite(E1, 100);
    analogWrite(E2, 113);
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
    delay(32);
  }


  //overshoot
  else if ((digitalRead(L2) == HIGH) && (digitalRead(L1) == HIGH) && (digitalRead(MD) == HIGH) && 
  //(digitalRead(R1) == HIGH) && 
  (digitalRead(R2) == HIGH)) {

    analogWrite(E1, 88);
    analogWrite(E2, 100);
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
    delay(50);
  }

  //HLLLH
  else if ((digitalRead(L2) == HIGH) && (digitalRead(L1) == LOW) && (digitalRead(MD) == LOW) && 
  //(digitalRead(R1) == LOW) && 
  (digitalRead(R2) == HIGH)) {
    analogWrite(E1, 100);
    analogWrite(E2, 113);
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
  }

  //hit wall
  
  else if ((digitalRead(L2) == LOW) && (digitalRead(L1) == LOW) && (digitalRead(MD) == LOW) && 
  //(digitalRead(R1) == LOW) && 
  (digitalRead(R2) == LOW)) {
    analogWrite(E1, 100);
    analogWrite(E2, 113);
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
  }
  
}
