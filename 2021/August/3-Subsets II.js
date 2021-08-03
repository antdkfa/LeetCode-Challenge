var dfs = function(nums,index, temp, res){
    let lastpopped
    res.push(temp.slice());
    for (let i=index;i<nums.length;i++){        
        if(nums[i] === lastpopped) { continue; }
        temp.push(nums[i]);
        dfs(nums, i + 1, temp, res);
        lastpopped = temp.pop();
    }
}

var subsetsWithDup = function(nums) {
    let result = [];
    if (nums.length === 0 && nums === null) return result;
    nums.sort((a,b) => a - b);
    dfs(nums, 0, [], result);
    return result;
};
