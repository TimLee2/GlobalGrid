/*File: 5MinDtect.js
* Author: Tim Lee
* Date Created: 6/30/2017

* This file will determine whether a coordinate needs to change based
* on the 5-minute mark.
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

        var temp = locationHistory[0].item.time;
        var lastElement = locationHistory.slice(-1)[0].item.time;
        var diff = lastElement - temp;

        if(diff > (idleTime+60)){
            locationHistory.shift();
        }
        else if(diff < idleTime){
            return false;
        }
        else if (diff >= idleTime && diff <= (idleTime+60)){
            var coords1 = GenIDFromCoord(locationHistory[0].item.lat, locationHistory[0].item.lon, increment);
            var coords2 = GenIdFromCoord(locationHistory.slice(-1)[0].item.lat, locationHistory.slice(-1)[0].item.lon, increment);
            if(coords1 == coords2){
                return true;
            }
        }
    }
}