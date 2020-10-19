class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if(A.size() == 0 || A.size() == 1) return 0;
        int sum[10] = {0,};
        for(int i = 0;i<A.size();i++){
            if(A[i] == B[i]) sum[A[i]] += i + 1;
            else{
                sum[B[i]] += i + 1;
                sum[A[i]] += i + 1;
            }
        }
        for(int i =0;i<=6;i++){
            if(sum[i] == (A.size() + 1) * A.size() / 2){
                int ans = 0, tmp = 0;
                for(int j = 0;j<A.size();j++){
                    if(A[j] != i) tmp++;
                }
                ans = tmp, tmp = 0;
                for(int j = 0;j<A.size();j++){
                    if(B[j] != i) tmp++;
                }
                ans = min(ans, tmp);
                return ans;
            }
        }
        return -1;
    }
};
