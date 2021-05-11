

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <iostream>
#include <cmath>

using namespace std;

void ReadHomeLocation(long double& Start_Latitude, long double& Start_Longitud);
int Auto_Grid_Waypoint_Generator(double StartLatitud, double Start_Longitud);
double Coords2Meters(double lat1, double lon1, double lat2, double lon2);

double Meters2CoordsY(double Y);
double Meters2CoordsX(double X);

//double Meters2Coords(double dist);


//================================
// Classes
//================================

class Coord_Point
{
public:
	//basic 3 variables
	long double * longitud;
	long double * latitud;
	long double * altitud;

	Coord_Point(); //default constructor
	Coord_Point(long double New_latitud, long double New_longitud); //2 param constructor
	Coord_Point(long double New_latitud, long double New_longitud, long double New_altitud); //3 param constructor
	~Coord_Point(); //destructor

	long double GetLat();
	long double GetLon();
	long double GetAlt();
};

class Waypoint
{
public:

	//long double longitud, latitud, altitud; //basic 3 variables
	//long double *WayArr; // dynamic array
	Coord_Point *WayArr; // dynamic array

	int WaySize = 12; //for basic array

	Waypoint(); //default constructor
	Waypoint(int New_Size); //1 param constructor
	~Waypoint(); //destructor

	void WaySet(int index, long double New_longitud, long double New_latitud, long double New_altitud); //setter
	void WayGet(int index, long double& New_latitud, long double& New_longitud, long double& New_altitud); //Getter

};
#endif