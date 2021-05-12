#include <iostream>
#include <cmath>
#include "Functions.h"
#include "Classes.h"


using namespace std;

Waypoint Auto_Grid_Waypoint_Generator(long double StartLatitud, long double Start_Longitud, long double Start_Altitud, int& Grid_Waypoints)
{
	long double CoordX1, CoordY1;
	long double CoordX2 = 0, CoordY2 = 0;
	double GridSize_Length, GridSpacing; 
	// GridSize_Width,
	bool Err_Test, FullSurvey, ValidGrid = false;


	//void Translate(long double X1, long double Y1, long double& X2, long double& Y2); //function to translate XY to LongLat
	
	//****************
	//Ask requirements
	//****************
	while (!ValidGrid)
	{
		cout << "Size of the grid AxA in meters(m) : ";   // //square
		cin >> GridSize_Length;

		cout << "Input length between points in meters(m) : ";
		cin >> GridSpacing;

		Err_Test = fmod(GridSize_Length, GridSpacing);

		if (GridSize_Length <= 0 || GridSpacing <= 0)
		{
			cout << "Invalid Inputs." << endl << endl << "Try Again:" << endl;
			//return;
			//return NULL;
			ValidGrid = false;
		}
		else if (Err_Test != 0)
		{
			cout << "The spacing inputted doesn't evenly go into the grid." << endl << endl << "Try Again:" << endl;

			ValidGrid = false;
			//return;
			//return NULL;

		}
		else
		{
			ValidGrid = true;
		}
	}

	
	//---------------------------
	//Calculate number of points
	int PntNum = (int)(((GridSize_Length / GridSpacing) + 1) * ((GridSize_Length / GridSpacing) + 1));
	Grid_Waypoints = PntNum;

	//cout << PntNum << endl;
	//---------------------------

	//build grid
	
	//Create grid
	//Waypoint Grid1(PntNum);
	Waypoint Grid1;
	Grid1.SetSize(PntNum);

	CoordX1 = 0; 
	CoordY1 = 0;
	
	CoordX2 = StartLatitud;
	CoordY2 = Start_Longitud;
	Grid1.WaySet(0, CoordY2, CoordX2, 5.0); //setting Home coordinates

	FullSurvey = false;
	int ArrCount = 1;
	while (!FullSurvey)
	{

		if (CoordX1 == GridSize_Length && CoordY1 == GridSize_Length) //check
		{
			FullSurvey = true;
		}
		else
		{
			for (int i = 0; i < (GridSize_Length / GridSpacing); i++) //going right
			{
				//CoordX2 = CoordX1 + GridSpacing;
				CoordX1 += GridSpacing;

				//Translate(CoordX1, CoordY1, CoordX2, CoordY2);
				CoordX2 += Meters2CoordsX(CoordX1);
				Grid1.WaySet(ArrCount, CoordY2, CoordX2, Start_Altitud);
				ArrCount++;
			}
		}
		
		if (FullSurvey == false) //going forwards
		{
			CoordY1 += GridSpacing;

			//Translate(CoordX1, CoordY1, CoordX2, CoordY2);
			CoordY2 += Meters2CoordsY(CoordY1);
			Grid1.WaySet(ArrCount, CoordY2, CoordX2, Start_Altitud);
			ArrCount++;
		}

		if (CoordX1 == GridSize_Length && CoordY1 == GridSize_Length) //check
		{
			FullSurvey = true;
		}
		else
		{
			for (int i = 0; i < (GridSize_Length / GridSpacing); i++) //going left
			{
				CoordX1 -= GridSpacing;

				//Translate(CoordX1, CoordY1, CoordX2, CoordY2);
				CoordX2 += Meters2CoordsX(CoordX1);
				Grid1.WaySet(ArrCount, CoordY2, CoordX2, Start_Altitud);
				ArrCount++;
			}
		}

	}
	
	return Grid1;
}


//void Translate(long double X1, long double Y1, long double& X2, long double& Y2)
//{
//	X2 = X2 + Meters2CoordsX(X1);
//	Y2 = Y2 + Meters2CoordsY(Y1);
//}
