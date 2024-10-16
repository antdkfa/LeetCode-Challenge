class Solution {
public:
    typedef pair<int,int> p; 
    string longestDiverseString(int a, int b, int c) {
        priority_queue<p> pq;
        if(a> 0) pq.push({a, 0});
        if(b> 0) pq.push({b, 1});
        if(c> 0) pq.push({c, 2});

        string ans = "";
        int row[3] = {};
        while(!pq.empty()) {
            int cnt = pq.top().first, idx = pq.top().second;
            pq.pop();
            cnt--;
            ans += 'a' + idx;
            row[idx]++;
            if(row[idx] == 2) {
                if(!pq.empty()) {
                    int nCnt = pq.top().first, nIdx = pq.top().second;
                    pq.pop();
                    nCnt--;
                    ans += 'a' + nIdx;
                    row[nIdx]++;
                    row[idx] = 0;
                    if(nCnt > 0) pq.push({nCnt,nIdx});
                } else {
                    break;
                }
            }
            if(cnt > 0) pq.push({cnt,idx});

        }
        return ans;
    }
};
