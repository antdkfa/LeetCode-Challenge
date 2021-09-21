/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let ans = 0, cnt = 0;
    nums.forEach(num => {
        if(num) {
            cnt++;
            ans = Math.max(ans,cnt);
        } else { 
            cnt = 0;
        }
    })
    return ans;
};
