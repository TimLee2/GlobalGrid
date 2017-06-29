/*
* File: SampleGridGenerator.cpp
* Author: Tim Lee
* Date Created: 6/27/2017
*
* Compile:
* rm GridGenData.json && g++ -std=c++11 GridGenerator.cpp -o GridGen && ./GridGen.exe 1.0 >> GridGenData.json
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

    double minLat = -90.0;
    double maxLat = 90.0;
    double minLong = -180.0;
    double maxLong = 180.0;
    
    double currentLat = 90.0;
    double currentLong = -180.0;
    
    double increment = 10.0;
    if(argv[1] != NULL){
        increment = stod(argv[1]);
    }
    
    cout << "{";
    
    for(int longitude = minLong; longitude <= maxLong - increment; longitude += increment){
        for(int latitude = minLat; latitude <= maxLat; latitude += increment){
            if(longitude == (maxLong - increment) && latitude == maxLat) {
                cout << "\"" << latitude << "|" << longitude << "|" << (latitude - increment);
                cout << "|" << (longitude + increment) << "\"";
                cout << ":{\"s\":\"t\"}" << endl;
            } 
            else {
                cout << "\"" << latitude << "|" << longitude << "|" << (latitude - increment);
                cout << "|" << (longitude + increment) << "\"";
                cout << ":{\"s\":\"t\"}," << endl;
            }
        }    
    }
    cout << "}";
    return 0;
}

