class Solution {
public:
    int maxPower(string s) {
        int len = s.size();
        int a = 0, b = 0, ans = 0, now = 0;
        while(a < len && b < len){
            if(s[a] != s[b]){
                ans = max(ans, now);
                a = b;
                now  = 0;
            }
            else{
                now++;
                ans = max(ans, now);
                b++;
            }
        }
        return ans;
    }
};
