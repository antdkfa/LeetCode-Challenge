class Solution {
public:
    int countVowelPermutation(int n) {
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        int mod = 1e9 + 7;
        for(int k=0;k<n - 1;k++) {
            int nextA = 0, nextE = 0, nextI = 0, nextO = 0, nextU = 0;
            nextE = (nextE + a) % mod;
            nextA = (nextA + e) % mod;
            nextI = (nextI + e) % mod;
            nextA = (nextA + i) % mod;
            nextE = (nextE + i) % mod;
            nextO = (nextO + i) % mod;
            nextU = (nextU + i) % mod;
            nextI = (nextI + o) % mod;
            nextU = (nextU + o) % mod;
            nextA = (nextA + u) % mod;
            a = nextA, e = nextE, i = nextI, o = nextO, u = nextU;
        }
        return ((((a + e) % mod + i) % mod + o) % mod + u) % mod;
    }
};
