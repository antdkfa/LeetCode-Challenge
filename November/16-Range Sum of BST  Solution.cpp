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
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> q;
        int ans = 0;
        q.push(root);
        while(!q.empty()){
            TreeNode *now = q.front();
            q.pop();
            if(low <= now->val && now->val <= high) ans += now->val;
            if(now->left) q.push(now->left);
            if(now->right) q.push(now->right);
        }
        return ans;
    }
};
