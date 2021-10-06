/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    const ans = [];
    nums.forEach((num, idx) =>{ 
        const org = Math.abs(num);
        if(nums[org-1] < 0) ans.push(org);
        else nums[org-1]*=-1;
    })
    return ans;
};
