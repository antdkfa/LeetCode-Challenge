class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        
        bool isPossible = true;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i+=3) {
            if(nums[i+2] - nums[i] > k) {
                isPossible = false;
                break;
            } else {
                vector<int> tmp;
                tmp.push_back(nums[i]);
                tmp.push_back(nums[i+1]);
                tmp.push_back(nums[i+2]);
                ans.push_back(tmp);
            }
        }

        if(!isPossible) {
            vector<vector<int>> a;
            return a;
        }
        return ans;
    }
};
