//MOTOR DRIVER(L298n) # 1
//Pin Initializing
int ena1 = 4; // for MEGA 4 & 13
int enb1 = 13;
int in11 = 2;
int in12 = 3;
int in13 = 5;
int in14 = 6;
//----------------------//
int x = 0;
int y = 0;
int z = 0;

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8);
const byte rxAddr[6] = "00001";

int acc[3];

void setup(){
  Serial.begin(9600);

//------------------------//
  pinMode(ena1, OUTPUT);
  pinMode(enb1, OUTPUT);
  pinMode(in11, OUTPUT);
  pinMode(in12, OUTPUT);
  pinMode(in13, OUTPUT);
  pinMode(in14, OUTPUT);
 //------------------------//
 
  while (!Serial);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, rxAddr);
  radio.startListening();
}

void loop(){
  
  if (radio.available())
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    Serial.println(text);

    radio.read(&acc, sizeof(acc));
    Serial.println(acc[0]);
    Serial.println(acc[1]);
    Serial.println(acc[2]);
    x = acc[0];
    y = acc[1];
    z = acc[2];
  
  
    if (x >= 18 && x <=78 && y >= 0 && y <= 20 ) 
  {
    // Motor Forward
    analogWrite(ena1, 190);
    analogWrite(enb1, 190);


    digitalWrite(in11, LOW);
    digitalWrite(in12, HIGH);
    digitalWrite(in13, HIGH);
    digitalWrite(in14, LOW);
    Serial.println("Motor Forward"); // Prints out “Motor 1 Forward” on the serial monitor
    Serial.println("   "); 
  }

 
  else if(x >= 9 && x <=60 && y >= 300 && y <= 350)
  {
     analogWrite(ena1, 190);
analogWrite(enb1, 190);

  digitalWrite(in11, HIGH);
  digitalWrite(in12, LOW);
  digitalWrite(in13, HIGH);
  digitalWrite(in14, LOW);
    Serial.println("Motor Left");
    Serial.println("   ");
  }

  
  else if(x >= 0 && x <=40 && y >= 5 && y <= 60 )
  {
    analogWrite(ena1, 190);
analogWrite(enb1, 190);

  digitalWrite(in11, LOW);
  digitalWrite(in12, HIGH);
  digitalWrite(in13, LOW);
  digitalWrite(in14, HIGH);

    Serial.println("Motor Right");
    Serial.println("   ");
  }
  else if(x >= 315 && x <=350 && y >= 0 && y <= 220)
  {
    
    analogWrite(ena1, 190);
    analogWrite(enb1, 190);


  digitalWrite(in11, HIGH);
  digitalWrite(in12, LOW);
  digitalWrite(in13, LOW);
  digitalWrite(in14, HIGH);

    Serial.println("Motor Reverse");
    Serial.println("   ");
  }
  else
  {
    analogWrite(ena1, 0);
    analogWrite(enb1, 0);

  digitalWrite(in11, LOW);
  digitalWrite(in12, LOW);
  digitalWrite(in13, LOW);
  digitalWrite(in14, LOW);
    Serial.println("Motor Stop");
    Serial.println("   ");
  }
delay(1000);
  }
}

