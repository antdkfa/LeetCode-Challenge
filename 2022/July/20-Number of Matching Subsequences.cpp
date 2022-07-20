class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        set<int> se[30];
        for(int i=0;i<s.length();i++) {
            se[s[i] - 'a'].insert(i);
        }
        
        int ans = 0;
        for(int i=0;i<words.size();i++) {
            int idx = -1;
            bool isSubsequence = true;
            for(int j=0;j<words[i].length();j++) {
                int now = words[i][j] - 'a';
                auto it = se[now].upper_bound(idx);
                if(it == se[now].end()) {
                    isSubsequence = false;
                    break;
                }
                idx = *it;
            }
            if(isSubsequence) ans++;
        }
        
        return ans;
    }
};
