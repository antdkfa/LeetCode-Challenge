class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;
        int w1[30]={0,},w2[30]={0,};
        for(int i=0;i<word1.size();i++){
            w1[word1[i]-'a']++;
            w2[word2[i]-'a']++;
        }   
        vector<int>v1,v2;
        for(int i=0;i<30;i++){
            if((w1[i]&&!w2[i])||(!w1[i]&&w2[i])) return false;
            if(w1[i])v1.push_back(w1[i]);
            if(w2[i])v2.push_back(w2[i]);
        }
        sort(v1.begin(),v1.end()), sort(v2.begin(),v2.end());
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i])return false;
        }
        return true;
    }
};
