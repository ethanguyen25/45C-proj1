//distance.cpp

#include <iostream>
#include <cmath>

//Calculates the distance with given inputs.

double distance(double newLat1, double newLon1,
             double newLat2, double newLon2)
{
    double eradius = 3959.9;

    //Need to convert to radians. 
    double conversion = (M_PI/180);

    double dlat = (newLat2 - newLat1) * conversion;
    double dlon = (newLon2 - newLon1) * conversion;
    
    newLat1 = newLat1 * conversion;
    newLat2 = newLat2 * conversion;

    double a = pow(sin(dlat/2),2) + (cos(newLat1) * 
                    cos(newLat2) * pow(sin(dlon/2),2));
    //double arctanNum = (sqrt(a) / sqrt(1-a));
    //double c = 2 * (atan (arctanNum));
    double c = 2 * (atan2(sqrt(a), sqrt(1-a)));
    
    double d = eradius * c;
    //std::cout << "Distance: " << d << std::endl;

    return d;

}
