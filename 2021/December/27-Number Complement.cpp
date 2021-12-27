class Solution {
public:
    int findComplement(int num) {
        int ans = 0, flag = 0;;
        for(int i=30;i>=0;i--) {
            int now = num &(1 << i);
            if(now) flag = 1;
            if(!now && flag) ans += 1<<i;
        }
        
        return ans;
    }
};
