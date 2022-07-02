class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int mxH = 0, mxV = 0;
        for(int i=0;i<horizontalCuts.size() - 1;i++) {
            mxH = max(mxH, horizontalCuts[i+1] - horizontalCuts[i]);           
        }
        
        for(int i=0;i<verticalCuts.size() - 1;i++) {
            mxV = max(mxV, verticalCuts[i+1] - verticalCuts[i]);           
        }
        
        long long MOD = 1000000007;
        long long ans = (long long) mxH * mxV;
        ans %= MOD;
        return (int) ans;
    }
};
