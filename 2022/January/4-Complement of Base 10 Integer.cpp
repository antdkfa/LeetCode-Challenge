class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n) return 1;
        int ans = 0, first = 0;
        for(int i=30;i>=0;i--) {
            if(n & (1 << i)) {
                first = 1;
            }
            else {
                if(first) ans += 1<<i;
            }
        }
        return ans;
    }
};
