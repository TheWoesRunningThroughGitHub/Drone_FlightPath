#pragma once

//#ifndef _CLASSES_H_
//#define _CLASSES_H_

#include<iostream>
#include "Class_Coord_Point.h"
using namespace std;


class Waypoint
{
public:

	//long double longitud, latitud, altitud; //basic 3 variables
	//long double *WayArr; // dynamic array

	//int WaySize = 10;
	int WaySize = 2;

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