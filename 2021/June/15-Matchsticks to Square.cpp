class Solution {
public:
    long long sum = 0, mx = 0, x = 0;
    int n;
    bool ans = false;
    
    static int cmp(int a, int b) {
        return a > b;
    }
    
    void dfs(int depth, long long a, long long b, long long c, long long d, vector<int>& matchsticks) {
        if(depth == n || ans) {
            if(a == b  && b == c  && c == d && a == x) ans = true;
            return;
        }
        if(a + (long long)matchsticks[depth] <= x) {
            dfs(depth + 1, a + (long long)matchsticks[depth], b, c, d, matchsticks);
        }
        if(b + (long long)matchsticks[depth] <= x) {
            dfs(depth + 1, a, b + (long long)matchsticks[depth], c, d, matchsticks);
        }
        if(c + (long long)matchsticks[depth] <= x) {
            dfs(depth + 1, a, b, c + (long long)matchsticks[depth], d, matchsticks);
        }
        if(d + (long long)matchsticks[depth] <= x) {
            dfs(depth + 1, a, b, c, d + (long long)matchsticks[depth], matchsticks);
        }
    }
    
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4) return false; 
        
        for(int i=0;i<matchsticks.size();i++) sum += (long long) matchsticks[i], mx = max((int)mx,                        matchsticks[i]);
        if(sum % (long long)4) return false;
        if(sum/(long long)4 < mx) return false;
        
        x = sum / (long long)4;
        n = matchsticks.size();
        sort(matchsticks.begin(), matchsticks.end(), cmp);
        
        dfs(0,0,0,0,0,matchsticks);
        return ans;
    }
};
