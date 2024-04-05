class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++) {
            if(!st.empty() && (st.top() + 32 == s[i] || st.top() - 32 == s[i])) {
                st.pop();
            } else st.push(s[i]);
        }

        string ans = "";
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
