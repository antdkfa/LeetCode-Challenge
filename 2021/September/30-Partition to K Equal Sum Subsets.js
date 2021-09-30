/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var canPartitionKSubsets = function(nums, k) {
    let sum = 0;
    for(let i=0;i<nums.length;i++) {
        sum += nums[i];
    }
    if(sum % k) return false;
    
    const avg = sum / k;
    for(let i=0;i<nums.length;i++) {
        if(avg < nums[i]) return false;    
    }
    
    let ans = false;
    const go = (idx, sums) => {
        if(ans) return;
        if(idx === nums.length) {
            let flag = true;
            for(let i=0;i<k;i++) {
                if(sums[i] != avg) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans = true;
            return;
        }
        for(let i=0;i<k;i++) {
            if(sums[i] + nums[idx] > avg) continue;
            sums[i] += nums[idx];
            go(idx + 1, sums);
            sums[i] -= nums[idx];
        }
    }
    
    const sums = Array.from({length: k}, () => 0);
    go(0, sums);
    
    return ans;
};
