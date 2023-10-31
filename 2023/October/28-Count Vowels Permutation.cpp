class Solution {
public:
    int countVowelPermutation(int n) {
        int MOD = 1e9+7, vowels[5] = {1,1,1,1,1};
        for(int i=1;i<n;i++) {
            int na = ((vowels[1] + vowels[2]) % MOD + vowels[4]) % MOD;
            int ne = (vowels[0] + vowels[2]) % MOD;
            int ni = (vowels[1] + vowels[3]) % MOD;
            int no = vowels[2] % MOD;
            int nu = (vowels[2] + vowels[3]) % MOD;
            vowels[0] = na, vowels[1] = ne, vowels[2] = ni, vowels[3] = no, vowels[4] = nu;
        }

        int ans = 0;
        for(int i=0;i<5;i++) {
            ans += vowels[i];
            ans %= MOD;
        }
        return ans;
    }
};
