class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char>st;
        string ans = "";
        for(int i=0;i<s.length();i++) {
            if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) {
                ans += ' ';
                st.push(s[i]);
            } else {
                ans += s[i];
            }
        }
        for(int i=0;i<ans.length();i++) {
            if(ans[i] == ' ') {
                ans[i] = st.top();
                st.pop();
            }
        }
        return ans;
    }
};
