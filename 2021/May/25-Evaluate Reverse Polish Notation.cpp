class Solution {
public:
    stack<string>s;
    string a, b;
    void common(){
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
    }
    
    int evalRPN(vector<string>& tokens) {
        for(int i=0;i<tokens.size();i++){
            string now = tokens[i];
            if(now.length()>1 || ('0' <= now[0] && now[0] <= '9')) s.push(now);
            else{
                if(now[0] == '-'){
                    common();
                    s.push(to_string(stoi(b) - stoi(a)));
                }
                else if(now[0] == '+'){
                    common();
                    s.push(to_string(stoi(b) + stoi(a)));
                }
                else if(now[0] == '*'){
                    common();
                    s.push(to_string(stoi(b) * stoi(a)));
                }
                else {
                    common();
                    s.push(to_string(stoi(b) / stoi(a)));
                }
            }
        }
        return stoi(s.top());
    }
};
