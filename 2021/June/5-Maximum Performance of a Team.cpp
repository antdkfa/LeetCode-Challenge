class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long ans = 0;
        #define MOD 1000000007
        
        typedef pair<int,int> p;
        p es[100005];
        for(int i=0;i<n;i++) es[i] = {efficiency[i], speed[i]};
        sort(es, es + n);
        
        long long sum = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=n-1;i>=n - k + 1;i--){
            pq.push(es[i].second);
            sum += es[i].second;
            ans = max(ans,(long long) es[i].first * sum);
        }
        
        for(int i=n-k;i>=0;i--){
            pq.push(es[i].second);
            sum += es[i].second;
            while(pq.size() > k) {
                int now  = pq.top();
                pq.pop();
                sum -= now;
            }
            ans = max(ans,(long long) es[i].first * sum);
        }
        ans %= MOD;
        return (int) ans;
    }
};
