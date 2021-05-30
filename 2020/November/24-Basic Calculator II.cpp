class Solution {
public:
    int calculate(string s) {
        stack<string> c;
        string now = "";
        int ans = 0, op = 1;
        for(int i = 0;i<s.length();i++){
            if(s[i] == '+') {
                if(op <= 2) c.push(now);
                else {
                    string a = c.top();
                    c.pop();
                    if(op == 3) c.push(to_string(stoi(a) * stoi(now)));
                    else c.push(to_string(stoi(a) / stoi(now)));
                }
                now.clear();
                op = 1;
            }
            else if(s[i] == '-') {
                if(op <= 2) c.push(now);
                else {
                    string a = c.top();
                    c.pop();
                    if(op == 3) c.push(to_string(stoi(a) * stoi(now)));
                    else c.push(to_string(stoi(a) / stoi(now)));
                }
                now.clear();
                now += '-';
                op = 2;
            }
            else if(s[i] == '*') {
                if(op <= 2) c.push(now);
                else {
                    string a = c.top();
                    c.pop();
                    if(op == 3) c.push(to_string(stoi(a) * stoi(now)));
                    else c.push(to_string(stoi(a) / stoi(now)));
                }
                now.clear();
                op = 3;
            }
            else if(s[i] == '/') {
                if(op <= 2) c.push(now);
                else {
                    string a = c.top();
                    c.pop();
                    if(op == 3) c.push(to_string(stoi(a) * stoi(now)));
                    else c.push(to_string(stoi(a) / stoi(now)));
                }
                now.clear();
                op = 4;
            }
            else {
                if(s[i] != ' ') now += s[i];
            }
            if(i == s.length() - 1){
                if(op <= 2) c.push(now);
                else {
                    string a = c.top();
                    c.pop();
                    if(op == 3) c.push(to_string(stoi(a) * stoi(now)));
                    else c.push(to_string(stoi(a) / stoi(now)));
                }
            }
        }
        while(!c.empty()){
            string a = c.top();
            c.pop();
            ans += stoi(a);
        }
        return ans;
    }
};
