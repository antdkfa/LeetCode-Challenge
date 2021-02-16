class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string>ans;
        queue<string>q;
        q.push("");
        while(!q.empty()){
            string now=q.front();
            q.pop();
            if(now.length() == S.length()) ans.push_back(now);
            else{
                string next=now;
                if('0' <= S[now.length()] && S[now.length()] <= '9'){
                    next+=S[now.length()];
                    q.push(next);
                }
                else{
                    next+=toupper(S[now.length()]);
                    q.push(next);
                    next.pop_back();
                    next+=tolower(S[now.length()]);
                    q.push(next);
                }
            }
        }
        return ans;
    }
};
