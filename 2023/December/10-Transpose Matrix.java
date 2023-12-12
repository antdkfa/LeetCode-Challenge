class Solution {
    public int[][] transpose(int[][] matrix) {
        int[][] ans = new int[matrix[0].length][matrix.length];
        int k = 0;
        for(int i=0;i<matrix.length;i++) {
            for(int j =0;j<matrix[0].length;j++) {
                ans[k%matrix[0].length][k/matrix[0].length] = matrix[i][j];
                k++;
            }
        }
        return ans;
    }
}
