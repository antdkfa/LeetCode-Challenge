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
    int sz = 0;
    void getLevel(TreeNode* now, int cnt){
        sz = max(sz, cnt);
        if(now->left) getLevel(now->left, cnt+1);
        if(now->right) getLevel(now->right, cnt+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        getLevel(root,0);
        ans.resize(sz+1);
        typedef pair<TreeNode*, int> Ti;
        queue<Ti> q;
        q.push({root, 0});
        while(!q.empty()){
            TreeNode* now = q.front().first;
            int depth = q.front().second;
            q.pop();
            ans[depth].push_back(now->val);
            if(now->left) q.push({now->left, depth+1});
            if(now->right) q.push({now->right, depth+1});
        }
        return ans;
    }
};
