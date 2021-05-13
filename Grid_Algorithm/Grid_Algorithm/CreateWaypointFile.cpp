
#include <fstream>
using namespace std; 
 
const int s = 100;
int Command_Number(int &n) {
	n = n + 1;
	return n; 
}
void CreateWaypointFile(int size, long double waypoints[])
{

	ofstream OutputFile; 
	int position = 0; 

	OutputFile.open("WaypointGrid.waypoints");

	OutputFile << " QGC WPL 110" << endl;
		for (int i = 0; i < size; i++) {
			OutputFile << "  "<< Command_Number(position) << "	 1" << "  0" << "	16" << "	0" << "	0" << "	0" << "	0" << "	 " << waypoints[i] << "	 " << waypoints[i] << "	 " << waypoints[i]<< endl;
			OutputFile << "  " << Command_Number(position) << "	 1" << "  0" << "	16" << "	0" << "	0" << "	0" << "	0" << "	 " << waypoints[i] << "	 " << waypoints[i] << "	 " << waypoints[i]<< endl;
		}

	OutputFile.close();
}