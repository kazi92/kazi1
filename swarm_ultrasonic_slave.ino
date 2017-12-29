// Swarm_Robot_Using_ultrasonic_Slave.ino

const int LM1 = 3;             // left motor terminal 1 , motor pin numbers can be changed in the program if both motors rotate in different directions
const int LM2 = 5;             // left motor terminal 2

const int RM1 =9;             // right motor terminal 1
const int RM2 =6;              // right motor terminal 2

long previousMillis = 0;
long interval = 1000; 

unsigned long currentMillis = 0;

void setup() 
{
  Serial.begin(9600);

  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);

  pinMode(RM1, OUTPUT);
  pinMode(RM_2, OUTPUT);
}

void loop() 
{
  char temp;
  currentMillis = millis();
  
  if(Serial.available())
  {
    previousMillis = currentMillis;
    temp=Serial.read();
    if(temp == 'f')
      forward();
    if(temp == 'l')
      left();
    if(temp == 'b')
      back();
    if(temp == 'r')
      right();
  }
  monitorConnection();  
  
}
void monitorConnection() {
 if(((currentMillis - previousMillis) < interval) || ( previousMillis == 0))
  {
      
  } 
  
  else
  {
    stop1();
  }
  
}
void forward()        // Forward function defined
{
  analogWrite(LM1,180);          // both the terminals are made to move forward
  analogWrite(LM2,0);
  analogWrite(RM1,180);
  analogWrite(RM2,HIGH);
  return; 
}

void backward()
{
  analogWrite(LM1,0);            // Instructions to move backward
  analogWrite(LM2,110);
  analogWrite(RM1,0);
  analogWrite(RM2,110);
  return;
}

void left()           // Left function defined
{
  analogWrite(LM1,0);
  analogWrite(LM2,90);
  analogWrite(RM1,90);
  analogWrite(RM2,0);// robot turns left
  return; 
}

void right()          // Right function defined
{
  analogWrite(LM_1,HIGH);
  analogWrite(LM_1,HIGH);
  analogWrite(LM_1,HIGH);
  analogWrite(RM2,HIGH);                                        
  return;
}

void stop1()          // Stop function defined
{
  digitalWrite(LM_1,LOW);            // Stops the Robot
  digitalWrite(LM_2,LOW);
  digitalWrite(RM_1,LOW);                                          
  digitalWrite(RM_2,LOW);                                         
  return;
}

void back_left()      // Back Left function defined 
{
  digitalWrite(LM_1,LOW);             // Instructions to move backward
  digitalWrite(LM_2,HIGH);
  digitalWrite(RM_1,LOW);
  digitalWrite(RM_2,HIGH);
  delay(900);                                                      
  digitalWrite(LM_1,LOW);                                          
  digitalWrite(LM_2,HIGH);
  digitalWrite(RM_1,HIGH);                                         
  digitalWrite(RM_2,LOW);             // Robot turns Left
  delay(600);
  return;
}

void back_right()     // Back Right function defined
{

  digitalWrite(LM_1,LOW);             // Instructions to move backward
  digitalWrite(LM_2,HIGH);
  digitalWrite(RM_1,LOW);
  digitalWrite(RM_2,HIGH);
  delay(900);                                             
  digitalWrite(LM_1,HIGH);                                 
  digitalWrite(LM_2,LOW);
  digitalWrite(RM_1,LOW);                                
  digitalWrite(RM_2,HIGH);            // Robot turns right
  delay(600);
  return;
}

