#pragma once

#include<iostream>
#include "Class_Waypoint.h"
using namespace std;

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

	friend ostream& operator<<(ostream& out, const Coord_Point& overload);
	Coord_Point& operator=(const Coord_Point& copy);
};
