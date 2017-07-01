/*
* File: GenIDFromCoord.cpp
* Author: Tim Lee
* Date Created: 6/27/2017
*
* This program takes in two coordinates from the command line and rounds them
* both up and down based on the increment value.
*
* Compile:
  g++ -std=c++11 GenIDFromCoord.cpp -o GenIDFromCoord
*/

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

    double minLat = -90.0;
    double maxLat = 90.0;
    double minLong = -180.0;
    double maxLong = 180.0;
    
    double increment = 0.001;
    
    if(argv[1] != NULL){
        increment = stod(argv[1]);
    }
    
    double modInc = 1/increment;
    cout << modInc << endl;
    
    double lat = 23.23654;
    double lon = -141.21343;
    
    cout << ceil(lat*modInc)*increment << "|" << floor(lon*modInc)*increment; 
    cout << "|" << floor(lat*modInc)*increment << "|";
    cout << ceil(lon*modInc)*increment << endl;
    
    
    
    return 0;
}

var minLat = -90.0;
var maxLat = 90.0;
var minLong = -180.0;
var maxLong = 180.0;

var increment = 0.001;

if(process.argv[1] != NULL){
        increment = parseFloat(process.argv[1]);
}

var modInc = 1/increment;
console.log(modInc);

var lat = 23.2365;
var lon = -141.21343;

if ("geolocation" in navigator) {
    navigator.geolocation.getCurrentPosition(function(position) {
        console.log(position.coords.latitude + " " + position.coords.longitude);
    });
} 
else {
    console.log("No Navigator");
}

var id = Math.ceil(lat*modInc)*increment + "|" + Math.floor(lon*modInc)*increment;
var id2 = 

console.log(Math.ceil(lat*modInc)*increment + "|" + Math.floor(lon*modInc)*increment);
console.log()

