class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        int n = s.length();
        stack<char> st;
        for(int i = 0;i<n;i++){
            if(s[i] == ']'){
                string tmp = "";
                while(1){
                    char now = st.top();
                    st.pop();
                    if('0' <= now && now <= '9'){
                        string t = "";
                        t += now;
                        while(!st.empty() && ('0' <= st.top() && st.top() <= '9')) {
                            t += st.top();
                            st.pop();        
                        }
                        reverse(t.begin(), t.end());
                        reverse(tmp.begin(), tmp.end());
                        for(int i = 0; i < stoi(t); i++) {
                            for(int j = 0;j<tmp.length();j++){
                                st.push(tmp[j]);
                            }
                        }
                        break;
                    }
                    else if(now == '[') continue;
                    else {
                        tmp+=now;
                    }
                }
            }
            else st.push(s[i]);
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
