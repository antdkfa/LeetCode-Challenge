class Solution {
public:
    
    int openLock(vector<string>& deadends, string target) {
        for(int i=0;i<deadends.size();i++){
            if(deadends[i] == "0000") return -1;
        }
        unordered_map<string,int> deadend;
        for(int i=0;i<deadends.size();i++) deadend[deadends[i]] = 1;
        typedef pair<string,int> si;
        queue<si> q;
        q.push({"0000", 0});
        unordered_map<string,int>m;
        m["0000"] = 1;
        int ans = -1;
        char to[20] = { '1', '9', '2', '0', '3', '1', '4', '2', '5', '3', '6', '4', '7', '5', '8', '6', '9', '7', '0', '8'};
        while(!q.empty()){
            string now = q.front().first;
            int depth = q.front().second;
            q.pop();
            if(now == target){
                ans = depth;
                break;
            }
            for(int i=0;i<4;i++){
                string tmp = now;
                tmp[i] = to[(tmp[i] - '0') * 2];
                if(!deadend[tmp] && !m[tmp]){
                    m[tmp] = 1;
                    q.push({tmp, depth + 1});
                }
                
                tmp = now;
                tmp[i] = to[(tmp[i] - '0') * 2 + 1];
                if(!deadend[tmp] && !m[tmp]){
                    m[tmp] = 1;
                    q.push({tmp, depth + 1});
                }
            }
        }
        return ans;
    }
};
