// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>      /* printf */
#include <math.h> 
#include <iostream>
double coordsToVector(double toLat1, double toLon1, double fromLat2, double fromLon2);

int _tmain(int argc, _TCHAR* argv[])
{ 

	//http://www.movable-type.co.uk/scripts/latlong.html
	double const MEAN_EARTH_RADIUS = 3959; //miles
# define PI           3.14159265358979323846
	//double dir = coordsToVector(30.3933, 86.4753, 30.4203, 86.6167);
	//std::cout << dir;
	//return newVector;
	/*double toLat1 = 30.3933;
	double fromLat2 = 86.4753;
	double toLon1 = 30.4203; // FWB to destin
	double fromLon2 = 86.6167;*/

//}
//
//double coordsToVector(double toLat1, double toLon1, double fromLat2, double fromLon2)
//{
	//double const MEAN_EARTH_RADIUS = 3959; //miles
	double toLat1 = 30;
	double fromLat2 = 30;

	double toLon1 = 31;
	double fromLon2 = 30;

	//double phi1 = toLat1;

	//double phi2 = fromLat2;

	//double gamma1 = toLon1;

	//double gamma2 = fromLon2;

	double changeInLat = fromLat2 - toLat1; // deltaPhi
	double changeInLon = fromLon2 - toLon1; // deltaGamma
	/* previous try
	//// Magnitude
	//double a = pow(sin(changeInLat / 2), 2) + cos(toLat1)*cos(fromLat2)*pow(sin(changeInLon / 2), 2);;
	//double c = 2 * atan2(sqrt(a), sqrt(1 - a));

	//double magnitude = MEAN_EARTH_RADIUS*c;

	// Bearing
	double y = sin(toLon1)*cos(toLat1);
	double x = cos(toLat1)*sin(fromLat2) - sin(toLat1)*cos(fromLat2)*cos(changeInLon);
	//double direction = atan2(y, x);
	double direction = atan2(y,x);

	// Normalize Bearing
	std::cout << "x = "<< x << " y = " << y << "\n";
	std::cout << "dir = " << direction;

	direction = (180 *direction)/PI;
	direction = fmod(direction + 180, 360);
	std::cout << "dir = " << direction;
	*/
	//return newVector;
	double lat1, lat2, lon1, lon2;
	lat1 = 30;
	lat2 = 30;
	lon1 = 30;
	lon2 = 31;
	// new try
	double bearing = atan2(cos(lat1)*sin(lat2) - sin(lat1)*cos(lat2)*cos(lon2 - lon1),
		sin(lon2 - lon1)*cos(lat2));

	std::cout << "dir = " << bearing;

	bearing = fmod(bearing + 360, 360);

	std::cout << "dir = " << bearing;
	bearing = fmod(bearing + 180, 360);
	//bearing = (180 * bearing) / PI;
	//bearing = fmod(bearing + 180, 360);
	std::cout << "dir = " << bearing;
	std:getchar();
	return bearing;
}
