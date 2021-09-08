/**
 * @param {string} s
 * @param {number[]} shifts
 * @return {string}
 */
var shiftingLetters = function(s, shifts) {
    let post = Array.from({length: shifts.length + 1}, idx => 0);
    
    for(let i=shifts.length-1;i>=0;i--) {
        post[i] = (shifts[i] + post[i+1])%26;
    }
    
    let ans = '';
    for(let i=0;i<shifts.length;i++) {
        ans += (String.fromCharCode((((s[i].charCodeAt() - 97) + post[i])%26 + 97)));
    }
    return ans;
};
