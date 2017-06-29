/*
* File: ClosestPoints_LatLong.cpp
* Author: Tim Lee
* Date Created: 6/25/2017
* 
* This program will calculate the distance between two latitude-longitude
* points.
* A generated text file containing the decimal degrees will be read by the 
* program.
*
* Compile: g++ ClosestPoints_LatLong.cpp -o [executable name]
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <math.h>

#define pi 3.14159265358979323
#define earthRadiusKm 6371.00

using namespace std;

double calculateDistance(double, double, double, double);
double degToRad(double);

int main(int argc, char *argv[]){

    ifstream inFile;
    inFile.open("Test1_LatLong.txt");
    
    int numberCoordinates;
    inFile >> numberCoordinates;
    cout << "Number of Coordinates to process: " << numberCoordinates << endl;
    
    double lat1, lon1, lat2, lon2;
    double lat1s, lon1s, lat2s, lon2s;
    double smallestDistance = 0;
    
    for(int i=0; i<numberCoordinates; i++){
        inFile >> lat1 >> lon1 >> lat2 >> lon2;
        double distance = calculateDistance(lat1, lon1, lat2, lon2);
        
        if(i == 0){
            smallestDistance = distance;
            cout << "Starting Smallest Distance: " << smallestDistance << endl;
        }
        
        if(distance < smallestDistance){
            smallestDistance = distance;
            lat1s = lat1;
            lon1s = lon1;
            lat2s = lat2;
            lon2s = lon2;
            cout << "New Smallest Distance: " << smallestDistance << endl;
        }
    }
    cout << "SMALLEST DISTANCE: " << smallestDistance << endl;
    cout << lat1s << ", " << lon1s << endl;
    cout << lat2s << ", " << lon2s << endl;
    
    inFile.close();
    return 0;
}

/*
* This function converts the decimal degrees to its radians equivalent.
*/
double degToRad(double degree){
    return ((degree * pi)/180);
}

/*
* This function calculates the distance between two points on Earth using the
* Haversine formula.
*/
double calculateDistance(double lat1, double lon1, double lat2, double lon2){
    double x, y, z;
    double lat1Rad = degToRad(lat1);
    double lon1Rad = degToRad(lon1);
    double lat2Rad = degToRad(lat2);
    double lon2Rad = degToRad(lon2);
    x = sin((lat2Rad - lat1Rad)/2);
    y = sin((lon2Rad - lon1Rad)/2);
    z = asin(sqrt(x * x+cos(lat1Rad) * cos(lat2Rad) * y * y));
    double distance = z * earthRadiusKm * 2.0;
    return distance;
}




