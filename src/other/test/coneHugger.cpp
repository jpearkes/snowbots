#include <tbrclient/tbrclient.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace tbrprobe07;

const int PORT = 1225;
const char *HOST = "127.0.0.1";

tbrclient client;

bool coneHugger()
{
//	double courseWidth = 2.00;
	double PI = 3.14159265;	
	double minDistance = 0.8;
	double angleIrNE = PI/6;
	double angleIrNW = PI/6;

	if(client.getInfraredN() > 1.0)
	{
std::cout << "Distance = " << client.getInfraredN() << std::endl;		
		client.setSteering(0);
		return false;
	}
	else
	{
std::cout << "Distance = " << client.getInfraredN() << std::endl;		

		double distanceToRight = client.getInfraredNE() * cos(angleIrNE);
		double distanceToLeft = client.getInfraredNW() * cos(angleIrNW);

		if (distanceToRight < minDistance)
		{
std::cout << "NE: Distance= " << client.getInfraredNE() << std::endl;
std::cout << "Distance to Right= " << distanceToRight << std::endl;
std::cout << "ESteering= " << (minDistance-distanceToRight)/minDistance*(-100) << std::cout;

			client.setSteering((minDistance-distanceToRight)/minDistance*(-100));
			return true;
		}
		if (distanceToLeft < minDistance)
		{
std::cout << "NW: Distance= " << client.getInfraredNW() << std::endl;
std::cout << "Distance to Left= " << distanceToLeft << std::endl;
std::cout << "WSteering= " << (minDistance-distanceToRight)/minDistance*(100) << std::cout;
			
			client.setSteering((minDistance-distanceToLeft)/minDistance*(100));
			return true;
		}
	}
	return true;
}

int main()
{	
	if (client.initialize(PORT, HOST)== false)
	{
		std::cout << "Connection Failed!" << std::endl;
	}
	else
	{		
	//	double initPos = client.getOdometerDistance();
		client.setThrottle(70);
	
		while (true)//client.getOdometerDistance() < initPos + 20.00)
		{
			coneHugger();
			usleep(500000);
		}
	
		client.setThrottle(10);
	}
	return 0;
}

