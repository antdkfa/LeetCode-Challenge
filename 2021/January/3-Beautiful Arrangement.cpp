class Solution {
public: 
    int ans = 0, visited[20];
    
    void dfs(int depth, int n) {
        if(depth == 1) {
            ans++;
            return;
        }
        for(int i = n;i>=1;i--) {
            if(!visited[i] && (!(i % depth) || !(depth % i))) {
                visited[i] = 1;
                dfs(depth - 1, n);
                visited[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        dfs(n,n);
        return ans;
    }
};
