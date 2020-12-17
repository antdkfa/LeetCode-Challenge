class Solution {
public:
    
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> m1,m2;
        vector<int>v;
        int len = A.size(), ans = 0;
        for(int i = 0;i<len;i++){
            for(int j = 0;j<len;j++){
                int now = A[i]+B[j];
                if(!m1[now]) v.push_back(now);
                m1[now]++;
                m2[C[i]+D[j]]++;
            }
        }
        for(int i=0;i<v.size();i++){
            ans += m1[v[i]] * m2[-v[i]];
        }
        return ans;
    }
};
