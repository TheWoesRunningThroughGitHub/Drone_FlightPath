#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int Auto_Grid_Waypoint_Generator(double StartLatitud, double Start_Longitud)
{
	double CoordX2, CoordY2;
	double GridSize_Length, GridSize_Width, GridSpacing;
	double Err_Test;

	//****************
	//Ask requirements
	//****************

	cout << "Input grid length (m) : ";   // //square
	cin >> GridSize_Length;

	cout << "Size of the grid AxA (A) : ";
	cin >> GridSpacing;

	Err_Test = fmod(GridSize_Length, GridSpacing);

	if (Err_Test != 0)
	{
		cout << "The spacing inputted doesn't evenly go into the grid." << endl;

		return NULL;
	}

	//build grid
	while (true)
	{
	
	}

	system("PAUSE");
	return NULL;
}