// Swarm_Robot_Using_ultrasonic_sensor
#define echopin  8 // echo pin
#define trigpin 7 // Trigger pin
int maximumRange = 30;
long duration, distance;

const int LM1 = 5;             // left motor terminal 1 , motor pin numbers can be changed in the program if both motors rotate in different directions
const int LM2 = 3;             // left motor terminal 2

const int RM1 =9;             // right motor terminal 1
const int RM2 = 6;              // right motor terminal 2


void setup() 
{
  Serial.begin(9600);
  pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT );
  pinMode(LM1,OUTPUT);                     // all four motor pins are assigned as OUTPUT
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);

  
}

void loop()
{

  {
    digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    duration=pulseIn (echopin,HIGH);
    distance = (duration/2) / 29.1;//29.1 is the pace of the sound instead of using the Speed of Sound, we can also use the "Pace of Sound".
                                   //The Pace of Sound = (1 / Speed of Sound) = 1 / 0.03435 = 29.1 ss/cm
    delay (100);
    Serial.println(distance);
  }
  
  if (distance > 15){
    Serial.println("no obstacle !! moving forward ");
    analogWrite(LM1,180);//forward
    analogWrite(LM2,0);
    analogWrite(RM1,180);
    analogWrite(RM2,0);
    Serial.write("f");
    delay (650);
  }
  
  else if (distance >=8 && distance <= 12) {
    Serial.println("Obstacle detected !! moving left!! ");
    analogWrite(LM1,0);
    analogWrite(LM2,90);
    analogWrite(RM1,90);
    analogWrite(RM2,0);
    Serial.write("l");
    delay (160);
  }
 else if (distance < 8)
 {
  Serial.println(" Danger Close !!! Falling Back !!");
   analogWrite (LM1,0);//back
   analogWrite (LM2,110);
   analogWrite (RM1,0);
   analogWrite (RM2,110);
   Serial.write("b");
   delay (200);
   Serial.println("Obstacle avoided !!! moving right!!");
   analogWrite(LM1,0);
   analogWrite(LM2,110);
   analogWrite(RM1,110);
   analogWrite(RM2,0);
   delay (160);
   Serial.write("r");
 } }
