class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int judge = -1, cnt[1005] = {0,};
        for(int i=0;i<trust.size();i++) {
            cnt[trust[i][1]]++;
        }
        
        for(int i=1;i<=n;i++) {
            if(cnt[i] == n-1) {
                judge = i;
            }
        }
        
        if(judge != -1) {
            for(int i=0;i<trust.size();i++) {
                if(trust[i][0] == judge) judge = -1;
            }
        }
        return judge;
    }
};
