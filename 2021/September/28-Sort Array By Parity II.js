/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArrayByParityII = function(nums) {
    const odd = [], even = [];
    for(let i = 0;i<nums.length;i++){
        if(nums[i] % 2) odd.push(nums[i]);
        else even.push(nums[i]);
    }
    
    const ans = [];
    for(let i=0;i<nums.length/2;i++) {
        ans.push(even[i]);
        ans.push(odd[i]);
    }
    return ans;
};
