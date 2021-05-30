class Solution {
public:
    int minJumps(vector<int>& arr) {
        typedef pair<int,int>p;
        queue<p>q;
        int dp[50005]={0,};
        map<int,int>m;
        set<p>s;
        for(int i=0;i<arr.size();i++) s.insert({arr[i],i});
        q.push({0,1});
        dp[0] = 1;
        while(!q.empty()){
            int now = q.front().first, depth = q.front().second;
            q.pop();
            if(now+1<arr.size() && !dp[now+1]) dp[now+1]=depth+1,q.push({now+1,depth+1});
            if(now-1>=0 && !dp[now-1]) dp[now-1]=depth+1,q.push({now-1,depth+1});
            if(!m[arr[now]]){
                m[arr[now]]=1;
                auto it=s.lower_bound({arr[now],0});
                if(it != s.end()){
                    int tmp=it->first;
                    for(it;it != s.end();it++){
                        if(it->first!=tmp) break;
                        if(!dp[it->second]) dp[it->second]=depth+1,q.push({it->second,depth+1});
                    }
                }
            }
        }
        return dp[arr.size() - 1] - 1;
    }
};
