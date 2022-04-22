class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int ans = 0, mod = 1000000007, dp[3005][305] = { 0, };
        for(int i=arr.size() - 1;i>=0;i--){
            dp[i][arr[i]]++;
            for(int j=0;j<=300;j++){
                dp[i][j] += dp[i + 1][j];
            }
        }
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(target - arr[i] - arr[j] >= 0) {
                    ans += dp[j + 1][target - arr[i] - arr[j]] % mod;
                    ans %= mod;
                }
            }
        }
        return ans;
    }
};
