class Solution {
public:
    string customSortString(string order, string str) {
        int cnt[30] = {0, };
        for(int i=0;i<str.size();i++){
            cnt[str[i] - 'a']++;
        }
        
        string ans = "";
        for(int i=0;i<order.size();i++){
            while(cnt[order[i] - 'a']){
                ans += order[i];
                cnt[order[i] - 'a']--;
            }
        }
        for(int i=0;i<26;i++) {
            while(cnt[i]) {
                ans += i + 'a';
                cnt[i]--;
            }
        }
        return ans;
    }
};
