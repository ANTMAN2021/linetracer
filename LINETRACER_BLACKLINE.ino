

#define m1 5 //Right Motor MA1
#define m2 4 //Right Motor MA2
#define m3 2  //Left Motor MB1
#define m4 3  //Left Motor MB2
#define e1 7  //Right Motor Enable Pin EA
#define e2 6 //Left Motor Enable Pin EB

//**********5 Channel IR Sensor Connection**********//
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A5
//*************************************************//

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
}

void loop() {
  //Reading Sensor Values
  int s1 = digitalRead(ir1);  //Left Most Sensor
  
  int s2 = digitalRead(ir2);  //Left Sensor
  
  int s3 = digitalRead(ir3);  //Middle Sensor
  
  int s4 = digitalRead(ir4);  //Right Sensor
 
  int s5 = digitalRead(ir5);  //Right Most Sensor
 
  //if only middle sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 0) && (s5 == 0))
  {
    moveforward();

  }
  if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0))
  {
    moveforward();

  }
  if((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 0))
  {
    moveforward();

  }
  //if only left sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 0))
  {
    moveright();
  }
  
  //if only left most sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 1))
  {
    moveextremeright();

  }

  //if only right sensor detects black line
  if((s1 == 0) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
moveleft();
  }

  //if only right most sensor detects black line
  if((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
moveextremeleft();
  }

  //if middle and right sensor detects black line
  if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0))
  {
moveleft();
  }

  //if middle and left sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 0))
  {
moveright();
  }

  //if middle, left and left most sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1))
{
  moveextremeright();
  }

  //if middle, right and right most sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0))
  {
moveextremeleft();
  }
  
    if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
moveextremeleft();
  }

 /* //if all sensors are on a white line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    analogWrite(e1, 80); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 80); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);

    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);

  }*/
}
void moveforward()
{
    //going forward with full speed 
    analogWrite(e1, 80); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 80); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);

    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);

    digitalWrite(m4, LOW);
   }

void moveright()
{
      //going right with full speed 
    analogWrite(e1, 80); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 80); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);

    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
}

void moveextremeright()
{
    //going extreme right with full speed 
    analogWrite(e1, 80); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 80); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);

    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
   
}

void moveleft()
{
      //going left with full speed 
    analogWrite(e1, 80); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 80); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);

    digitalWrite(m4, LOW);
}

void moveextremeleft()
{
      //going exteme left with full speed //not working
    analogWrite(e1, 80); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 80); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);

    digitalWrite(m3, HIGH);

    digitalWrite(m4, LOW);
}
