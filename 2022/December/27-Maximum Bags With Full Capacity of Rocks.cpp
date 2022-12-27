class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        priority_queue<int> pq;
        for(int i=0;i<capacity.size();i++) {
            pq.push(-(capacity[i] - rocks[i]));
        }

        int ans = 0;
        while(!pq.empty()) {
            int top = -pq.top();
            pq.pop();
            additionalRocks -= top;
            if(additionalRocks >= 0) ans++;
            else break;    
        }

        return ans;
    }
};
