class Solution {
public:
    int ans = 1e9;
    void dfs(int depth, vector<int>& dist, vector<int>& cookies, int k) {
        if(depth == cookies.size()) {
            int mxNow = -1e9;
            for(int i=0;i<k;i++) {
                mxNow = max(mxNow,dist[i]);
            }
            ans = min(ans, mxNow);
            return;
        }
        for(int i=0;i<k;i++) {
            dist[i]+=cookies[depth];
            dfs(depth+1, dist, cookies, k);
            dist[i]-=cookies[depth];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v;
        v.resize(k+1);
        dfs(0,v,cookies,k);
        return ans;
    }
};
