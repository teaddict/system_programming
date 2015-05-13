/*
 * =====================================================================================
 *
 *       Filename:  AppSever.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include"VehicleControl.h"
#include"VehicleParser.h"
#include"VehicleServer.h"
#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<arpa/inet.h>
#include <stdbool.h>

int main()
{
	
	//ONCE VEHICLE DEGER ATA
	Vehicle vehicle;
	State state[4];
	
	state[0]=0;
	state[1]=1;
	state[2]=0;
	state[3]=1;
	
	char *name="audi";
	
	setVehicleName(&vehicle,name);
	setVehicleTemp(&vehicle, 1.0,2.0,3.5);
	setVehicleSpeed(&vehicle, 45);
	setVehicleDoor(&vehicle, state[0], state[1], state[2], state[3]);
	setVehicleWheelPressure(&vehicle, 25,30,30,25);
	
	printf("----------------------------------------------------\n");
	printf("Applied Vehicle Properties:\n");
	printf("----------------------------------------------------\n");
	printf("Name: %s\n",vehicle.name);
	printf("Speed: %d\n",vehicle.speed);
	printf("Temperature: (motor) %d , (indoor) %d , (outdoor) %d\n",vehicle.Temp.motor,vehicle.Temp.indoor,vehicle.Temp.outdoor);
	printf("Door: (frontLeft) %d ,(frontRight) %d,(rearLeft) %d,(rearRight) %d\n",vehicle.Door.frontLeft, vehicle.Door.frontRight,vehicle.Door.rearLeft, vehicle.Door.rearRight);
	printf("Wheel Pressure : (frontLeft) %d ,(frontRight) %d ,(rearLeft) %d, (rearRight) %d\n",vehicle.WheelPressure.frontLeft,vehicle.WheelPressure.frontRight,vehicle.WheelPressure.rearLeft,vehicle.WheelPressure.rearRight);
	printf("----------------------------------------------------\n");
	
	printf("open the server\n\n");
	
	int server, port,client;
	port=7777;
	if(initializeConnection(&server,port))
	{
		while(1)
		{
			client=makeConnection(&server);
			
			if(answerMessage(client,&vehicle));
		}
	}

return 0;
}	
