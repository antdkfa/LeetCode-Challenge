class Solution {
public:
    map<int,int> m;
    int idx;
    
    vector<vector<int>> v;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        v.resize(nums.size()+5);
        for(int i=0;i<nums.size();i++) {
           if(!m[nums[i]]) {
               m[nums[i]] = ++idx;
           } 
            v[m[nums[i]]].push_back(i);
        }
        
        for(int i=1;i<=idx;i++) {
            for(int j=0;j<v[i].size() - 1;j++) {
                if(v[i][j+1]-v[i][j]<=k) return true;
            }
        }
        
        return false;
    }
};
