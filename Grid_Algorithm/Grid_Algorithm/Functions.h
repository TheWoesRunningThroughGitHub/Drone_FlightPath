

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <iostream>
#include <cmath>
#include "Classes.h"

using namespace std;

void ReadHomeLocation(long double& Start_Latitude, long double& Start_Longitud);
Waypoint Auto_Grid_Waypoint_Generator(long double StartLatitud, long double Start_Longitud, long double Start_Altitud, int& Grid_Waypoints);
double Coords2Meters(double lat1, double lon1, double lat2, double lon2);
void CreateWaypointFile(int size, long double waypoints[]);

double Meters2CoordsY(double Y);
double Meters2CoordsX(double X);

//double Meters2Coords(double dist);



#endif