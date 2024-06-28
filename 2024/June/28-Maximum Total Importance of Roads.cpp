class Solution {
public:
    int cnt[50005];
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        for(int i=0;i<roads.size();i++) {
            cnt[roads[i][0]]++;
            cnt[roads[i][1]]++;
        }

        long long ans = 0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++) pq.push(cnt[i]);
        while(!pq.empty()) {
            int now = pq.top();
            pq.pop();
            ans += (long long)now * n;
            n--;
        }

        return ans;
    }
};
