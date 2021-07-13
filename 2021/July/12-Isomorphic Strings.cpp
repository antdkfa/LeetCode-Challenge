class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,int> visitedS, visitedT;
        int aS[50005] = {0, }, aT[50005] = {0, }, idxS = 1, idxT = 1;
        for(int i=0;i<s.length();i++) {
            if(!visitedS[s[i] - 'a']) {
                visitedS[s[i] - 'a'] = idxS++;
            }
            if(!visitedT[t[i] - 'a']) {
                visitedT[t[i] - 'a'] = idxT++;
            }
            aS[i] = visitedS[s[i] - 'a'];
            aT[i] = visitedT[t[i] - 'a'];
        }
        
        for(int i=0;i<s.length();i++) {
            if(aS[i] != aT[i]) return false;
        }
        return true;
    }
};
