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
    vector<int> v;    
    int depth = 0;
    void dfs(TreeNode * now){
        v.push_back(now->val);
        if(now->left) dfs(now->left);
        if(now->right) dfs(now->right);
    }
    
    void make_tree(TreeNode * now){
        if(now->left) make_tree(now->left);
        now->val = v[depth++];
        if(now->right) make_tree(now->right);
    }
    
    void recoverTree(TreeNode* root) {
        dfs(root);
        sort(v.begin(), v.end());
        make_tree(root);
    }
};
