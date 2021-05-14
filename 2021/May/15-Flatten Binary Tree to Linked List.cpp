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
    TreeNode* getLastNodeOfLeftSub(TreeNode* now){
        if(now->right) return getLastNodeOfLeftSub(now->right);
        else if(now->left) return getLastNodeOfLeftSub(now->left);
        else return now;
    }
    
    void go(TreeNode* now){
        if(now->right && now->left == nullptr){
            go(now->right);
        }
        else if(now->left && now->right == nullptr){
            now->right = now->left;
            now->left = nullptr;
            go(now->right);
        }
        else if(now->left && now->right){
            TreeNode* tmp = now->right;
            go(now->left);
            TreeNode* Last = getLastNodeOfLeftSub(now->left);
            now->right = now->left;
            now->left = nullptr;
            Last->right = tmp;
            go(Last->right);
        }
        else return; 
    }
    
    void flatten(TreeNode* root) {
        if(root) go(root);
    }
};
