//****************************************************
// File: Main.cpp
//
// Purpose: Simple command to create a grid
//
// Written By: David Wan
//
// Compiler: Visual C++ 2017
//
//
// Update Information
// ------------------
//
// Name: David Wan
// Date: 
// Description: 
//
//****************************************************

#include <iostream> 
#include <fstream> 
#include <string>

#include "Functions.h"

using namespace std; 

int main()
{
	long double Lat, Lon, Alt; //latitude, longitude, altitude
	bool AddLines = true; //loops

	ofstream FlightFile; //create waypoint file
	FlightFile.open("FlightPath_1.waypoints");

	if (!FlightFile) //In case of issue, output error
	{
		cout << "Error in creating file";
		return 0;
	}

	FlightFile << "QGC WPL 110" << endl; //Line 1

	cout << "Set Home here: " << endl;

	cout << "Input Latitude: ";
	cin >> Lat;
	cout << "Input Longitude: ";
	cin >> Lon;
	cout << "Input Altitude: ";
	cin >> Alt;

	FlightFile << "0	1	0	16	0	0	0	0	" << Lat << "	" << Lon << "	" << Alt << "	1" << endl; //Line 2 (Home Position)
	FlightFile << "1	0	3	22	0.00000000	0.00000000	0.00000000	0.00000000	0.00000000	 0.00000000 	" << Alt << "	1" << endl; //Line 3 (Launch)

	cout << endl << "Begin grid:" << endl;

	//Begin inserting points
	int Act = 2;
	while (AddLines)
	{
		//Waypoint
		//Temporary -----------------
		cout << "New Wapoint" << endl;
		cout << "Input Latitude: ";
		cin >> Lat;
		cout << "Input Longitude: ";
		cin >> Lon;
		cout << "Input Altitude: ";
		cin >> Alt;
		cout << endl;
		//----------------------------

		FlightFile << Act << "	0	3	16	0.00000000	0.00000000	0.00000000	0.00000000	0.00000000	0.00000000	" << Alt << "	1" << endl;
		//note - 16 is the waypoint command action
		Act++; //increases to create the next line

		//Signal 
		FlightFile << Act << "	0	3	206	0.00000000	0.00000000	0.00000000	0.00000000	" << Lat << "	" << Lon << "	" << Alt << "	1" << endl;
		//note - 206 is the signal output command action
		Act++; //increases to create the next line

		//Loiter
		FlightFile << Act << "	0	3	19	10.00000000	0.00000000	0.00000000	0.00000000	" << Lat << "	" << Lon << "	" << Alt << "	1" << endl;
		//note - 19 is the loiter command action
		Act++; //increases to create the next line

		//temporary break (testing)
		if (Act == 12 || Act > 12)
		{
			AddLines = false;
		}


	}

	//Return to launch
	FlightFile << Act << "	0	3	20	0.00000000	0.00000000	0.00000000	0.00000000	0.00000000	0.00000000	0.00000000	1" << endl;


	FlightFile.close();

//	system("PAUSE"); //pauses the output screen to view the final outputs
	return 0; 
}
