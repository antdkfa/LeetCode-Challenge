class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int pascal[35][35] = {0, };
        vector<int> ans;
        for(int i=0;i<=rowIndex;i++) {
            for(int j=0;j<=i;j++) {
                if(!j || j == i) pascal[i][j] = 1;
                else {
                    pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
                }
            }
        }
        for(int i=0;i<=rowIndex;i++) ans.push_back(pascal[rowIndex][i]);
        return ans;
    }
};
