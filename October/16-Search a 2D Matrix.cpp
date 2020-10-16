class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int n = matrix.size(), m = matrix[0].size();
        int s = 0, e = m * n - 1;
        while(s <= e){
            int mid = (s+e)/2;
            int r = mid/m, c = mid % m;
            if(matrix[r][c] > target) e = mid-1;
            else if(matrix[r][c] < target) s = mid+1;
            else return true;
        }
        return false;
    }
};
