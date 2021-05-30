class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<int> leaves;
        //array to hold the leaves of the graph 
        
        unordered_map<int, unordered_set<int>> adj;
        //the adjacency list
        
        vector<int> degree(n, 0);
        //this array holds the degree of each node
        
        for(int i= 0 ; i< edges.size(); i++){
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
            
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        
        
        for(int i=0;i<n;i++){
            if(degree[i] == 1){
                leaves.push_back(i);
            }
        }
        
        
        if(n==1) return {0};
        if(n<=2) return leaves;
        
        vector<int> newleaves;        
        
        while(n>2){
            n-=leaves.size();
            int size = leaves.size();
            
            for(int i=0;i<size;i++){
                int cur = leaves[i];
                degree[cur]--;
                
                for(int nei : adj[cur]){
                    degree[nei]--;
                    adj[nei].erase(cur);
                    if(degree[nei]==1) newleaves.push_back(nei);
                }
                
                adj.erase(cur);
            }
            
            
            leaves = newleaves;
            newleaves = vector<int> ();
        }
        
        return leaves;
        
    }
};
