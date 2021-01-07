class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        int l = 0, r = 0, ans=0;
        map<char,int> last_idx;
        while(r<=s.length()){
            if(r==s.length()) {ans=max(ans,r-l);break;}
            if(!last_idx[s[r]]){
                ans=max(ans,r-l+1);
                last_idx[s[r++]]++;
            }
            else{
                last_idx[s[l++]]=0;
            }
        }
        return ans;
    }
};
