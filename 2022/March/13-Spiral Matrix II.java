class Solution {
    public int[][] generateMatrix(int n) {
        int[] fr = {0,1,0,-1};
        int[] fc = {1,0,-1,0};
        int[][] ans = new int[n][n];
        int now = 1;
        int r = 0;
        int c = 0;
        int dir = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                ans[r][c] = now++;
                int nr = r + fr[dir];
                int nc = c + fc[dir];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n || ans[nr][nc] != 0) {
                    dir = (dir + 1) % 4;
                    nr = r + fr[dir];
                    nc = c + fc[dir];
                }
                r = nr;
                c = nc;
            }
        }
        return ans;
    }
}
