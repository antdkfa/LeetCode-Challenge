class Solution {
public:
    typedef pair<int,int> p;
    typedef pair<int,p> ip;
    int uf[1005];
    priority_queue<ip> pq;
    
    int find(int now) {
        if(uf[now] == now) return now;
        return find(uf[now]);
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        uf[a] = b;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        for(int i=0;i<1005;i++) uf[i] = i;
        for(int i=0;i<points.size();i++) {
            for(int j=i+1;j<points.size();j++) {
                pq.push({-(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])),{i,j}});
            }
        }
        
        int ans = 0;
        while(!pq.empty()) {
            ip now = pq.top();
            pq.pop();
            int pos1 = now.second.first, pos2 = now.second.second;
            if(find(pos1) == find(pos2)) continue;
            ans += -now.first;
            merge(pos1, pos2);
        }
        
        return ans;
    }
};
