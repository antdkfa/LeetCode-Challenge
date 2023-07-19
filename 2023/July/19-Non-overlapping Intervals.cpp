class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int ans = 0, s = -1e9, e = -1e9;
        for (int i=0;i<intervals.size();i++) {
            int nowS = intervals[i][0], nowE = intervals[i][1];
            if(nowS < e) {
                e = min(e, nowE);
                ans++;
            } else {
                e = nowE;
            }
        }
        return ans;
    }
};
