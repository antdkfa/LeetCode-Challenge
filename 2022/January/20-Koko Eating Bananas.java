class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int s = 1, e = 1000000000, ans = 1000000000;
        while(s <= e) {
            int mid = (s + e) / 2;
            int cnt = 0;
            for(int i=0;i<piles.length;i++) {
                cnt += piles[i] / mid + ((piles[i] % mid == 0) ? 0 : 1); 
            }
            if(cnt <= h) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
}
