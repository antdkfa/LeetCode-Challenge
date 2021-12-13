class Solution {
public:
    int maxPower(string s) {
        int ans = 1, sum = 1;
        for(int i =0;i<s.length() - 1;i++) {
            if(s[i] == s[i+1]) {
                sum++;
                ans = max(ans, sum);
            } else sum = 1;
        }
        
        return ans;
    }
};
