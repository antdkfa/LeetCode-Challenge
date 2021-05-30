class Solution {
public:
    
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int>v;
        if(matrix.size() == 0) return v;
        int N = matrix.size(), M = matrix[0].size();
        if(N==1) {
            for(int i =0;i<M;i++) v.push_back(matrix[0][i]);
            return v;
        }
        if(M==1){
            for(int i = 0;i<N;i++) v.push_back(matrix[i][0]);
            return v; 
        }
        int r= 0,c=0,flag=1,cnt=0;
        while(cnt < M * N){
            v.push_back(matrix[r][c]);
            if(!r || c == M-1){
                if(!flag){
                    r+=1,c-=1;
                }
                else{
                    if(c+1 < M){
                        c+=1;
                    }
                    else{
                        r+=1;
                    }
                    flag = 0;
                }
            }
            else if(r==N-1||!c){
                if(flag) {
                    r-=1,c+=1;
                }
                else {
                    if(r+1<N){
                        r+=1;
                    }
                    else{
                        c+=1;
                    }
                    flag = 1;
                }
            }
            else{
                if(!flag) {
                    r+=1,c-=1;
                }
                else{
                    r-=1,c+=1;
                }
            }
            cnt++;
        }
        return v;
    }
};
