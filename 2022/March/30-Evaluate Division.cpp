class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,int> m;
        vector<vector<pair<int,double>>> v;
        v.resize(45);
        int idx = 1;
        for(int i=0;i<equations.size();i++) {
            string A = equations[i][0];
            string B = equations[i][1];
            int aIdx = 0, bIdx = 0;
            if(m[A]) aIdx = m[A];
            else {
                m[A] = idx;
                aIdx = idx++;
            }
            if(m[B]) bIdx = m[B];
            else {
                m[B] = idx;
                bIdx = idx++;
            }
            v[aIdx].push_back({bIdx, values[i]});
            v[bIdx].push_back({aIdx, 1 / values[i]});
        }
        
        vector<double> ans;
        for(int i=0;i<queries.size();i++) {
            string s = queries[i][0], e = queries[i][1];
            if(m[s] && m[e]) {
                queue<pair<int, double>> q;
                int visited[45] = {0, };
                q.push({m[s], 1.0});
                visited[m[s]] = 1;
                while(!q.empty()) {
                    int now = q.front().first;
                    double ret = q.front().second;
                    if(m[e] == now) {
                        ans.push_back(ret);
                        break;
                    }
                    q.pop();
                    for(int i=0;i<v[now].size();i++) {
                        int next = v[now][i].first;
                        double val = v[now][i].second;
                        if(!visited[next]) {
                            visited[next] = 1;
                            q.push({next, ret * val});
                        }
                    }
                }
                if(!visited[m[e]]) ans.push_back(-1.0);
            } else ans.push_back(-1.0);
        }
        return ans;
    }
};
