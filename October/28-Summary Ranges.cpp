class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector <string> ans;
        if(nums.empty()) return ans;
        nums.push_back(1e9);
        int n = nums.size();
        for(int i = 0;i < n - 1; i++){
            if(nums[i] != 2147483647 && nums[i] + 1 == nums[i+1]){
                for(int j = i;j < n - 1;j++){
                    if(nums[j] == 2147483647 || nums[j] + 1 != nums[j + 1]){
                        string tmp = to_string(nums[i]);
                        tmp+="->";
                        tmp+=to_string(nums[j]);
                        ans.push_back(tmp);
                        i = j;
                        break;
                    }
                }
            }
            else ans.push_back(to_string(nums[i]));
        }
        return ans;
    }
};
