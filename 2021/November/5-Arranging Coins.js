/**
 * @param {number} n
 * @return {number}
 */
var arrangeCoins = function(n) {
    let l = 1, r = 1e5;
    while(l <= r) {
        let row = Math.floor((l + r) / 2);
        let coins = (row * (row+1))/2;
        if(coins - row + 1 <= n && n <= coins) {
            if(n==coins) return row;
            else return row - 1;
        } else if(n<coins-row+1) {
            r = row-1;
        } else {
            l = row+1;
        }
    }
    
    return 0;
};
