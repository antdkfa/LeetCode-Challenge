class Solution {
    public int[][] transpose(int[][] matrix) {
        int[][] ans = new int[matrix[0].length][matrix.length];
        int idx = 0;
        for(int i=0;i<ans.length;i++) {
            for(int j=0;j<ans[i].length;j++) {
                ans[i][j] = matrix[idx % matrix.length][idx/matrix.length];
                idx++;
            }
        }
        
        return ans;
    }
}
