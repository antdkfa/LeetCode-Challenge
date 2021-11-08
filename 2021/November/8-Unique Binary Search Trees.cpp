class Solution {
public:
    int dp[20][20];
    
    int trees(int low, int high) {
       if(low >= high) return 1;
        if(dp[low][high] != 0) return dp[low][high];
        int ans = 0;
        for(int root = low; root <= high; root++){
            ans += trees(low, root-1)*trees(root+1, high);
        }
         dp[low][high] = ans;
        return dp[low][high];
    }
    
    int numTrees(int n) {
         return trees(1, n);
    }
};
