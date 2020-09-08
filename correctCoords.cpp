//correctCoords.cpp

#include <iostream>

//Need to change coordinates correctly to differentiate between same 
//  numbers but different directions.
//Changes numbers to negative if direction is South or West.


double correctLat(double latNum1, std::string latStr1)
{
       
    if (latStr1 == "/S")
    {
        latNum1 = -latNum1;
    }

    return latNum1;
}

double correctLon(double lonNum1, std::string lonStr1)
{    
    if (lonStr1 == "/W")
    {
        //std::cout << "correctCoords" << std::endl;
        lonNum1 = -lonNum1;
    }
    
    return lonNum1;
}
