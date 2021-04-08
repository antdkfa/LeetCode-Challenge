class Solution {
public:
    
    vector<string> ans;
    int digits_len;
    string letter[15] = { "", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void go(string now, int depth, string digits) {
        if(depth == digits_len) {
            ans.push_back(now);
            return;
        }
        for(int i=0;i<letter[digits[depth] - '0'].length();i++){
            go(now+letter[digits[depth]-'0'][i], depth+1,digits);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(!digits.length()) return ans;
        digits_len = digits.length();
        go("",0,digits);
        return ans;
    }
};
