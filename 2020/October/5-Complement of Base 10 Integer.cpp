class Solution {
public:
    int bitwiseComplement(int N) {
        if(!N) return 1;
        int ans = 0;
        stack<int> s;
        while(N != 0){  
            s.push(N%2);
            N/=2;
        }
        while(!s.empty()){
            int now = s.top();
            if(!now) ans += pow(2, s.size() - 1);
            s.pop();
        }
        return ans;
    }
};
