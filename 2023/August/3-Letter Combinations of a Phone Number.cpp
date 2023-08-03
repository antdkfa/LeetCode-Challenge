class Solution {
public:
    vector<string> ans;
    string mapper[10] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void go(int depth, string digits, string now) {

        if(depth == digits.length()) {
            ans.push_back(now);
            return;
        }
        
        for(int i=0;i<mapper[digits[depth]-'2'].length();i++) {
            string tmp = now;
            tmp += mapper[digits[depth]-'2'][i];
            go(depth+1,digits,tmp);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == "") return ans;
        go(0,digits,"");
        return ans;
    }
};
