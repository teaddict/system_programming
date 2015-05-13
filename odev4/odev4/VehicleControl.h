/*
 * =====================================================================================
 *
 *       Filename:  VehicleControl.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/27/2015 06:05:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef VEHICLECONTROL_H
#define VEHICLECONTROL_H
typedef enum {
	OPEN =0,
	CLOSED=1
}State;

typedef struct {
	char name[100];
	int speed;
	struct {
		int motor;
		int indoor;
		int outdoor;
	} Temp;
	struct {
		State frontLeft;
		State frontRight;
		State rearLeft;
		State rearRight;
	} Door;
	struct {
		int frontLeft;
		int frontRight;
		int rearLeft;
		int rearRight;
	} WheelPressure;
}Vehicle;
void setVehicleName(Vehicle *, char *);
void setVehicleSpeed(Vehicle *, int);
void setVehicleTemp(Vehicle *, float motor,float indoor,float outdoor);
void setVehicleDoor(Vehicle *, State fL, State fR, State rL, State rR);
void setVehicleWheelPressure(Vehicle *,int fL, int fR, int rL, int rR);
#endif
