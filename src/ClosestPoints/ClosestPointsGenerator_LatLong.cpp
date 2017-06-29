/*
* File: ClosestPointsGenerator_LatLong.cpp
* Author: Tim Lee
* Date Created: 6/26/2017
* This program generates random latitude-longitude coordinates into a text file.
* The format will be of:
*                        Number of Coordinates
*                         Lat1 Lon1 Lat2 Lon2
*                         Lat1 Lon1 Lat2 Lon2
*
* Compile: g++ ClosestPointsGenerator_LatLong.cpp -o [executable name]
*/

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#include <ctime>

using namespace std;

double randomLatGenerator();
double randomLongGenerator();

const int numberCoordinates = 50;

int main(){
    
    ofstream outFile;
    outFile.open("Test1_LatLong.txt");
    
    srand(unsigned(time(0)));
    
    double x1, y1, x2, y2;
    
    outFile << numberCoordinates << endl;
    
    for(int i=0; i<numberCoordinates; i++){
    
        for(int k=0; k<4; k++){
            double randomLatNumber = randomLatGenerator();
            double randomLongNumber = randomLongGenerator();
            
            if(k == 0 || k == 2){
                outFile << randomLatNumber << " ";
            }
            else if(k == 1){
                outFile << randomLongNumber << " ";
            }
            else if(k == 3){
                outFile << randomLongNumber << endl;
            }
        }
    }
    
    outFile.close();
    return 0;
}

/*
* The range of decimal degrees for latitude is -90 to 90.
*/
double randomLatGenerator(){

    double min = -90.0;
    double max = 90.0;
    double lat_Number;
    lat_Number = min + (double)rand() * (max - min)/(double)RAND_MAX;
    return lat_Number;
}

/*
* The range of decimal degrees for longitude is -180 to 180.
*/
double randomLongGenerator(){

    double min = -180.0;
    double max = 180.0;
    double long_Number;
    long_Number = min + (double)rand() * (max - min)/(double)RAND_MAX;
    return long_Number;
}


