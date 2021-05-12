class NumMatrix {
private :
    int sum[205][205] = {0,}, n, m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                sum[i][j] = matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i=row1;i<=row2;i++){
            for(int j=col1;j<=col2;j++){
                ans += sum[i][j];   
            }
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
