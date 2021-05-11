#include "Functions.h"
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

//class Coord_Point
//{
//	public:
//		//basic 3 variables
//		long double * longitud;
//		long double * latitud;
//		long double * altitud; 
//
//		Coord_Point(); //default constructor
//		Coord_Point(long double New_latitud, long double New_longitud); //2 param constructor
//		Coord_Point(long double New_latitud, long double New_longitud, long double New_altitud); //3 param constructor
//		~Coord_Point(); //destructor
//
//};
//
//class Waypoint 
//{
//	public:
//
//		//long double longitud, latitud, altitud; //basic 3 variables
//		//long double *WayArr; // dynamic array
//		Coord_Point *WayArr; // dynamic array
//
//		int WaySize = 12; //for basic array
//
//		Waypoint(); //default constructor
//		Waypoint(int New_Size); //1 param constructor
//		~Waypoint(); //destructor
//
//		void WaySet(int index, long double New_longitud, long double New_latitud, long double New_altitud); //setter
//
//};

Coord_Point::Coord_Point()
{
	latitud = new long double;
	longitud = new long double;
	altitud = new long double;

	*longitud = 0;
	*latitud = 0;
	*altitud = 0;

}

Coord_Point::Coord_Point(long double New_latitud, long double New_longitud)
{
	latitud = new long double;
	longitud = new long double;
	altitud = new long double;

	*latitud = New_latitud;
	*longitud = New_longitud;
	*altitud = 1;

}

Coord_Point::Coord_Point(long double New_latitud, long double New_longitud, long double New_altitud)
{
	latitud = new long double;
	longitud = new long double;
	altitud = new long double;

	*latitud = New_latitud;
	*longitud = New_longitud;
	*altitud = New_altitud;

}

Coord_Point::~Coord_Point()
{
	delete latitud;
	delete longitud;
	delete altitud;
}

//getters
long double Coord_Point::GetLat()
{
	return *latitud;
}
long double Coord_Point::GetLon()
{
	return *longitud;
}
long double Coord_Point::GetAlt()
{
	return *altitud;
}

//=============================================================================================================
// different classes
//=============================================================================================================

Waypoint::Waypoint() //default constructor
{
	WayArr = new Coord_Point[WaySize];

	for (int i = 0; i < WaySize; i++)
	{
		WayArr[i] = { Coord_Point(0, 0, 0) };	//initialize all elements of the array to a default value
	}

}

Waypoint::Waypoint(int New_Size)
{
	WaySize = New_Size;	//Sets member variable grade_size to the passed in paramter 
	WayArr = new Coord_Point[WaySize];	//Dynamic array of Grades

	for (int i = 0; i < WaySize; i++)
	{
		WayArr[i] = { Coord_Point(0, 0, 0) };	//initialize all elements of the array to a default value, (Name: John | Score:zero)
	}
}

Waypoint::~Waypoint() //default destructor
{
	delete[] WayArr;
}


void Waypoint::WaySet(int index, long double New_latitud, long double New_longitud, long double New_altitud)	//Sets the values at the given index to the given point
{
	if (index < 0 || index >= WaySize)	//detects if the index value is a valid index number
	{
		cout << "Invalid Index Number\n";	//Informs user the given index number used was invalid
	}
	else //The index number is valid
	{
		WayArr[index] = Coord_Point(New_latitud, New_longitud, New_altitud);	//The Grade is set in the Array for the given index number
	}
}

void Waypoint::WayGet(int index, long double& New_latitud, long double& New_longitud, long double& New_altitud)	//Gets the values at the given index to the given point
{
	if (index < 0 || index >= WaySize)	//detects if the index value is a valid index number
	{
		cout << "Invalid Index Number\n";	//Informs user the given index number used was invalid
	}
	{
		New_latitud = WayArr[index].GetLat();
		New_longitud = WayArr[index].GetLon();
		New_altitud = WayArr[index].GetAlt();
	}
}