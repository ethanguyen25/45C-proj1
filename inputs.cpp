//inputs.cpp

#include <iostream>
#include <string>
#include "distance.hpp"
#include "correctCoords.hpp"
#include "strings.hpp"

//This file is the 'main' file that controls where all of the inputs go.

void readInputs()
{
    //Reading the first line and second line of inputs.
    double latNum1;
    std::string latStr1;
    double lonNum1;
    std::string lonStr1;
    std::string name1;
    int howMany;

    std::cin >> latNum1 >> latStr1 >> lonNum1 >> lonStr1;
    std::getline(std::cin, name1);
    name1.erase(name1.begin());
    std::cin >> howMany;

    //Converting coords into correct num if lat is S and/or lon is W.
    double newLat1 = correctLat(latNum1, latStr1);
    double newLon1 = correctLon(lonNum1, lonStr1);
   
    //Variables for the following inputs. 
    double latNum2;
    std::string latStr2;
    double lonNum2;
    std::string lonStr2;
    std::string name2;
    
    int counter = 0;
    double changing = 0;
    double min = 0;
    double max = 0;
    

    std::string minOutput;
    std::string maxOutput;

    for (int n = 0; n < howMany; ++n)
    {
        //Reading the rest of the inputs subsequently.
        std::cin >> latNum2 >> latStr2 >> lonNum2 >> lonStr2;
        std::getline(std::cin, name2);
        name2.erase(name2.begin());

        //Converting the coords if necessary.
        double newLat2 = correctLat(latNum2, latStr2);
        double newLon2 = correctLon(lonNum2, lonStr2);
       
        //Using all the variables to find the distance.
        changing = distance(newLat1, newLon1, newLat2, newLon2);
        //std::cout << "Changing: " << changing << std::endl;

        //If only 1 comparison, then it would be both Closest 
        //  and Furthest else ...
        counter += 1;
        if (counter == 1)
        {
            min = changing;
            max = changing;
            minOutput = output(latNum2, latStr2, lonNum2, lonStr2, name2, min);
            maxOutput = minOutput;
        }
        else
        {
            if (changing < min)
            {
                min = changing;
                minOutput = output(latNum2, latStr2, lonNum2, 
                                    lonStr2, name2, min);
            }
            else if (changing > max)
            {
                max = changing;
                maxOutput = output(latNum2, latStr2, lonNum2, 
                                    lonStr2, name2, max);
            }
            else
            {
            continue;
            }
        }
        

    }
    
    std::string startOutput =  first_output(latNum1, latStr1, lonNum1, 
                                            lonStr1, name1);
    std::cout << "Start Location: " + startOutput << std::endl;
    std::cout << "Closest Location: " + minOutput << std::endl;
    std::cout << "Farthest Location: " + maxOutput << std::endl;


       
}




















