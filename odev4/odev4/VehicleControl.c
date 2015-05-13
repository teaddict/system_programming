/*
 * =====================================================================================
 *
 *       Filename:  VehicleControl.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/27/2015 06:27:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include"VehicleControl.h"
void setVehicleName(Vehicle *vehicle, char *name)
{
	strncpy(vehicle->name,name,100);
}

void setVehicleSpeed(Vehicle *vehicle, int speed)
{
	vehicle->speed=speed;
}

void setVehicleTemp(Vehicle *vehicle, float motor,float indoor,float outdoor)
{
	vehicle->Temp.motor=motor;
	vehicle->Temp.indoor=indoor;
	vehicle->Temp.outdoor=outdoor;
}

void setVehicleDoor(Vehicle *vehicle, State fL, State fR, State rL, State rR)
{
	
	vehicle->Door.frontLeft=fL;
	vehicle->Door.frontRight=fR;
	vehicle->Door.rearLeft=rL;
	vehicle->Door.rearRight=rR;
}

void setVehicleWheelPressure(Vehicle *vehicle,int fL, int fR, int rL, int rR)
{
	vehicle->WheelPressure.frontLeft=fL;
	vehicle->WheelPressure.frontRight=fR;
	vehicle->WheelPressure.rearLeft=rL;
	vehicle->WheelPressure.rearRight=rR;
}


