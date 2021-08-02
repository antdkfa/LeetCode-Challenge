/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var map = [];
    nums.unshift(-1);
    nums.forEach((e, idx) => {
        if(map[e]) map[e] = -map[e]; 
        else map[e] = idx;
    })
    
    var ans = [];
    nums.forEach((e, idx) => {
        if(map[target - e] && ((target === 2 * e && map[e] < 0) || target !== 2 * e)) ans = [idx - 1, Math.abs(map[target - e]) - 1];
    })
    return ans;
};
