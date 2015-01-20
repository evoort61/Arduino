#ifndef Lidar_h
#define Lidar_h

#include <Arduino.h>

class Lidar
{
  private:
	int IR_RECIVER;
	int IR_TRANSMITTER;
	int DiffMin;
	float A;
  public:
	Lidar();
	void Init(int, int); //Pins: IR_RECIVER, IR_TRANSMITTER
    void Init(int, int, int, int); //Pins: IR_RECIVER, IR_TRANSMITTER, DiffMin, Diff30cm
	float GetDistance();//cm
	int V0;//illumination level when transmitter OFF
	int V1;//illumination level when transmitter ON
};

#endif
