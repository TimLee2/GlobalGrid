/*
* File: PointInPolygon.cpp
* Author: Tim Lee
* Date Created: 6/27/2017
* 
* This program will determine if a point is within a polygon boundary.
*/

#include <iostream>

using namespace std;

int inPolygon(int, float *, float *, float, float);

int main(){

    int numVert = 4;
    //float vertX[] = {37.310864, 37.311486, 37.3094, 37.307744};
    //float vertY[] = {122.047442, 122.044672, 122.042664, 122.045806};
    float vertX[] = {90.000, 90.000, 80.000, 80.000};
    float vertY[] = {0.000, 10.000, 0.000, 10.000};
    float x = 90.000;
    float y = 10.000;
    
    int result = inPolygon(numVert, vertX, vertY, x, y);
    if(result == 0){
        cout << "Point is not in the polygon." << endl;
    }
    else if(result == 1){
        cout << "Point is in the polygon." << endl;
    }

    return 0;
}

/*
* Parameters:
*   numVert: the number of vertices in polygon
*   vertX, vertY: arrays containing the x and y coordinates of the vertices
*   x, y: the coordinates of the test point
* Returns 0 if the point is outside the polygon.
* Returns 1 if the point is inside the polygon.
*/
int inPolygon(int numVert, float *vertX, float *vertY, float x, float y){
    int i, j = 0;
    int c = 0;
    for (i = 0, j = numVert-1; i < numVert; j = i++) {
    
        if( ((vertY[i]>y) != (vertY[j]>y)) &&
        (x < (vertX[j]-vertX[i]) * (y-vertY[i]) / (vertY[j]-vertY[i]) + vertX[i]) ){

            c = !c;
        }
    }
    return c;
}
