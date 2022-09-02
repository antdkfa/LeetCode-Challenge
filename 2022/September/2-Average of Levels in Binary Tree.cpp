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
    double sum[10005],cnt[10005];
    void dfs(int level, TreeNode* now) {
        sum[level]+=now->val;
        cnt[level]++;
        if(now->left) dfs(level+1,now->left);
        if(now->right) dfs(level+1,now->right);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(0,root);
        vector<double>v;
        for(int i=0;i<10005;i++) {
            if(!cnt[i]) break;
            v.push_back(sum[i]/cnt[i]);
        }
        return v;
    }
};
