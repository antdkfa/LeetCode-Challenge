/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function(text) {
    const dp = {
        b: 0,
        a: 0,
        l: 0,
        o: 0,
        n: 0
    };
    for(let i=0;i<text.length;i++) {
        if(text[i] === 'b') {
            dp.b++;
        }
        if(text[i] === 'a') {
            dp.a++;
        }
        if(text[i] === 'l') {
            dp.l++;
        }
        if(text[i] === 'o') {
            dp.o++;
        }
        if(text[i] === 'n') {
            dp.n++;
        }
    }
    return Math.min(dp.b,dp.a,dp.l % 2 ? (dp.l - 1)/2 : dp.l/2,dp.o%2?(dp.o-1)/2:dp.o/2,dp.n);
};
