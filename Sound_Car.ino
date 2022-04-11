//declare all necessary global variables
int sensorValue=A1;//variable that stores output received from sound sensor
int threshold =400;
//declare the pins to control vehicle wheels
int rearRightForward =22;
int rearRightReverse=23;
int rearLeftReverse=24;
int rearLeftForward=25;
int frontLeftForward=26;
int frontLeftReverse=27;
int frontRightForward=28;
int frontRightReverse=29;
//declare variables to be used for controlling the speed of vehicle's wheels
int speed1=2;
int speed2=3;
int speed3=4;
int speed4=5;
int speEd=100;
float sensorval;
float value0;
//declare boolean values that trigger depending on how many claps detected
boolean oneClap=false;
boolean twoClaps=false;
boolean threeClaps=false;
boolean fourClaps=false;
boolean goingForward=false;
void setup() {
//setup all necessary pins for vehicle wheel control and speed control
pinMode(rearRightForward,OUTPUT);
pinMode(rearRightReverse,OUTPUT);
pinMode(rearLeftReverse,OUTPUT);
pinMode(rearLeftForward,OUTPUT);
pinMode(frontRightForward,OUTPUT);
pinMode(frontRightReverse,OUTPUT);
pinMode(frontLeftForward,OUTPUT);
pinMode(frontLeftReverse,OUTPUT);
pinMode(sensorValue,INPUT);
pinMode(speed1,OUTPUT);
pinMode(speed2,OUTPUT);
pinMode(speed3,OUTPUT);
pinMode(speed4,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  sensorval=analogRead(sensorValue);//reads the analog output received from sound sensor
  
  //if statement that triggers if the sound exceeds a prescribed value of threshold+-17
if(sensorval<threshold-17||sensorval>threshold+17                                                                                                                                                                                                                                                                            ){
  oneClap=true;//triggers first clap
  delay(500);
  for(int i=0; i<1000;i++){
    sensorval=analogRead(sensorValue);
    delay(1);
    if(sensorval<threshold-17||sensorval>threshold+17 ){
      twoClaps=true;//if a sound value meeting threshold is detected again within 1s triggers second clap
      break;
      
    }
    }
  }
  if(twoClaps==true){
    delay(500);
  for(int i=0; i<1000;i++){
    delay(1);
    sensorval=analogRead(sensorValue);
    if(sensorval<threshold-17||sensorval>threshold+17){
      threeClaps=true;
      break;
      
    }
    
    }
  }
 if(threeClaps==true){
    delay(500);
  for(int i=0; i<1000;i++){
    delay(1);
    sensorval=analogRead(sensorValue);
    if(sensorval<threshold-17||sensorval>threshold+17){
      fourClaps=true;
      break;
    } 
    }
  }
  //trigers action for three claps
 if(threeClaps==true&&fourClaps==false){
  turnLeft();
  delay(2000);
  forward();
 }
 //trigers action for one clap
 if(oneClap==true&&twoClaps==false&&fourClaps==false){
  if(goingForward==false){
   forward();
   goingForward=true;
  }
   else{
  reverse();
  goingForward=false;
   }
  
 }
 //trigers action for two claps
 if(twoClaps==true&&threeClaps==false&&fourClaps==false){
   turnRight();
   delay(2000);
   forward();  
 }
 //trigers action for four claps
 if(fourClaps==true){
  //turnRight();
   halt();
  delay(2000);
 }
 
 //resets all claps after execution of above code
 oneClap=false;
 twoClaps=false;
 threeClaps=false; 
 fourClaps=false;
  
}
/**
 * Method to trigger the vehicle to move forward.
 * Achieved by toggling high the required pins pn the
 * motor driver
 */
void forward(){
  speedVal(speEd);
   digitalWrite(rearRightForward,HIGH);
  digitalWrite(rearRightReverse,LOW);
  digitalWrite(rearLeftForward,HIGH);
  digitalWrite(rearLeftReverse,LOW);
  digitalWrite(frontLeftReverse,LOW);
  digitalWrite(frontLeftForward,HIGH);
 digitalWrite(frontRightForward,HIGH);
 digitalWrite(frontRightReverse,LOW);
}
/**
 * Method to trigger the vehicle to move forward.
 * Achieved by toggling high the required pins pn the
 * motor driver
 */
void reverse(){
  speedVal(speEd);
  digitalWrite(rearRightForward,LOW);
  digitalWrite(rearRightReverse,HIGH);
  digitalWrite(rearLeftForward,LOW);
  digitalWrite(rearLeftReverse,HIGH);
  digitalWrite(frontLeftReverse,HIGH);
  digitalWrite(frontLeftForward,LOW);
 digitalWrite(frontRightForward,LOW);
 digitalWrite(frontRightReverse,HIGH);
}
/**
 * Method to trigger the vehicle to move forward.
 * Achieved by toggling high the required pins pn the
 * motor driver
 */
void turnRight(){
  speedVal(speEd);
 digitalWrite(rearRightForward,LOW);
 digitalWrite(rearRightReverse,LOW);
 digitalWrite(rearLeftForward,HIGH);
 digitalWrite(rearLeftReverse,LOW);
 digitalWrite(frontLeftReverse,LOW);
 digitalWrite(frontLeftForward,HIGH);
 digitalWrite(frontRightForward,LOW);
 digitalWrite(frontRightReverse,LOW);
}
/**
 * Method to trigger the vehicle to move forward.
 * Achieved by toggling high the required pins pn the
 * motor driver
 */
void turnLeft(){
  speedVal(speEd);
 digitalWrite(rearRightForward,HIGH);
 digitalWrite(rearRightReverse,LOW);
 digitalWrite(rearLeftForward,LOW);
 digitalWrite(rearLeftReverse,LOW);
 digitalWrite(frontLeftReverse,LOW);
 digitalWrite(frontLeftForward,LOW);
 digitalWrite(frontRightForward,HIGH);
 digitalWrite(frontRightReverse,LOW);
}
/**
 * Method to trigger the vehicle to move forward.
 * Achieved by toggling high the required pins pn the
 * motor driver
 */
void halt(){
 digitalWrite(rearRightForward,LOW);
 digitalWrite(rearRightReverse,LOW);
 digitalWrite(rearLeftForward,LOW);
 digitalWrite(rearLeftReverse,LOW);
 digitalWrite(frontLeftReverse,LOW);
 digitalWrite(frontLeftForward,LOW);
 digitalWrite(frontRightForward,LOW);
 digitalWrite(frontRightReverse,LOW);
}
/**
 * Method to control the speed of each of the wheels
 * of the vehicle by sending a PWM signal to the 
 * 'ENABLE' pins of the motor driver.
 */
void speedVal(int value){
  analogWrite(speed1,value);
  analogWrite(speed2,value);
  analogWrite(speed3,value);
  analogWrite(speed4,value);
  
}
