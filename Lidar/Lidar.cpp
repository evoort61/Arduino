#include <Lidar.h>
#include <Arduino.h>

Lidar::Lidar()
{
}

void Lidar::Init(int IR_RECIVER, int IR_TRANSMITTER)
{
  Init(IR_RECIVER, IR_TRANSMITTER, 60, 180);
}

void Lidar::Init(int IR_RECIVER, int IR_TRANSMITTER, int DiffMin, int Diff30cm)
{
  pinMode(IR_RECIVER, INPUT_PULLUP);
  pinMode(IR_TRANSMITTER, OUTPUT);
  this->IR_RECIVER = IR_RECIVER;
  this->IR_TRANSMITTER = IR_TRANSMITTER;
  this->DiffMin = DiffMin;
  this->A = 30  * sqrt(Diff30cm - DiffMin);
}

//Returns distance (cm)
float Lidar::GetDistance()
{
  V0 = 0;
  V1 = 0;
  const char count = 1;
   
  for(int i=0;i<count;i++)
  {
    digitalWrite(IR_TRANSMITTER, LOW);
    delayMicroseconds(1500);
    V0 += analogRead(IR_RECIVER);
      
    digitalWrite(IR_TRANSMITTER, HIGH);
    delayMicroseconds(500);
    V1 += 2 * analogRead(IR_RECIVER);
      
    digitalWrite(IR_TRANSMITTER, LOW);
    delayMicroseconds(500);
    V0 += analogRead(IR_RECIVER);      
  }
  
  V0 /= count * 2;
  V1 /= count * 2;
  
  float diff = (V0 - V1) - DiffMin;
  if(diff < 0.01)
    diff = 0.01;

  return A / sqrt(diff);
}