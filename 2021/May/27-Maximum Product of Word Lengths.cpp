class Solution {
public:
    int maxProduct(vector<string>& words) {
        int usedLetters[1005][30] = {0, }, ans = 0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                usedLetters[i][words[i][j] - 'a'] = 1;
            }
        }
        
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                bool flag = true;
                for(int k=0;k<=26;k++){
                    if(usedLetters[i][k] && usedLetters[j][k]) {flag = false; break;}
                }
                if(flag) ans = max(ans, int(words[i].length() * words[j].length()));
            }
        }
        return ans;
    }
};
