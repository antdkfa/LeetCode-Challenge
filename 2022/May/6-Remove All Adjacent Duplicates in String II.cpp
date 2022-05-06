class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.length();i++) {
            if(!st.empty()) {
                char now = st.top().first;
                if(now == s[i]) {
                    int cnt = st.top().second;
                    st.pop();
                    if(cnt + 1 != k) st.push({now, cnt+1});
                } else st.push({s[i], 1});
            } else st.push({s[i], 1});
        }
        
        string ans = "";
        while(!st.empty()) {
            char now = st.top().first;
            int cnt = st.top().second;
            for(int i=0;i<cnt;i++) ans+=now;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
