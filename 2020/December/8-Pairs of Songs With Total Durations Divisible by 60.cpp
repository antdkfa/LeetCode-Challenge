class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int m[65] = {0, }, ans = 0;
        for(int i = 0;i<time.size();i++) m[60 - time[i] % 60]++;
        for(int i = 1;i<30;i++) ans += m[i] * m[60 - i];
        ans += m[60] * (m[60] - 1) / 2;
        ans += m[30] * (m[30] - 1) / 2;
        return ans;
    }
};
