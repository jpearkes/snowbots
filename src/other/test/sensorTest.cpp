#include <tbrclient/tbrclient.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace tbrprobe07;

const int PORT = 1225;
const char *HOST = "127.0.0.1";

tbrclient client;

int main()
{
	while(true)
	{	
	if (client.initialize(PORT, HOST)== false)
	{
		std::cout << "Connection Failed!" << std::endl;
	}
	else
	{	

std::cout << "Distance = " << client.getInfraredN() << std::endl;			
//		usleep(2000000);

std::cout << "NE: Distance= " << client.getInfraredNE() << std::endl;
//std::cout << "Distance to Right= " << distanceToRight << std::endl;
//		usleep(2000000);

std::cout << "NW: Distance= " << client.getInfraredNW() << std::endl;
//std::cout << "Distance to Left= " << distanceToLeft << std::endl;
		usleep(2000000);
	}
	}
	return 0;
}
