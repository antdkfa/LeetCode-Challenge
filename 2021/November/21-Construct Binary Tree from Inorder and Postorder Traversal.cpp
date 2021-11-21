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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& in_pos, int in_left, int in_right, int post_left, int post_right)
    {
        if (post_left > post_right || in_left > in_right) {
            return nullptr;
        }     
        TreeNode* root = new TreeNode(postorder[post_right]);
        // [post_left, post_right - 1]
        int root_in_pos = in_pos[root->val];
        int left_len = root_in_pos - in_left;
        root->left = build(inorder, postorder, in_pos, in_left, root_in_pos - 1, post_left, post_left + left_len - 1);
        root->right = build(inorder, postorder, in_pos, root_in_pos + 1, in_right, post_left + left_len, post_right - 1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> in_pos;
        for (int i = 0; i < inorder.size(); i++) {
            in_pos[inorder[i]] = i;
        }
        return build(inorder, postorder, in_pos, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
