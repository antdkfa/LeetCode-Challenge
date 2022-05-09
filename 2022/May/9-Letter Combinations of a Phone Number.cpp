class Solution {
public:
    vector<string> ans;
    char comb[15][5] = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    
    void dfs(string now, string digits, int idx) {
        if(now.length() == digits.length()) {
            ans.push_back(now);
            return;
        }
        int number = (digits[idx] - '0');
        int end = 3;
        if(number == 7 || number == 9) end = 4;
        for(int i=0;i<end;i++) {
            string tmp = now;
            tmp += comb[number][i];
            dfs(tmp, digits, idx+1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        dfs("",digits,0);
        return ans;
    }
};
