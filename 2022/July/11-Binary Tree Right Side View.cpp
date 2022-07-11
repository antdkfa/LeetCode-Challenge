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
    vector<int> ans;
    int visited[105];
    void go(TreeNode*  now, int idx) {
        if(!now) return; 
        if(!visited[idx]) visited[idx]=1,ans.push_back(now->val);
        go(now->right, idx+1);
        go(now->left, idx+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        go(root, 0);
        return ans;
    }
};
