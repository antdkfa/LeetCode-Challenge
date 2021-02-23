class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans="";
        for(int i=0;i<d.size();i++){
            for(int j=0,k=0;j<s.length();j++){
                if(d[i][k]==s[j]) k++;
                if(k==d[i].size()) {
                    if(ans.length() < d[i].length()) ans=d[i];
                    else if(ans.length() == d[i].length()) ans = min(ans,d[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
