/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    let cnt1 = Array.from({length: 1005}, () => 0);
    let cnt2 = Array.from({length: 1005}, () => 0);
    
    for(let i=0;i<nums1.length;i++) {
        cnt1[nums1[i]]++;
    }
    
    for(let i=0;i<nums2.length;i++ ) {
        cnt2[nums2[i]]++;
    }
    
    let ans = [];
    for(let i=0;i<=1000;i++) {
        for(let j=0;j<Math.min(cnt1[i], cnt2[i]);j++) {
            ans.push(i);
        }
    }
    return ans;
};
