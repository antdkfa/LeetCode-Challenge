class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<boxTypes.size();i++) {
            pq.push({boxTypes[i][1], boxTypes[i][0]});
        }

        int ans = 0;
        while(!pq.empty() && truckSize) {
            pair<int,int> now = pq.top();
            pq.pop();
            ans += now.first * min(truckSize, now.second);
            truckSize -= min(truckSize, now.second);
        }
        
        return ans;
    }
};
