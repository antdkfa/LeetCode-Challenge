class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int size=A.size();
        for(int i=0;i<size;i++)A[i]-=K;
        int l1,r1,l2,r2,ans=abs(A[size-1]-A[0]);
        for(int i=0;i<size-1;i++){
            A[i]+=K*2;
            l1=A[0],r1=A[i],l2=A[i+1],r2=A[size-1];
            int tmp = max(abs(r2-l2),max(abs(r1-l1),max(abs(r2-l1),(r1-l2))));
            ans = min(ans,tmp);
        }
        return ans;
    }
};
