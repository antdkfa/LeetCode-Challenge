class Solution {
public:
    int countPrimes(int n) {
        int prime[5000005] = {0, }, ans = 0;
        for(int i=2;i*i<5000005;i++){
            if(i>=n) break;
            for(int j=i*i;j<5000005;j+=i) {
                prime[j] = 1;
                if(j>=n) break;
            }    
        }
        for(int i=2;i<=5000000;i++) {
            if(i>=n) break;
            if(!prime[i] && i<n) ans++;
        }
        return ans;
    }
};
