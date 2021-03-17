class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() < 2) return 0;
        int sold = 0, hold = 0 - prices[0];
        for (int i = 1; i < prices.size(); i++) {
            hold = max(hold, sold - prices[i]);
            sold = max(sold, hold + prices[i] - fee);
        }
        return sold;
    }
};
