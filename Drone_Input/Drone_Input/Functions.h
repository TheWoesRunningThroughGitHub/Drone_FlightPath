#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_



void ReadHomeLocation(long double& Start_Latitude, long double& Start_Longitud);
void Auto_Grid_Waypoint_Generator(double StartLatitud, double Start_Longitud);
double Coords2Meters(double lat1, double lon1, double lat2, double lon2);
void CreateWaypointFile(int size, long double waypoints[]);
//double Meters2Coords(double dist);

#endif