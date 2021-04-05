class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int mini[5005] = {0};
        mini[A.size()] = 1e9;
        for(int i=A.size() - 1;i>=0;i--){
            mini[i] = min(mini[i+1], A[i]);
        }
        for(int i=0;i<A.size();i++){
            int j = i + 2;
            if(j >= A.size()) break;
            if(A[i] > mini[j]) return false;
        }
        return true;
    }
};
