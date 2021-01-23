class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        priority_queue<int>pq;
        for(int i=0;i<m;i++){
            int r=0,c=i;
            while(r<n&&c<m){
                pq.push(-mat[r++][c++]);
            }
            r=0,c=i;
            while(r<n&&c<m){
                mat[r++][c++]=-pq.top();
                pq.pop();
            }
        }
        for(int i=1;i<n;i++){
            int r=i,c=0;
            while(r<n&&c<m){
                pq.push(-mat[r++][c++]);
            }
            r=i,c=0;
            while(r<n&&c<m){
                mat[r++][c++]=-pq.top();
                pq.pop();
            }
        }
        return mat;
    }
};
