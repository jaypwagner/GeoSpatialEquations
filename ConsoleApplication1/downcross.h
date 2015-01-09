#pragma once
class downcross
{
public:
	downcross();
	~downcross();
};


POLAR vector_from_two_points (targetOrToPoint, 
releaseOrFromPoint, isInputInRadians)
COORDINATE targetOrToPoint;
COORDINATE releaseOrFromPoint;
bool isInputInRadians;
#endif
{
    POLAR newVector = {0};
    
    double phi1   = (isInputInRadians) ? targetOrToPoint.lat 
   : (targetOrToPoint.lat * RAD_per_DEG);
    double phi2   = (isInputInRadians) ? 
releaseOrFromPoint.lat : (releaseOrFromPoint.lat * 
RAD_per_DEG);
    double gamma1 = (isInputInRadians) ? targetOrToPoint.lon 
   : (targetOrToPoint.lon * RAD_per_DEG);
    double gamma2 = (isInputInRadians) ? 
releaseOrFromPoint.lon : (releaseOrFromPoint.lon * 
RAD_per_DEG);
    double deltaPhi = phi2 - phi1;
    double deltaGamma = gamma2 - gamma1;

    // Magnitude
    double a = pow(sin(deltaPhi/2),2) + cos(phi1)*cos
(phi2)*pow(sin(deltaGamma/2),2);
    double c = 2*atan2(sqrt(a), sqrt(1-a));
    newVector.mag = MEAN_EARTH_RADIUS*c;

    // Bearing
    double y = sin(deltaGamma)*cos(phi2);
    double x = cos(phi1)*sin(phi2) - sin(phi1)*cos
(phi2)*cos(deltaGamma);
    newVector.dir = atan2(y, x);

    return newVector;
}