class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        typedef pair<string,int> si;
        priority_queue <si, vector<si>, greater<si>> pq;
        for(int i=0;i<products.size();i++){
            int len = min(products[i].length(), searchWord.length());
            for(int j=0;j<len;j++){
                if(products[i][j] != searchWord[j]){
                    if(j) pq.push({products[i], j - 1}); 
                    break;
                }
                if(j == len - 1){
                    pq.push({products[i], len-1});
                }
            }
        }
        vector<vector<string>> ans;
        for(int i=0;i<searchWord.length();i++){
            queue<si> q;
            while(q.size() < 3 && !pq.empty()){
                string now = pq.top().first;
                int idx = pq.top().second;
                pq.pop();
                if(i <= idx) q.push({now,idx});
            }
            
            vector<string> tmp;
            while(!q.empty()){
                string now = q.front().first;
                int idx = q.front().second;
                q.pop();
                pq.push({now, idx});
                tmp.push_back(now);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
