/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    var ans = "", u = 0, i, j;
    for(i=num1.length - 1, j = num2.length - 1; i>= 0 && j>=0; i--,j--) {
        var now = (num1[i] - '0') + (num2[j] - '0') + u;
        if(now >= 10) now -= 10, u = 1;
        else u = 0;
        ans += now;        
    }
    for(i;i>=0;i--) {
        var now = (num1[i] - '0') + u;
        if(now >= 10) now -= 10, u = 1;
        else u = 0;
        ans += now;
    }
    for(j;j>=0;j--) {
        var now = (num2[j] - '0') + u;
        if(now >= 10) now -= 10, u = 1;
        else u = 0;
        ans += now;
    }
    if(u) ans += u;
    return ans.split("").reverse().join("");
};
