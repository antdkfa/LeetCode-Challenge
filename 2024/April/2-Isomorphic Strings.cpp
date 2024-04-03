class Solution {
public:

    string stringToNumber(string s) {
        map<char,int> m;
        int cnt = 1;
        string number;
        for(int i=0;i<s.length();i++) {
            if(!m[s[i]]) {
                m[s[i]] = cnt;
                number += cnt;
                cnt++;
            } else {
                number += m[s[i]];
            }
        }

        return number;
    }

    bool isIsomorphic(string s, string t) {
        return stringToNumber(s) == stringToNumber(t);
    }
};
