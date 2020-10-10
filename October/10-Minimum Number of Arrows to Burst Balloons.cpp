class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        int ans = 1;
        sort(points.begin(), points.end());
        int e = points[0][1];
        for(int i = 1;i<points.size();i++){
            if(e < points[i][0]){
                ans++;
                e = points[i][1];
            }
            else e = min(e, points[i][1]);
        }
        return ans;
    }
};
