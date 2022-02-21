class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int need[65] = {0, };
        for(int i=0;i<time.size();i++) {
            need[time[i] % 60]++;
        }
        
        int ans = 0;
        if(need[0] && need[0]%2) ans += (need[0] * ((need[0] - 1)/2));
        else ans += need[0]/2 * (need[0] - 1);
        for(int i=1;i<30;i++) {
            ans += need[i] * need[60-i];
        }
        
        if(need[30] && need[30]%2) ans += (need[30] * ((need[30] - 1)/2));
        else ans += need[30]/2 * (need[30] - 1);
        return ans;
    }
};
