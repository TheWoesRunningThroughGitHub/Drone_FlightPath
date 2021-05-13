//****************************************************
// File: Main.cpp
//
// Purpose: Simple command to create a grid
//
// Written By: David Wan & Diego Cordova
//
// Compiler: Visual C++ 2017
//
//****************************************************
#include "Functions.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
//#include "Classes.h"
#include"Class_Coord_Point.h"
#include"Class_Waypoint.h"

using namespace std; 

int main()
{
	long double Lat=0.00, Lon=0.00 , Alt=1.00; //latitude, longitude, altitude
	//long double H_Lat = 0.00, H_Lon = 0.00, H_Alt = 0.00; //latitude, longitude, altitude

	int GridPoints = 0; //tracks number of points that need to be made


	double d_time = 2.0, d_precise = 20; //quick changes

	Waypoint FlightGrid;

	//Testing
	//===========================================================
	//Coord_Point FirstP1;
	//Coord_Point FirstP2(2.0, 3.0);

	//cout << FirstP1 << endl;
	//cout << FirstP2 << endl;

	//cout << FlightGrid;

	//long double test[3] = { 10,20,30 };
	//CreateWaypointFile(3, test);
	//=============================================================

	
	ofstream FlightFile; //create waypoint file
	FlightFile.open("FlightPath_2.waypoints");

	if (!FlightFile) //In case of issue, output error
	{
		cout << "Error in creating file" << endl;
		return 0;
	}

	FlightFile << "QGC WPL 110" << endl; //Line 1

	//Setting Home 
	ReadHomeLocation(Lat, Lon);
	//cout << setprecision(14) << Lat << "  " << Lon << "  " << Alt << " " << endl;

	FlightFile << setprecision(d_precise)  << "0	1	0	16	0	0	0	0	" << Lat << "	" << Lon << "	" << Alt << "	1" << endl; //Line 2 (Home Position)
	//H_Lat = Lat; 
	//H_Lon = Lon; 
	//H_Alt = Alt;

	//Auto takeoff
	Alt = 5;
	FlightFile << "1	0	3	22	0	0	0	0	0	 0 	" << Alt << "	1" << endl; //Line 3 (Launch)


	cout << endl << "Begin grid:" << endl;
	cout << "Input Starting Altitude: ";
	cin >> Alt;

	Auto_Grid_Waypoint_Generator(Lat, Lon, Alt, GridPoints, FlightGrid); //begin filling grid

	//cout << FlightGrid << endl;
	//cout << Auto_Grid_Waypoint_Generator(Lat, Lon, Alt, GridPoints);

	//Begin inserting points
	int Act = 2;
	//while ()
	for (int j = 0; j < GridPoints; j++)
	{
		//Lat = *FlightGrid.WayArr[j].latitud;
		//Lon = FlightGrid.WayArr[j].GetLon();

		FlightGrid.WayGet(j, Lat, Lon, Alt);

		//Waypoint
		FlightFile << setprecision(d_precise) << Act << "	0	3	16	0	0	0	0	" << Lat << "	" << Lon << "	" << Alt << "	1" << endl;
		//note - 16 is the waypoint command action
		Act++; //increases to create the next line

		//Signal 
		FlightFile << setprecision(d_precise) << Act << "	0	3	206	0.00000000	0.00000000	0.00000000	0.00000000	0.00000000	0.00000000	" << Alt << "	1" << endl;
		//note - 206 is the signal output command action
		Act++; //increases to create the next line

		//Loiter
		FlightFile << setprecision(d_precise) << Act << "	0	3	19	"<< d_time <<"	0.00000000	0.00000000	0.00000000	" << Lat << "	" << Lon << "	" << Alt << "	1" << endl;
		//note - 19 is the loiter command action
		Act++; //increases to create the next line

	}

	//Return to launch
	FlightFile << setprecision(d_precise) << Act << "	0	3	20	0	0	0	0	0	0	0	1" << endl;
	 
	// //Land
	//FlightFile << Act << "	0	3	21	0.00000000	0.00000000	0.00000000	0.00000000	" << H_Lat << "	" << H_Lon << "	1.000000	1" << endl;
	

	FlightFile.close();
	

	return 1; 
}