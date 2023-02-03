class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCnt = 0;
        bool capitalAfterFirst = false;

        for(int i=0;i<word.length();i++) {
            char now = word[i];
            if('A' <= now && now <= 'Z') {
                capitalCnt++;   
                if(i) capitalAfterFirst = true;
            }
        }

        if(capitalCnt == word.length() || !capitalCnt || (capitalCnt == 1 && !capitalAfterFirst)) return true;
        return false;
    }
};
