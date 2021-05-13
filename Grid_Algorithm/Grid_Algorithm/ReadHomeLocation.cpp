#include <fstream>
#include <iostream>
#include <string>
using namespace std; 

void ReadHomeLocation(long double &Start_Latitude,long double &Start_Longitud) {

	ifstream HomeFile;
	string ignore; 

	HomeFile.open("home2.waypoints");

	getline(HomeFile,ignore);

	HomeFile >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> Start_Latitude >> Start_Longitud >> ignore >> ignore;

	HomeFile.close();
}