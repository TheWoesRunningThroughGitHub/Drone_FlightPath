#include "Functions.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include "Class_Waypoint.h"
#include "Class_Coord_Point.h"


using namespace std;


Waypoint::Waypoint() //default constructor
{
	WayArr = new Coord_Point[WaySize];

	//WayArr[0] = Coord_Point(10.0, 10.0, 5.0);
	//WayArr[1] = Coord_Point(22.0, 20.0, 12.0);

	for (int i = 0; i < WaySize; i++)
	{
		WayArr[i] = { Coord_Point(0.0, 0.0, 0.0) };	//initialize all elements of the array to a default value
		//WayArr[i] = { Coord_Point() };
		//WayArr[i] = Coord_Point(0.0, 0.0, 0.0);
		//WayArr[i] = { Coord_Point(0.0, 0.0) };
	}

}

void Waypoint::SetSize(int& New_Size)
{
	WaySize = New_Size;	//Sets member variable grade_size to the passed in paramter 
	WayArr = new Coord_Point[WaySize];	//Dynamic array of Grades

	for (int i = 0; i < WaySize; i++)
	{
		WayArr[i] = { Coord_Point(0.0, 0.0, 0.0) };	//initialize all elements of the array to a default value
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
		WayArr[index] = Coord_Point(New_latitud, New_longitud, New_altitud);	//set in the Array for the given index number
	}
}

void Waypoint::WayGet(int index, long double& New_latitud, long double& New_longitud)	//Gets the values at the given index to the given point
{
	if (index < 0 || index >= WaySize)	//detects if the index value is a valid index number
	{
		cout << "Invalid Index Number\n";	//Informs user the given index number used was invalid
	}
	{
		New_latitud = WayArr[index].GetLat();
		New_longitud = WayArr[index].GetLon();
		//New_altitud = WayArr[index].GetAlt();
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

Waypoint&  Waypoint::operator=(const Waypoint& orig)	//a member overload for the assignment operator - sets the values of one object to 
{
	delete[] WayArr;	//deletes original array;

	WaySize = orig.WaySize;	//current instance’s array is now the same size as the other instance’s array.

	WayArr = new Coord_Point[WaySize]; //allocates new memory space for array;

	//Sets the array in object 1 to the array in objext 2
	for (int i = 0; i < WaySize; i++)
	{
		WayArr[i] = orig.WayArr[i];
	}

	return *this;	//returns this pointer to return changes made
}

ostream& operator<<(ostream& out, const Waypoint& overload)	//a non-member operator<< overload
{
	for (int i = 0; i < overload.WaySize; i++)
	{
		out << overload.WayArr[i] << endl;	//outputs the all elements in the array
	}

	return out; //returns the new overload out operation
}