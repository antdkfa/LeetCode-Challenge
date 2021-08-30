/**
 * @param {number} m
 * @param {number} n
 * @param {number[][]} ops
 * @return {number}
 */
var maxCount = function(m, n, ops) {
    let r = m, c = n;
    for(let i=0;i<ops.length;i++) {
        r = Math.min(r,ops[i][0]);
        c = Math.min(c,ops[i][1]);
    }
    return r * c;
};
