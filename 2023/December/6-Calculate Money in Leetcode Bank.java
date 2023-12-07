class Solution {
    public int totalMoney(int n) {
        int ans = 0;
        for(int i=1;n != 0;i++) {
            for(int j=0;j<7;j++) {
                ans += i + j;
                n--;
                if(n == 0) break;
            }
        }

        return ans;
    }
}
