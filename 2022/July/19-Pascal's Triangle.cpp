class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int pascal[35][35] = {0,};
        pascal[1][0] = 1;
        for(int i=2;i<=numRows;i++){
            for(int j=0;j<i;j++){
                pascal[i][j] = pascal[i-1][j];
                if(j - 1 >= 0) pascal[i][j] += pascal[i-1][j-1];
            }
        }
        
        
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            vector<int> tmp;
            for(int j=0;j<i;j++) tmp.push_back(pascal[i][j]);
            ans.push_back(tmp);
        }
        return ans;
    }
};
