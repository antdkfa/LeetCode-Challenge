class Solution {
public:
    bool converted[205];
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++) {
            vector<int>tmp;
            bool distinct[205] = {false,};
            for(int j=i;j<nums.size();j++) {
                int now = nums[j];
                if(!converted[j] && !distinct[now]) {
                    converted[j] = true;
                    distinct[now] = true;
                    tmp.push_back(now);
                }
            }
            if(tmp.size()) ans.push_back(tmp);
        }

        return ans;
    }
};
