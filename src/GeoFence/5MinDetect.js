/*
* File: 5MinDetect.js
* Author: Tim Lee
* Date Created: 6/30/2017
*
* This file contains the functions used for anything relate to sectors.
*
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
function getAdjacentSectors(id, inc) {
    var decs = (Math.round(1/inc) + "").length - 1;
    var partsArray = id.split('|');
    for(i=0; i < partsArray.length; i++){
        partsArray[i] = parseInt(partsArray[i]);
    }
    var ids = [partsArray.join("|")];
    ids.push((partsArray[0]+"|"+((partsArray[1]*inc)-inc).toFixed(decs)+"|"+partsArray[2]+"|"+((partsArray[3]*inc)-inc).toFixed(decs)).split('.').join(""));
    ids.push((((partsArray[0]*inc)-inc).toFixed(decs)+"|"+((partsArray[1]*inc)-inc).toFixed(decs)+"|"+((partsArray[2]*inc)-inc).toFixed(decs)+"|"+((partsArray[3]*inc)-inc).toFixed(decs)).split('.').join(""));
    ids.push((((partsArray[0]*inc)-inc).toFixed(decs)+"|"+partsArray[1]+"|"+((partsArray[2]*inc)-inc).toFixed(decs)+"|"+partsArray[3]).split('.').join(""));
    ids.push((((partsArray[0]*inc)-inc).toFixed(decs)+"|"+((partsArray[1]*inc)+inc).toFixed(decs)+"|"+((partsArray[2]*inc)-inc).toFixed(decs)+"|"+((partsArray[3]*inc)+inc).toFixed(decs)).split('.').join(""));
    ids.push((partsArray[0]+"|"+((partsArray[1]*inc)+inc).toFixed(decs)+"|"+partsArray[2]+"|"+((partsArray[3]*inc)+inc).toFixed(decs)).split('.').join(""));
    ids.push((((partsArray[0]*inc)+inc).toFixed(decs)+"|"+((partsArray[1]*inc)+inc).toFixed(decs)+"|"+((partsArray[2]*inc)+inc).toFixed(decs)+"|"+((partsArray[3]*inc)+inc).toFixed(decs)).split('.').join(""));
    ids.push((((partsArray[0]*inc)+inc).toFixed(decs)+"|"+partsArray[1]+"|"+((partsArray[2]*inc)+inc).toFixed(decs)+"|"+partsArray[3]).split('.').join(""));
    ids.push((((partsArray[0]*inc)+inc).toFixed(decs)+"|"+((partsArray[1]*inc)-inc).toFixed(decs)+"|"+((partsArray[2]*inc)+inc).toFixed(decs)+"|"+((partsArray[3]*inc)-inc).toFixed(decs)).split('.').join(""));

    /*for(i=0; i<ids.length; i++){
        console.log(ids);
    }*/
    
    return ids;
}
getAdjacentSectors("37294|-121852|37293|-121851", .001);


/*
* keyToCoords
* Converts the key in "lat|long|lat|long" format into its decimal equivalent.
*/
function keyToCoords(id, increment){
    var partsArray = id.split('|');
    for(i=0; i < partsArray.length; i++){
        partsArray[i] = ((parseInt(partsArray[i])*increment).toFixed((Math.round(1/increment) + "").length - 1));
    }
    return partsArray;
}

/*
* coordsToKey
* Converts the decimal of latitude and longitude into the "lat|long|lat|long format".
*/
function coordsToKey(coordsArray, increment){
    for(i=0; i<coordsArray.length; i++){
        coordsArray[i] = Math.round(((coordsArray[i]*(1/increment)).toFixed((Math.round(1/increment) + "").length - 1)));
    }
    var key = coordsArray.join("|");
    console.log(key);
    return key;
}
