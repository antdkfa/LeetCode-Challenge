/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int dp[505], level, cnt;
    
    void find_depth(TreeNode *now, int depth){
        level = max(level, depth);
        if(now->left) find_depth(now->left, depth + 1);
        if(now->right) find_depth(now->right, depth + 1);
    }
    
    int dfs(TreeNode *now, int depth){
        int &ret = dp[now->val];
        if(ret != -1) return ret;
        if(!now->left && !now->right){
            if(depth == level) {
                ret = 1;
                return ret;
            }
            else {
                ret = 0;
                return ret;     
            }
        }
        else{
            ret = 0;
            if(now->left) ret += dfs(now->left, depth + 1);
            if(now->right) ret += dfs(now->right, depth + 1);
            return ret;
        }
    }
    
    TreeNode* bfs(TreeNode *root){
        TreeNode* ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* now = q.front();
            q.pop();
            if(dp[now->val] == cnt) ans = now;
            if(now->left) q.push(now->left);
            if(now->right) q.push(now->right);
        }
        return ans;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        for(int i = 0;i<505;i++) dp[i] = -1;
        find_depth(root, 0);
        dfs(root, 0);
        for(int i = 0;i<505;i++) cnt = max(cnt, dp[i]);
        return bfs(root);
    }
};
