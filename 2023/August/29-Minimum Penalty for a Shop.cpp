class Solution {
public:
    int bestClosingTime(string customers) {
        int dp[100005] = {};
        for(int i=customers.length()-1;i>=0;i--) {
            dp[i] = dp[i+1] + (customers[i] == 'Y' ? 1 : 0);
        }

        int ansIdx = 1e9, minPenulty = 1e9, front = 0;
        for(int i=0;i<=customers.length();i++) {
            if(front + (customers[i] == 'Y' ? 1 : 0) + dp[i+1] < minPenulty) {
                minPenulty = front + dp[i+1] + (customers[i] == 'Y' ? 1 : 0);
                ansIdx = i;
            }
            if(customers[i] == 'N') front++;
        }
        
        return ansIdx;
    }
};
