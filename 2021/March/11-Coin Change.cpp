class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans[10005] = {0, };
        for(int i=1;i<10005;i++)ans[i]=1e9;
        sort(coins.begin(),coins.end());
        for(int i=0;i<coins.size();i++){
            if(coins[i] > amount) break;
            for(int j = 1;j<=amount;j++) {
                if(j-coins[i] >= 0) {
                    ans[j] = min(ans[j], ans[j-coins[i]] + 1);
                }
            }
        }
        return ans[amount] >= 1e9 ? -1 : ans[amount];
    }
};
