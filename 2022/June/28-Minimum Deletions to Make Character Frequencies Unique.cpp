class Solution {
public:
    int minDeletions(string s) {
        int cnt[30] = {0,};
        for(int i=0;i<s.length();i++) {
            cnt[s[i] - 'a']++;
        }
        
        priority_queue<int> pq;
        for(int i=0;i<26;i++) {
            if(cnt[i]) pq.push(cnt[i]);
        }
        
        int ans = 0;
        while(!pq.empty()) {
            int now = pq.top();
            if(!now) break;
            pq.pop();
            while(!pq.empty()) {
                int next = pq.top();
                if(next == now) {
                    ans++;
                    pq.pop();
                    pq.push(next-1);
                }
                else break;
            }
        }
        return ans;
    }
};
