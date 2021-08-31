/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let s = 0, e = nums.length - 1, ans = nums[0];
    while(s <= e) {
        let mid = Math.floor((s + e) / 2);
        ans = Math.min(ans, nums[mid]);
        if(nums[0] <= nums[mid]) s = mid+1;
        else e = mid - 1;
    }
    
    return ans;
};
