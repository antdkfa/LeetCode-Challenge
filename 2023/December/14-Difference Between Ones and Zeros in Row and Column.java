class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[] oneRow = new int[n];
        int[] oneCol = new int[m];
        for(int i=0;i<n;i++) {
            int cnt = 0;
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) cnt++;
            }
            oneRow[i] = cnt;
        }

        for(int i=0;i<m;i++) {
            int cnt = 0;
            for(int j=0;j<n;j++) {
                if(grid[j][i] == 1) cnt++;
            }
            oneCol[i] = cnt;
        }

        int[][] ans = new int[n][m];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans[i][j] = oneRow[i] + oneCol[j] - (n-oneRow[i]) - (m-oneCol[j]);
            }
        }

        return ans;
    }
}
