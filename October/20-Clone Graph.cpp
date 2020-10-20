/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int,Node*> m;
    int visited[105][105] = {0, };
    vector<vector<int>> v;
    void make_vec(Node* now){
        for(int i = 0;i<now->neighbors.size();i++){
            Node* next = now->neighbors[i];
            if(!visited[now->val][next->val]) {
                visited[now->val][next->val] = 1;
                v[now->val].push_back(next->val);
                make_vec(next);
            }
        }
    }
    
    void make_graph(int now){
        for(int i = 0;i<v[now].size();i++){
            int next = v[now][i];
            if(!visited[now][next]){
                Node * nw, *nt;
                if(m[now]){
                    nw = m[now];
                }
                else nw = new Node(now), m[now] = nw;
                if(m[next]){
                    nt = m[next];
                }
                else nt = new Node(next), m[next] = nt;
                nw->neighbors.push_back(nt);
                visited[now][next] = 1;
                make_graph(next);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        if(node->neighbors.size() == 0) {
            Node *ret = new Node(1);
            return ret;
        }
        v.resize(105);
        make_vec(node);
        memset(visited,0,sizeof(visited));
        make_graph(1);
        return m[1];
    }
};
