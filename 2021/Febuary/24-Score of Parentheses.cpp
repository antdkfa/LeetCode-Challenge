class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int>st;
        int ans=0;
        for(int i=0;i<S.length();i++){
            if(S[i]==')') {
                int tmp=0;
                while(!st.empty()){
                    int now=st.top();
                    st.pop();
                    if(now==-1){
                        if(!tmp) tmp=1;
                        else tmp*=2;
                        break;
                    }
                    else {
                        tmp+=now;
                    }
                }
                st.push(tmp);
            }
            else st.push(-1);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
