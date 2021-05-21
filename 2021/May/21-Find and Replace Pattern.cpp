class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int used[30] = {0,}, now = 1;
        vector<int> cmp, tmp;
        for(int i=0;i<pattern.length();i++){
            if(!used[pattern[i] - 'a' + 1]){
                used[pattern[i] - 'a' + 1] = now++;
            }
            cmp.push_back(used[pattern[i] - 'a' + 1]);
        }
        for(int i=0;i<words.size();i++){
            memset(used,0,sizeof(used)), now = 1, tmp.clear();
            for(int j=0;j<words[i].length();j++){
                if(!used[words[i][j] - 'a' + 1]){
                    used[words[i][j] - 'a' + 1] = now++;
                }
                tmp.push_back(used[words[i][j] - 'a' + 1]);
            }
            for(int j=0;j<=cmp.size();j++){
                if(j == cmp.size()) {
                    ans.push_back(words[i]);
                    break;
                }
                if(tmp[j] != cmp[j]) break;
            }
        }
        return ans;
    }
};
