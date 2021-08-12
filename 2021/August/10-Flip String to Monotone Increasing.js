/**
 * @param {string} s
 * @return {number}
 */
var minFlipsMonoIncr = function(s) {
    var pre = new Array(s.length).fill(0);
    
    if(s[0] === '1') pre[0] = 1;
    for(var i=1;i<s.length;i++){
        pre[i] = pre[i-1] + (s[i] === '1' ? 1 : 0);
    }
    
    var post = new Array(s.length).fill(0);
    
    if(s[s.length-1] === '0') post[s.length-1] = 1;
    for(var i=s.length-2;i>=0;i--){
        post[i] = post[i+1] + (s[i] === '0' ? 1 : 0);
    }
    
    var ans = Math.min(post[0], pre[s.length-1]);
    for(var i=0;i<s.length-1;i++){
        ans = Math.min(ans, pre[i] + post[i+1]);
    }
    return ans;
};
