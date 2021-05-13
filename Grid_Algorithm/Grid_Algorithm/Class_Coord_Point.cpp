#include "Functions.h"
#include <iostream>
#include <cmath>
//#include <fstream>
#include "Class_Coord_Point.h"
#include "Class_Waypoint.h"

using namespace std;


Coord_Point::Coord_Point()
{
	latitud = new long double;
	longitud = new long double;
	altitud = new long double;

	*longitud = 0.0;
	*latitud = 0.0;
	*altitud = 0.0;

}

Coord_Point::Coord_Point(long double New_latitud, long double New_longitud)
{
	latitud = new long double;
	longitud = new long double;
	altitud = new long double;

	*latitud = New_latitud;
	*longitud = New_longitud;
	*altitud = 1.0;

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

ostream& operator<<(ostream& out, const Coord_Point& overload)	//a non-member operator<< overload
{

	out << *overload.latitud << endl;
	out << *overload.longitud << endl;
	out << *overload.altitud << endl;


	return out; //returns the new overload out operation
}

Coord_Point&  Coord_Point::operator=(const Coord_Point& copy)	//a member overload for the assignment operator= - sets the values of one object to 
{
	*latitud = *copy.latitud;
	*longitud = *copy.longitud;
	*altitud = *copy.altitud;

	return *this;	//returns this pointer to return changes made
}