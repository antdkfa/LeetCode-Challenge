class Solution {
public:
    int uf[1005];
    int find(int now) {
        if(!uf[now]) return now;
        else return find(uf[now]);
    }
    int merge(int a,int b) {
        a = find(a);
        b = find(b);
        if(a == b) return 0;
        uf[a] = b;
        return 1;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0], b = edges[i][1];
            int m = merge(a, b);
            if(!m) {
                ans.push_back(a);
                ans.push_back(b);
                break;
            }
        }
        return ans;
    }
};
