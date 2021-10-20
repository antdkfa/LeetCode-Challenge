/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    const str = s.split(' ');
    let ans = '';
    for(let i=str.length-1;i>=0;i--) {
        if(str[i] == '') continue;
        if(ans != '') ans += ' ';
        ans += str[i];
    }
    
    return ans;
};
