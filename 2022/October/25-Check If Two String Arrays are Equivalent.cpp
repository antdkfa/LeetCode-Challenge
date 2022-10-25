class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string f="", s="";
        for(int i=0;i<word1.size();i++) {
            f += word1[i];
        }
        for(int i=0;i<word2.size();i++) {
            s += word2[i];
        }
        return f == s;
    }
};
