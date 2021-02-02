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
    TreeNode* dfs(TreeNode* root,int& low,int& high){
        if(root==NULL)
            return NULL;
        if(root->val < low){
            root=root->right;
            return dfs(root,low,high);
        }            
        if(root->val > high){
            root = root->left;
            return dfs(root,low,high);
        }    
        //verify left
        if(root->left){
            root->left=dfs(root->left,low,high);
        }
        //verify right
        if(root->right){
            root->right = dfs(root->right,low,high);
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return dfs(root,low,high);
    }
};
