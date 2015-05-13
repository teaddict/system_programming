/*
 * =====================================================================================
 *
 *       Filename:  VehicleParser.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/27/2015 06:42:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  teaddict (), cyberasker@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef VEHICLEPARSER_H
#define VEHICLEPARSER_H
#include "VehicleControl.h"
#include<string.h>

#define bool int
#define true 1
#define false 0

bool parseTemp(char *str, float *motor, float *indoor, float *outdoor);
bool parseName(char *str, char *motor);
bool parseSpeed(char *str, int *speed);
bool parseDoor(char *str, State *fL, State *fR, State *rL, State *rR);
bool parseWheelPress(char *str, int *fL, int *fR, int *rL, int *rR);

#endif
