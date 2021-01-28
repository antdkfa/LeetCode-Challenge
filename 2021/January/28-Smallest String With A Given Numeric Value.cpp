class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=26;j++){
                if((n-i)*26>=k-j){
                    ans+=(j-1+'a'),k-=j;
                    break;
                }
            }
        }
        return ans;
    }
};
