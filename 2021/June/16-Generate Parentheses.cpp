class Solution {
public:
    vector<string> ans;
    
    void go(int depth, int n, string now) {
        if(depth == n) {
            int val = 0;
            for(int i=0;i<n;i++){
                if(now[i] == ')') val--;
                else val++;
                if(val < 0) return;
            }
            if(val) return;
            ans.push_back(now);
            return;
        }
        go(depth+1, n, now + "(");
        go(depth+1, n, now + ")");
    }
    
    vector<string> generateParenthesis(int n) {
        go(0,n*2, "");
        return ans;
    }
};
