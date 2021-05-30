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
    int dfs(TreeNode *now){
        if(now->left == NULL && now->right){
            int a = dfs(now->right);
            now->val += a;
        } 
        else if(now->right == NULL && now->left){
            int a = dfs(now->left);
            now->val += a;
        }
        else if(now->right && now->left){
            int a = dfs(now->left) + dfs(now->right);
            now->val += a;
        }
        return now->val;
    }
    
    int findTilt(TreeNode* root) {
        if(root == NULL) return 0;
        dfs(root);
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* now = q.front();
            q.pop();
            int left = 0, right = 0;
            if(now->left) left = now->left->val, q.push(now->left);
            if(now->right) right = now->right->val, q.push(now->right);
            ans+= abs(left - right);
            
        }
        return ans;
    }
};
