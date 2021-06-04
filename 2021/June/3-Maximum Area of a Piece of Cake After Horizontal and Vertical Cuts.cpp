class Solution {
public:
    #define MOD 1000000007
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int height = max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.size() - 1]), 
        width = max(verticalCuts[0], w - verticalCuts[verticalCuts.size() - 1]);
        height %= MOD, width %= MOD;
        long long ans = height % MOD * width % MOD;
        
        for(int i=0;i<horizontalCuts.size() - 1;i++){
            height = max(height, horizontalCuts[i+1] - horizontalCuts[i]);
            height %= MOD;
        }
        for(int i=0;i<verticalCuts.size() - 1;i++){
            width = max(width, verticalCuts[i+1] - verticalCuts[i]);
            width %= MOD;
        }
        ans = (long long) width * height;
        ans %= MOD;
        return (int) ans;
    }
};
