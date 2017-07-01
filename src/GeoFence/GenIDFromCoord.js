// GenIDFromCoord.js
var minLat = -90.0;
var maxLat = 90.0;
var minLong = -180.0;
var maxLong = 180.0;
var increment = 0.001;
// console.log(process.argv.join("|"));
if (process.argv[2] != null)
    increment = parseFloat(process.argv[2])
// console.log(increment);
var modInc = Math.round(1/increment);
// console.log(modInc);
var preciseness = (modInc + "").length - 1;
// console.log(preciseness);

var lat = 23.23323265;
var lon = -141.213323243;
if (typeof myVar != 'undefined' && "geolocation" in navigator) {
    navigator.geolocation.getCurrentPosition(function (position) {
        lat = position.coords.latitude;
        lon = position.coords.longitude;
        console.log(position.coords.latitude + " " + position.coords.longitude);
    });
} else {
    console.log(lat + " " + lon);
}
console.log(increment);
var id1 = (Math.ceil(lat * modInc) * increment).toFixed(preciseness) + "|" + (Math.floor(lon * modInc) * increment).toFixed(preciseness);
var id2 = (Math.floor(lat * modInc) * increment).toFixed(preciseness) + "|" + (Math.ceil(lon * modInc) * increment).toFixed(preciseness);
var id = id1 + "|" + id2;
console.log(id);