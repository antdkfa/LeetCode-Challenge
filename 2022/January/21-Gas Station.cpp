class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumg = 0, sumc = 0, n = gas.size();
        for(int i = 0;i<n;i++) {
            sumg+=gas[i], sumc += cost[i];
        }
        if(sumg < sumc) return -1;
        int sum = 0, ans = 0;
        for(int i = 0;i<n;i++){
            sum +=gas[i] - cost[i];
            if(sum < 0) sum = 0, ans = i+1;
        }
        return ans;
    }
};
