#include "Functions.h"
#include <cmath>
using namespace std;

//taken from stack exchange
double Coords2Meters(double lat1, double lon1, double lat2, double lon2)
{  // generally used geo measurement function
	double pi = 2 * acos(0.0);
	double R = 6378.137; // Radius of earth in KM
	double dLat = lat2 * pi / 180 - lat1 * pi / 180;
	double dLon = lon2 * pi / 180 - lon1 * pi / 180;
	double a = sin(dLat / 2) * sin(dLat / 2) +
		cos(lat1 * pi / 180) * cos(lat2 * pi / 180) *
		sin(dLon / 2) * sin(dLon / 2);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	double d = R * c;
	return d * 1000; // meters
}

//double Meters2Coords(double dist)
//{
//
//}

// Length in meters of 1° of latitude = always 111.32 km
//Length in meters of 1° of longitude = 40075 km * cos(latitude) / 360
