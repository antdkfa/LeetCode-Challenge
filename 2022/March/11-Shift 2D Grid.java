class Solution {
    private int[][] retRotate(int[][] org, int[][] rotated) {
        for(int i=0;i<org.length;i++) {
            for(int j=0;j<org[i].length;j++) {
                if(i == org.length - 1 && j == org[0].length - 1) {
                    rotated[0][0] = org[i][j];
                } else if(j == org[0].length - 1) {
                    rotated[i+1][0] = org[i][j];
                } else {
                    rotated[i][j+1] = org[i][j];
                }
            }
        }
        return rotated;
    }
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        for(int i=0;i<k;i++) {
            int[][] rotated = new int[grid.length][grid[0].length];
            rotated = retRotate(grid, rotated);
            grid = rotated;
        }
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=0;i<grid.length;i++) {
            List<Integer> tmp = new ArrayList<>();
            for(int j=0;j<grid[0].length;j++) {
                tmp.add(grid[i][j]);
            }
            ans.add(tmp);
        }
        return ans;
    }
}
