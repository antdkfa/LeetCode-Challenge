class Solution {
public:
    
    bool isBad(char a, char b) {
        if(a - 'A' == b - 'a' || a - 'a' == b - 'A') return true;
        return false;
    } 
        
    string makeGood(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++) {
            if(st.empty()) st.push(s[i]);
            else {
                char f = st.top();
                if(isBad(s[i], f) || isBad(f, s[i])) {
                    st.pop();
                } else st.push(s[i]);
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            char t = st.top();
            st.pop();
            ans += t;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
