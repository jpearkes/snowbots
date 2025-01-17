#include <tbrclient/tbrclient.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace tbrprobe07;

const int PORT = 1225;
const char *HOST = "127.0.0.1";

tbrclient client;

int coneHugger()
{
	double PI = 3.14159265;	
	double minDistance = 0.8;
	double angleIrNE = PI/6;
	double angleIrNW = PI/6;
	double steeringVal = 0;

	if(client.getInfraredN() > minDistance)
	{		
		client.setSteering(0);
	}
	else
	{
		double distanceToRight = client.getInfraredNE() * cos(angleIrNE);
		double distanceToLeft = client.getInfraredNW() * cos(angleIrNW);

		if (distanceToRight < minDistance)
		{
			steeringVal = (minDistance-distanceToRight)/minDistance*(-100);	
			client.setSteering(steeringVal);
			return steeringVal;
		}
		if (distanceToLeft < minDistance)
		{			
			steeringVal = (minDistance-distanceToLeft)/minDistance*(100);		
			client.setSteering(steeringVal);
			return steeringVal;
		}
	}
	return steeringVal; //returns 0
}

int main()
{	
	if (client.initialize(PORT, HOST)== false)
	{
		std::cout << "Connection Failed!" << std::endl;
	}
	else
	{		
		client.setThrottle(70);
	
		while (true)
		{
			coneHugger();
			usleep(500000);
		}
	
		client.setThrottle(10);
	}
	return 0;
}

