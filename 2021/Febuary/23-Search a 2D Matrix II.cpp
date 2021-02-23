class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            int s=0,e=matrix[i].size()-1;
            while(s<=e){
                int mid=(s+e)/2;
                if(matrix[i][mid] == target) return true;
                else if(matrix[i][mid] > target) e = mid - 1;
                else s = mid + 1;
            }
        }
        return false;
    }
};
