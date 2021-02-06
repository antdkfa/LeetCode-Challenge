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
    int visited[100005];
    vector<int> ans;
    void dfs(TreeNode* now, int depth) {
        if(!visited[depth]) visited[depth]=1,ans.push_back(now->val);
        if(now->right) dfs(now->right,depth+1);
        if(now->left) dfs(now->left,depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return ans;
        dfs(root, 0);
        return ans;
    }
};
