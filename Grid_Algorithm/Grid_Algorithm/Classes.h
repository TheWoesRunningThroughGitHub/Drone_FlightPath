#pragma once

//#ifndef _CLASSES_H_
//#define _CLASSES_H_

#include<iostream>
using namespace std;

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

	friend ostream& operator<<(ostream& out, const Coord_Point& overload);
};

class Waypoint
{
public:

	//long double longitud, latitud, altitud; //basic 3 variables
	//long double *WayArr; // dynamic array

	int WaySize = 10;
	Coord_Point *WayArr; // dynamic array

	Waypoint(); //default constructor

	//Waypoint(int New_Size); //1 param constructor
	void SetSize(int& New_Size);
	~Waypoint(); //destructor

	void WaySet(int index, long double New_longitud, long double New_latitud, long double New_altitud); //setter
	void WayGet(int index, long double& New_latitud, long double& New_longitud, long double& New_altitud); //Getter

	Waypoint&  operator=(const Waypoint& orig);
	friend ostream& operator<<(ostream& out, const Waypoint& overload);
};

//#endif