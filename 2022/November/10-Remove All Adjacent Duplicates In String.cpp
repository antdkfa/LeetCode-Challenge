class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char now: s) {
            if(st.empty()) st.push(now);
            else {
                if(st.top() == now) {
                    st.pop();
                } else st.push(now);
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            char now = st.top();
            st.pop();
            ans += now;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
