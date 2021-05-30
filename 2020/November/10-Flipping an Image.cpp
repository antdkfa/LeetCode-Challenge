class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m/2;j++){
                swap(A[i][j], A[i][m - 1 - j]);
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                A[i][j] = A[i][j] ? 0 : 1;
            }
        }
        return A;
    }
};
