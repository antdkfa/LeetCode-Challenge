class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, cnt = 0;
        s+=' ';
        for(int i=0;i<s.length();i++) {
            if(s[i] == ' ') {
                if(cnt) ans = cnt;
                cnt = 0;
            } else cnt++;
        }

        return ans;
    }
};
