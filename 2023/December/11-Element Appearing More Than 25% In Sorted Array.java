class Solution {
    public int findSpecialInteger(int[] arr) {
        int[] cnt = new int[100005];
        int ans = 0, mxCnt = 0;
        for(int a: arr) {
            cnt[a]++;
            if(mxCnt < cnt[a]) {
                mxCnt = cnt[a];
                ans = a;
            }
        }

        return ans;
    }
}
