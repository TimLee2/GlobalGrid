/*
* File: ClosestPoints_XY.cpp
* Author: Tim Lee
* Date Created: 6/25/2017
* 
* This program will calculate the distance between two coordinate points.
* This program does not use the latitude-longitude system.
* A generated text file will be read by the program.
*/

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    
    ifstream inFile;
    inFile.open("Test1_XY.txt");

    double x1, y1, x2, y2;
    int numberCoordinates;
    double smallestDistance = 0;
    
    inFile >> numberCoordinates;
    cout << "Number of coordinates to process: " << numberCoordinates << endl;
    
    int counter = 0;
    while(counter < numberCoordinates){
    
        inFile >> x1 >> y1 >> x2 >> y2;
        
        int distanceX = (x2 - x1) * (x2 - x1);
        int distanceY = (y2 - y1) * (y2 - y1);
        
        double totalDistance = sqrt(distanceX + distanceY);
        
        if(counter == 0){
            smallestDistance = totalDistance;
            cout << "Starting Smallest Distance: " << smallestDistance << endl;
        }
        
        if(totalDistance < smallestDistance){
            smallestDistance = totalDistance;
            cout << "New Smallest Distance: " << smallestDistance << endl;
        }
        
        counter++;
    }
    cout << "SMALLEST DISTANCE: " << smallestDistance << endl;

    inFile.close();
    return 0;
}


