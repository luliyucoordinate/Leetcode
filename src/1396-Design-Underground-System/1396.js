
var UndergroundSystem = function() {
    this.check_in = new Map();
    this.check_out = new Map();
};

/** 
 * @param {number} id 
 * @param {string} stationName 
 * @param {number} t
 * @return {void}
 */
UndergroundSystem.prototype.checkIn = function(id, stationName, t) {
    this.check_in.set(id, [stationName, t]);
};

/** 
 * @param {number} id 
 * @param {string} stationName 
 * @param {number} t
 * @return {void}
 */
UndergroundSystem.prototype.checkOut = function(id, stationName, t) {
    let [startName, timeIn] = this.check_in.get(id);
    let name = startName + ">" + stationName;
    if (!this.check_out.has(name)) this.check_out.set(name, [0, 0]);
    let [avg, cnt] = this.check_out.get(name);
    this.check_out.set(name, [avg + t - timeIn, cnt + 1]);
};

/** 
 * @param {string} startStation 
 * @param {string} endStation
 * @return {number}
 */
UndergroundSystem.prototype.getAverageTime = function(startStation, endStation) {
    let name = startStation + ">" + endStation;
    return this.check_out.get(name)[0] / this.check_out.get(name)[1];
};