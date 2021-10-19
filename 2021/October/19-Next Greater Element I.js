/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var nextGreaterElement = function(nums1, nums2) {
    const ans = Array.from({length: nums1.length}, () => 0);
    for(let i=0;i<nums1.length;i++) {
       let now = -1, flag = false;
       for(let j=0;j<nums2.length;j++) {
           if(nums1[i] == nums2[j]) {
               flag = true;
           }
           if(flag && nums1[i] < nums2[j]) {
               now = nums2[j];
               break;
           }
       }
       ans[i] = now;
    } 
    
    return ans;
};
