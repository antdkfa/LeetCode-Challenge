//Definition for a binary tree node.
/*
 struct TreeNode { 
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/
class Solution {
public:
    void rec(TreeNode *now, int val){
        if(now->val > val){
            if(now->left) rec(now->left, val);
            else {
                now->left = new TreeNode(val);
                return;   
            }
        }
        else {
            if(now->right) rec(now->right, val);
            else {
                now->right = new TreeNode(val);
                return;
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) root = new TreeNode(val);
        else rec(root, val);
        return root;
    }
};
