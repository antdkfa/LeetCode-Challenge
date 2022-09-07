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
    string ans="";
    void dfs(TreeNode*now) {
        ans+=to_string(now->val);
        if(now->left) {
            ans+='(';
            dfs(now->left);
            ans+=')';
        }
        if(now->right) {
            if(!(now->left)) {
                ans+='(';
                ans+=')';
            } 
            ans+='(';
            dfs(now->right);
            ans+=')';
        }
    }
    string tree2str(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
