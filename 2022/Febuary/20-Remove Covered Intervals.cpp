class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int erased[1005] = {0,};
        for(int i=0;i<intervals.size();i++) {
            for(int j=0;j<intervals.size();j++) {
                if(i==j) continue;
                if(intervals[i][0] <= intervals[j][0] && intervals[j][1] <= intervals[i][1]) {
                    erased[j] = 1;
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<intervals.size();i++) {
            ans += !erased[i];
        }
        return ans;
    }
};
