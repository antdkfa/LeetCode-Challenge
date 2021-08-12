/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    var ans = [], visited = [], idx = 0;
    strs.forEach((item) => {
        var tmp = new Array(26).fill(0);
        for(var i=0;i<item.length;i++) {
            tmp[item[i].charCodeAt(0) - 97]++;
        }
        var now = "";
        for(var i=0;i<tmp.length;i++){
            now +=tmp[i] + ',';
        }
        if(visited[now] === undefined) {
            visited[now] = idx++;
            ans.push([item]);
        } else {
            ans[visited[now]].push(item);
        }
    })
    
    return ans;
};
