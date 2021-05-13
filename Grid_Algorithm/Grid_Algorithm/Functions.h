

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <iostream>
#include <cmath>
#include "Class_Waypoint.h"
#include "Class_Coord_Point.h"

using namespace std;

void ReadHomeLocation(long double& Start_Latitude, long double& Start_Longitud);
void Auto_Grid_Waypoint_Generator(long double StartLatitud, long double Start_Longitud, long double Start_Altitud, int& Grid_Waypoints, Waypoint& Main_Grid);
double Coords2Meters(double lat1, double lon1, double lat2, double lon2);
void CreateWaypointFile(int size, long double waypoints[]);

double Meters2CoordsY(double Y);
double Meters2CoordsX(double X);

//double Meters2Coords(double dist);



#endif