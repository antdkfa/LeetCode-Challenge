class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans;
        for(int i=0;i<m;i++) {
            if(r[i] - l[i] < 2) {
                ans.push_back(true);
            } else {
                vector<int> seq;
                for(int j=l[i];j<=r[i];j++) {
                    seq.push_back(nums[j]);
                }
                sort(seq.begin(), seq.end());
                int dif = seq[1] - seq[0];
                for(int j=0;j<seq.size() - 1;j++) {
                    if(seq[j+1] - seq[j] != dif) {
                        ans.push_back(false);
                        dif = -1e9;
                        break;
                    }
                }
                if(dif != -1e9) ans.push_back(true);
            }
        }

        return ans;
    }
};
