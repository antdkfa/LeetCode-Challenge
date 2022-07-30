class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int totalAppearance[30] = {};
        for(int i=0;i<words2.size();i++) {
            string now = words2[i];
            int nowAppearance[30] = {};
            for(int j=0;j<now.length();j++) {
                nowAppearance[now[j] - 'a']++;
            }
            for(int j=0;j<26;j++) {
                totalAppearance[j] = max(totalAppearance[j], nowAppearance[j]);
            }
        }
        
        vector<string> ans;
        for(int i=0;i<words1.size();i++) {
            string now = words1[i];
            int nowAppearance[30] = {};
            for(int j=0;j<now.length();j++) {
                nowAppearance[now[j] - 'a']++;
            }
            
            bool flag = true;
            for(int j=0;j<26;j++) {
                if(totalAppearance[j] > nowAppearance[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(now);
        }
        
        return ans;
    }
};
