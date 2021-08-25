/**
 * @param {number} c
 * @return {boolean}
 */
var judgeSquareSum = function(c) {
    for(let i=0;;i++) {
        let a = i*i;
        if(c<a) break;
        let b = c - a;
        if(Math.sqrt(b) == Math.floor(Math.sqrt(b))) return true;
    }
    return false;
};
