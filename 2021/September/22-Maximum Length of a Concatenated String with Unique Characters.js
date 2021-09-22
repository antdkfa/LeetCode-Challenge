/**
 * @param {string[]} arr
 * @return {number}
 */
var maxLength = function(arr) {
    let ans = 0;
    const n = arr.length;
    
    function go(arr, depth, now) {
        if(depth == n) {
            ans = Math.max(ans, now.length);
            return;
        }
        
        let flag = true;
        const used = {};
        for(let i=0;i<arr[depth].length;i++) {
            if(!used[arr[depth][i]]) {
                used[arr[depth][i]] = 1;
            } else {
                flag = false;
                used[arr[depth][i]]++;
            }
        }
        
        if(flag) {
            for(let i=0;i<now.length;i++) {
                if(used[now[i]]) {
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag) {
            go(arr,depth + 1, now + arr[depth]);
        }
        
        go(arr,depth + 1, now);
    }
    
    go(arr, 0, "");
    
    return ans;
};
