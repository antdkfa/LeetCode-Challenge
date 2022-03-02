class Solution {
    private int toBinary(int num) {
        int cnt = 0;
        while(num != 0) {
            if(num % 2 == 1) cnt++;
            num/=2;
        }
        return cnt;
    }
    
    public int[] countBits(int n) {
        int[] ans = new int[n+1];
        for(int i=0;i<=n;i++) {
            ans[i] = toBinary(i);
        }
        return ans;
    }
}
