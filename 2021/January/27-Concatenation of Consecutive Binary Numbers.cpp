class Solution {
public:
    int concatenatedBinary(int n) {
        string s="";
        int ans=0, mod=1000000007;
        for(int i=1;i<=n;i++){
            string tmp="";
            int now=i;
            while(now){
                tmp+=now%2+'0';
                now/=2;
            }
            reverse(tmp.begin(),tmp.end());
            s+=tmp;
        }
        int now=1;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1'){
                ans+=now;
                ans%=mod;
            } 
            now*=2;
            now%=mod;
        }
        return ans;
    }
};
