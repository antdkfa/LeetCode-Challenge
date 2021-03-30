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
    int cnt, idx;
    vector<int> my_preorder, ans;
    
    void go(TreeNode* now, vector<int> voyage){
        my_preorder.push_back(now->val);
        idx++;
        if(now->left && now->right){
            if(voyage[idx] != now->left->val) {
                go(now->right, voyage);
                go(now->left,voyage);
                ans.push_back(now->val);
            }
            else {
                go(now->left,voyage);
                go(now->right, voyage);
            }
        }
        else {
            if(now->left) {
                go(now->left,voyage);
            }
            if(now->right){
                go(now->right,voyage);
            }
        }
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(root->val != voyage[0]){
            ans.push_back(-1);
            return ans;
        }
        go(root, voyage);
        for(int i=0;i<voyage.size();i++) if(voyage[i] != my_preorder[i]) { ans.clear(); ans.push_back(-1); return ans; }
        return ans;
    }
};
