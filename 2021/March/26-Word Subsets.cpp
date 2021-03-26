class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        int used[30] = {0, };
        for(int i=0;i<B.size();i++){
            int tmp[30] = {0, };
            for(int j=0;j<B[i].length();j++) tmp[B[i][j]-'a']++;
            for(int j=0;j<30;j++) used[j]=max(used[j],tmp[j]);
        }
        for(int i=0;i<A.size();i++){
            int tmp[30] = {0, };
            for(int j=0;j<A[i].length();j++) tmp[A[i][j]-'a']++;
            for(int j=0;j<30;j++) {
                if(used[j]>tmp[j]) break;
                if(j == 29) ans.push_back(A[i]);
            }
        }
        return ans;
    }
};
