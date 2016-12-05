#include <Time.h>

//#include <Time.h>  
//#include <Servo.h>
//Servo servoMain;


int int3 = 13;
int int4 = 12;
int int2= 6;
int int1= 5;

int trigpin_left= 3;
int echopin_left= 4;

int trigpin_front= 10;
int echopin_front= 9;

int trigpin_right= 7;
int echopin_right= 8;

int safedistance = 30;
long duration;
long centm;
int left1;
int front;
int right1;

char mapping[6][6] = {{'1','1','1','1','1','1'},
                      {'1','1','1','1','1','1'},
                      {'1','1','1','1','1','1'},
                      {'1','1','1','1','1','1'},
                      {'1','1','1','1','1','1'},
                      {'1','1','1','1','1','1'}};


void setup() {
  Serial.begin(9600);
  
  pinMode(int3, OUTPUT);
  pinMode(int4, OUTPUT);
  pinMode(int2, OUTPUT);
  pinMode(int1, OUTPUT);
  
  pinMode(trigpin_left, OUTPUT);
  pinMode(echopin_left, INPUT);

  pinMode(trigpin_front, OUTPUT);
  pinMode(echopin_front, INPUT);
  
  pinMode(trigpin_right, OUTPUT);
  pinMode(echopin_right, INPUT);

}

long watch_left()
{
  //trigger
  digitalWrite(trigpin_left, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin_left, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin_left, LOW);

  //duration
  duration = pulseIn(echopin_left, HIGH);
  centm = duration/29/2;

 // Serial.print(centm);
  //Serial.print("cm");
  //Serial.println();

  return centm;
}

long watch_front()
{
  //trigger
  digitalWrite(trigpin_front, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin_front, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin_front, LOW);

  //duration
  duration = pulseIn(echopin_front, HIGH);
  centm = duration/29/2;
  //Serial.print(centm);
  //Serial.print(" cm\n");
  return centm;
}

long watch_right()
{
  //trigger
  digitalWrite(trigpin_right, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin_right, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin_right, LOW);

  //duration
  duration = pulseIn(echopin_right, HIGH);
  centm = duration/29/2;
  if(centm>180)
  {
    centm=180;
  }
  return centm;
}

int actual=15;     //pid vairables
int pre_error=0;
int kp=0;
int ki=0;
int kd=0;
unsigned long start=0;
unsigned long endd=0;
unsigned long final=0;
int error=0;
int data;
long integral;
long derivative;
long output;       //

long start1;

int i=0;
int j=0;
int x=0;
int b=0;
int y=0;
int dis_right;

void loop()
{
   // final=endd-start;
 data=Serial.read();
 data=data-'0';
 //start1=second();
 //Serial.print(start1);
 //Serial.print("\n");
 if(data==1)
 {
 while(1)
 {
 
 start= millis();                                    //pid startup
 start1=second();
 left1 = watch_left();
 error=left1-actual;
 integral=integral+error*(millis()-start);
 derivative=(error-pre_error)/(millis()-start);
 output=(kp*error)+(ki*integral)+(kd*derivative);
 pre_error=error;                                      //pid end

 if(error<0)
{
  right();
  delay(output);
}
else if(error>0)
{
  left();
  delay(output);  
}
else if(error==0)
{
  front= watch_front();
  forward();
  if(start1%4==0)
  {
    rstop();
       delay(1000);
Serial.print(x);
    if(x>5)
    {
      i=5;
      //j=0;
      mapping[i][j]='*';
      right1=watch_right();
      if(right1==180)
      {
        for(int a=0; a<6; a++)
        {
          if(mapping[a][j]=='0')
          {
            mapping[a][j]='1';
          }
        
        }
      }
      j++;
      y++;
      Serial.print("\n");
      for(int n=0;n<6;n++)
      {
         for(int m=0;m<6;m++)
         {  
           Serial.print("|");
           Serial.print(mapping[n][m]);
           Serial.print("|");
           //delay(1000);
         }
      Serial.print("\n");
      }
      mapping[i][j-1]='1';
      if(y==6)
      {
        break;
      }
    }
   
   else if(x<6)
   { 
    mapping[i][j]='*';
    right1=watch_right();
    if(right1<180)
    {
      dis_right=right1/30;
      for(int a=dis_right;a<6;a++)
      {
        mapping[x][a]='0';
      }
    }
    i++;
    x++;
    Serial.print("\n");
    for(int n=0;n<6;n++)
    {
     for(int m=0;m<6;m++)
     {  
       Serial.print("|");
       Serial.print(mapping[n][m]);
       Serial.print("|");
       //delay(1000);
     }
     Serial.print("\n");
    }
 
 
   
    //mapping[
    //if(right1<=180)
    //{
     // right1/30;
      
    //}
    mapping[i-1][j]='1';
   }
  }
//  if(front<=5)
//  {
//    right();
//    delay(500);
//    rstop();
//    delay(500);
//    x=6;
//  }
}
 

 delay(millis()-start);
 }
 }
}
  //forward
void forward()
{
  digitalWrite(int1,LOW);
  digitalWrite(int2,HIGH);
  digitalWrite(int3,LOW );
  digitalWrite(int4, HIGH);
}
void rstop()
{
    digitalWrite(int1,LOW);
    digitalWrite(int2,LOW);
    digitalWrite(int3,LOW);
    digitalWrite(int4,LOW);
}
void right()
{
  digitalWrite(int1,LOW);
  digitalWrite(int2,HIGH);
  digitalWrite(int3,HIGH );
  digitalWrite(int4, LOW);
}
void left()
{
  digitalWrite(int1,HIGH);
  digitalWrite(int2,LOW);
  digitalWrite(int3,LOW );
  digitalWrite(int4, HIGH);
}

