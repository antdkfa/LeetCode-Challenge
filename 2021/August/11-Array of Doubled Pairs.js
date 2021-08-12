/**
 * @param {number[]} arr
 * @return {boolean}
 */
var canReorderDoubled = function(arr) {
    var visited = [];
    arr.forEach((item) => {
        if(!visited[item]) visited[item] = 1;
        else visited[item]++;
    })
    
    arr.sort(function(a,b){
        return a - b;
    })
    
    var ans = true;
    arr.forEach((item) => {
        if(visited[item] > 0) {
            visited[item]--;
            if(item >= 0) {
                if(visited[item * 2] > 0) {
                    visited[item * 2]--;
                } else {
                    ans = false;
                } 
            } else if(item < 0) {
                if(item % 2 === 0 && visited[item / 2] > 0) {
                    visited[item / 2]--;
                } else {
                    ans = false;
                }
            } 
        }
    })
    
    return ans;
};
