#include <iostream>
#include <cmath>
#include "Functions.h"

using namespace std;

int Auto_Grid_Waypoint_Generator(double StartLatitud, double Start_Longitud)
{
	double CoordX1, CoordY1;
	long double CoordX2 = 0, CoordY2 = 0;
	double GridSize_Length, GridSize_Width, GridSpacing;
	bool Err_Test, FullSurvey;

	//Waypoint Grid1;
	int ArrCount = 0;
	void SaveArr(double X1, double Y1, long double& X2, long double& Y2); //function


	//****************
	//Ask requirements
	//****************

	cout << "Size of the grid AxA (A) : ";   // //square
	cin >> GridSize_Length;

	cout << endl << "Input grid length (m) : ";
	cin >> GridSpacing;

	if (GridSize_Length <= 0 || GridSpacing <= 0)
	{
		cout << "Invalid Inputs." << endl;
		return NULL;
	}
	
	//---------------------------
	//Calculate number of points
	int PntNum = (((GridSize_Length / GridSpacing) + 1) * ((GridSize_Length / GridSpacing) + 1));
	Waypoint Grid1(PntNum);

	//---------------------------

	Err_Test = fmod(GridSize_Length, GridSpacing);

	if (Err_Test != 0)
	{
		cout << "The spacing inputted doesn't evenly go into the grid." << endl;

		return NULL;
	}

	//build grid
	CoordX1 = 0;
	CoordY1 = 0;
	
	FullSurvey = true;

	while (FullSurvey)
	{

		if (CoordX1 == GridSize_Length && CoordY1 == GridSize_Length) //check
		{
			FullSurvey = false;
		}
		else
		{
			for (int i = 0; i < (GridSize_Length / GridSpacing); i++) //going right
			{
				//CoordX2 = CoordX1 + GridSpacing;
				CoordX1 += GridSpacing;



				SaveArr(CoordX1, CoordY1, CoordX2, CoordY2);
				Grid1.WaySet(ArrCount, CoordY2, CoordX2, 1.0);
				ArrCount++;
			}
		}
		
		if (FullSurvey == true) //going forwards
		{
			CoordY1 += GridSpacing;

			SaveArr(CoordX1, CoordY1, CoordX2, CoordY2);
			Grid1.WaySet(ArrCount, CoordY2, CoordX2, 1.0);
			ArrCount++;
		}

		if (CoordX1 == GridSize_Length && CoordY1 == GridSize_Length) //check
		{
			FullSurvey = false;
		}
		else
		{
			for (int i = 0; i < (GridSize_Length / GridSpacing); i++) //going left
			{
				CoordX1 -= GridSpacing;

				SaveArr(CoordX1, CoordY1, CoordX2, CoordY2);
				Grid1.WaySet(ArrCount, CoordY2, CoordX2, 1.0);
				ArrCount++;
			}
		}

	}
	


	return NULL;
}


//Save data
void SaveArr(double X1, double Y1, long double& X2, long double& Y2)
{
	X2 = Meters2CoordsX(X1);
	Y2 = Meters2CoordsY(Y1);
}