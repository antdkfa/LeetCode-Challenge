class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int s = intervals[0][0], e = intervals[0][1];
        for(int i = 1;i<=n;i++){
            if(i == n) { v.push_back({s,e}); break; }
            if(e < intervals[i][0]) {
                v.push_back({s,e});
                s = intervals[i][0], e = intervals[i][1];
            }
            else e = max(e, intervals[i][1]);
        }
        return v;
    }
};
