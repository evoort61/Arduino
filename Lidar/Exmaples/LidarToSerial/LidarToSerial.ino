#include <Lidar.h>

#define IR_RECIVER A1
#define IR_TRANSMITTER A0

//Minimal V0-V1, when lidar looks at "infinite" distantion
#define DiffMin 38
//Value of V0-V1, when lidar looks at white paper A4 from 30 cm
#define Diff30cm 180

Lidar lidar;
char report[80];

void setup()
{
  Serial.begin(9600);
  lidar.Init(IR_RECIVER, IR_TRANSMITTER, DiffMin, Diff30cm);
}

void loop()
{
  int t1 = millis();
  float dist = lidar.GetDistance(); 
  int t2 = millis();
  
  snprintf(report, sizeof(report), "Time:  %6d ms  V0: %6d  V1: %6d  Diff: %6d  Dist: %6d cm", (int)(t2 - t1), (int)lidar.V0, (int)lidar.V1, (int)(lidar.V0 - lidar.V1), (int)dist);
  Serial.println(report);
}
