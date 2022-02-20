class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int pLetter[30] = {0, };
        for(int i=0;i<p.length();i++) {
            pLetter[p[i] - 'a']++;
        }
        
        int prefix[30005][30] = {0, };
        prefix[0][s[0] - 'a']++;
        for(int i=1;i<s.length();i++) {
            for(int j=0;j<30;j++) prefix[i][j] = prefix[i-1][j];
            prefix[i][s[i] - 'a']++;
        }
        
        vector<int>ans;
        for(int i=p.length()-1;i<s.length();i++) {
            bool flag = true;
            for(int j=0;j<30;j++) {
                int before = 0;
                if(p.length() <= i) before = prefix[i - p.length()][j];
                if(prefix[i][j] - before != pLetter[j]) flag = false;
            }
            if(flag) ans.push_back(i - p.length() + 1);
        }
        return ans;
    }
};
