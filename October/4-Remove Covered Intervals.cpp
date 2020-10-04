class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 0, removed[1005] = {0,};
        for(int i = 0;i<intervals.size();i++){
            for(int j = 0;j<intervals.size();j++){
                if(i != j && !removed[j]){
                    if(intervals[i][0] <= intervals[j][0] && intervals[j][1] <= intervals[i][1]){
                        removed[j] = 1;
                    }
                }
            }
        }
        for(int i = 0;i<intervals.size();i++) if(removed[i]) ans++;
        return intervals.size() - ans;
    }
};
