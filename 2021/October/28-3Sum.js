/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    nums.sort((a, b)=> {
        if(a < b) return -1;
        else return 1;
    })
    
    let ans = [];
    const dup = {};
    nums.forEach((num, idx) => {
        for(let i=idx+1;i<nums.length;i++) {
            let s = i+1, e = nums.length - 1;
            while(s<=e) {
                let mid = Math.floor((s + e) / 2);
                let sum = num + nums[i] + nums[mid];
                if(sum === 0) {
                    const arr = [num, nums[i],nums[mid]].sort((a, b) =>{ 
                        if(a < b) return -1;
                        else return 1;
                    });
                    const duplicated = arr[0].toString() + "," + arr[1].toString() + "," + arr[2].toString();
                    if(!dup[duplicated]) {
                        dup[duplicated] = 1;
                        ans.push(arr);
                    }
                    break;
                } else if(sum < 0) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
    })
    
    return ans;
};
