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
    vector<int> in;
    stack<int> pre;
    TreeNode* go(int l, int r){
        if(l > r) return nullptr;
        TreeNode* now = new TreeNode();
        for(int i=l;i<=r;i++){
            if(in[i] == pre.top()){
                now->val = pre.top();
                pre.pop();
                now->left = go(l, i-1);
                now->right = go(i+1,r);
                break;
            }
        }
        return now;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<preorder.size();i++) 
            pre.push(preorder[preorder.size() - i - 1]), in.push_back(inorder[i]);
        TreeNode* ans = go(0, preorder.size() - 1);
        return ans;
    }
};
