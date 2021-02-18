class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3) return 0;
        int ans=0,s=0,e=1,dif=A[e]-A[e-1];
        A.push_back(-1e9);
        while(s<A.size()&&e<A.size()){
            if(A[e]-A[e-1]==dif){
                e++;
            }
            else{
                if(e-s>=3)ans+=(e-s-2)*(e-s-1)/2;
                s=e-1;
                e=s+1;
                if(e<A.size())dif=A[e]-A[e-1];
            }
        }
        return ans;
    }
};
