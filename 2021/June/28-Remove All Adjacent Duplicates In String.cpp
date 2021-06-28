class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>ans;
        char nowDel = '!';
        for(int i=0;i<s.length();i++){
            if(!ans.empty()){
                if(ans.top() == s[i]) {
                    ans.pop();
                }
                else {
                    ans.push(s[i]);
                } 
            }
            else {
                ans.push(s[i]);
            }
        }
        string reversed = "";
        while(!ans.empty()) {
            char now = ans.top();
            ans.pop();
            reversed += now;
        }
        reverse(reversed.begin(), reversed.end());
        return reversed;
    }
};
