//strings.cpp

#include <iostream>
#include <string>

//This file just formats the strings for the output. 

std::string first_output(double latNum1, std::string latStr1, 
                     double lonNum1, std::string lonStr1, 
                     std::string name1)
{
    std::string s = (std::to_string(latNum1) + latStr1 + " " +
                     std::to_string(lonNum1) + lonStr1 + " (" + 
                     name1 + ")");
    return s;

}


std::string output(double latNum2, std::string latStr2,
            double lonNum2, std::string lonStr2,
            std::string name2, double number)
{
    std::string s = (std::to_string(latNum2) + latStr2 + " " +
                     std::to_string(lonNum2) + lonStr2 + " (" +
                     name2 + ") (" + std::to_string(number) + 
                     " miles)");
    return s;
}




