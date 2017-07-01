/*File: 5MinDtect.js
* Author: Tim Lee
* Date Created: 6/30/2017

* checkIdle function will determine whether a coordinate needs to change based
* on the 5-minute mark.
*
* getAdjacentSectors function will generate the eight adjacent sectors from the
* current centered one.
*/

/*
* checkIdle
* latitude: the latitude coordinate
* longitude: the longitude coordinate
* idleTime: 300 seconds
*/
function checkIdle(latitude, longitude, idleTime, increment){
    var item = {lat: latitude, lon: longitude, time: Math.round(Date.now()/1000)};

    locationHistory.push(item);

    while(locationHistory.length > 1){

        var temp = locationHistory[0].time;
        var lastElement = locationHistory.slice(-1)[0].time;
        var diff = lastElement - temp;

        if(diff > (idleTime+60)){
            locationHistory.shift();
        }
        else if(diff < idleTime){
            return false;
        }
        else if (diff >= idleTime && diff <= (idleTime+60)){
            var coords1 = GenIDFromCoord(locationHistory[0].lat, locationHistory[0].lon, increment);
            var coords2 = GenIdFromCoord(locationHistory.slice(-1)[0].lat, locationHistory.slice(-1)[0].lon, increment);
            if(coords1 == coords2){
                return true;
            }
        }
    }
}

/*
* getAdjacentSectors
* Generates the adjacent eight sectors from the current one.
* Parameters:
*   id: the current sector
*   increment: the range of the sector coordinates
*/
function getAdjacentSectors(id, increment){
    var partsArray = id.split('|');
    for(i=0; i<partsArray.length; i++){
        partsArray[i] = parseFloat(partsArray[i]);
    }
    var toReturn = [id];
    toReturn.push(partsArray[0]+"|"+(partsArray[1]-increment)+"|"+partsArray[2]+"|"+(partsArray[3]-increment));
    toReturn.push((partsArray[0]-increment)+"|"+(partsArray[1]-increment)+"|"+(partsArray[2]-increment)+"|"+(partsArray[3]-increment));
    toReturn.push((partsArray[0]-increment)+"|"+partsArray[1]+"|"+(partsArray[2]-increment)+"|"+partsArray[3]);
    toReturn.push((partsArray[0]-increment)+"|"+(partsArray[1]+increment)+"|"+(partsArray[2]-increment)+"|"+(partsArray[3]+increment));
    toReturn.push(partsArray[0]+"|"+(partsArray[1]+increment)+"|"+partsArray[2]+"|"+(partsArray[3]+increment));
    toReturn.push((partsArray[0]+increment)+"|"+(partsArray[1]+increment)+"|"+(partsArray[2]+increment)+"|"+(partsArray[3]+increment));
    toReturn.push((partsArray[0]+increment)+"|"+partsArray[1]+"|"+(partsArray[2]+increment)+"|"+partsArray[3]);
    toReturn.push((partsArray[0]+increment)+"|"+(partsArray[1]-increment)+"|"+(partsArray[2]+increment)+"|"+(partsArray[3]-increment));
    return toReturn;
}