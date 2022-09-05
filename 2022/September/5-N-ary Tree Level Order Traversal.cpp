/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>>v;
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return v;
        queue<pair<int,Node*>> q;
        q.push({0, root});
        while(!q.empty()) {
            int level = q.front().first;
            Node* now = q.front().second;
            q.pop();
            if(v.size()== level+1) v[level].push_back(now->val);
            else {
                vector<int> tmp;
                tmp.push_back(now->val);
                v.push_back(tmp);
            }
            vector<Node*> children = now->children;
            for(int i=0;i<children.size();i++) {
                Node* next = children[i];
                q.push({level+1,next});
            }
        }
        
        return v;
    }
};
