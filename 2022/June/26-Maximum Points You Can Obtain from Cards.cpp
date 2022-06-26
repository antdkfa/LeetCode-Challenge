class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int pre[100005] = {0, };
        int post[100005] = {0, };
        
        pre[0] = cardPoints[0];
        for(int i=1;i<cardPoints.size();i++) {
            pre[i] = pre[i-1]+cardPoints[i];
        }
        post[n-1] = cardPoints[n-1];
        for(int i=n-2;i>=0;i--) {
            post[i] = post[i+1]+cardPoints[i];           
        }
        
        int ans = max(pre[k-1],post[n-k]);
        for(int i=0,j=n-k+1;i<n;i++,j++) {
            if(j>=n) break;
            ans = max(ans, pre[i] + post[j]);          
        }
        return ans;
    }
};
