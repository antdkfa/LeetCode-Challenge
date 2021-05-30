class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int dp[30] = {0,}, ans = 0;
        dp[s[0] - '0']++;
        for(int i = 1;i<s.length();i++){
            int now = s[i] - '0';
            if(!now){
                int a = dp[1], b = dp[2];
                for(int j=0;j<30;j++){
                    dp[j] = 0;
                }
                dp[10] = a;
                dp[20] = b;
            }
            else if(now < 7){
                int a = dp[1], b = dp[2], sum = 0;
                for(int j = 0;j<30;j++){
                    sum +=dp[j];
                    dp[j] = 0;
                }
                dp[10 + now] = a;
                dp[20 + now] = b;
                dp[now] = sum;
            }
            else{
                int a = dp[1], sum = 0;
                for(int j = 0;j<30;j++){
                    sum+=dp[j];
                    dp[j]=0;
                }
                dp[10+now]=a;
                dp[now]=sum;
            }
        }
        for(int i = 0;i<30;i++) ans+=dp[i];
        return ans;
    }
};
