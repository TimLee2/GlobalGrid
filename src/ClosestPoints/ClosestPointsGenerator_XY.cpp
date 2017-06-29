/*
* File: ClosestPointsGenerator_XY.cpp
* Author: Tim Lee
* Date Created: 6/26/2017
* This program generates random coordinates into a text file.
* The format will be of:
*                       Number of Coordinates
*                            X1 Y1 X2 Y2
*                            X1 Y1 X2 Y2
*/

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#include <ctime>

using namespace std;

double randomGenerator();

const int numberCoordinates = 50;

int main(){
    
    ofstream outFile;
    outFile.open("Test1_XY.txt");
    
    srand(unsigned(time(0)));
    
    double x1, y1, x2, y2;
    
    outFile << numberCoordinates << endl;
    
    for(int i=0; i<numberCoordinates; i++){
    
        for(int k=0; k<4; k++){
            double randomNumber = randomGenerator();
            
            if(k < 3){
                outFile << randomNumber << " ";
            }
            else if(k == 3){
                outFile << randomNumber << endl;
            }
        }
    }
    
    outFile.close();
    return 0;
}

double randomGenerator(){

    double min = -100.0;
    double max = 200.0;
    double number;
    number = min + (double)rand() * (max - min)/(double)RAND_MAX;
    return number;
}


