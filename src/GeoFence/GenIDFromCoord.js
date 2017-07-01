//GenIDFromCoord.js
//Date Created: 6/30/2017
//
//This file is the javascript version of the GenIDFromCoord

var minLat = -90.0;
var maxLat = 90.0;
var minLong = -180.0;
var maxLong = 180.0;

var increment = 0.001;

if(process.argv[1] != null){
        increment = parseFloat(process.argv[1]);
}

var modInc = 1/increment;
console.log(modInc);

var lat = 23.2365;
var lon = -141.21343;

if (typeof myVar != 'undefined' && "geolocation" in navigator) {
    navigator.geolocation.getCurrentPosition(function(position) {
        lat = position.coords.latitude;
        lon = position.coords.longitude;
        console.log(position.coords.latitude + " " + position.coords.longitude);
    });
} 
else {
    console.log("No Navigator");
}

var id1 = Math.ceil(lat*modInc)*increment + "|" + Math.floor(lon*modInc)*increment;
var id2 = Math.floor(lat*modInc)*increment + "|" + Math.ceil(lon*modInc)*increment;
var id = id1 + "|" + id2;

console.log(id);
