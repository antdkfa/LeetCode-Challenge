class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int pre[100005] = {0, }, post[100005] = {0,}, ans = 0;
        pre[0] = cardPoints[0];
        for(int i=1;i<cardPoints.size();i++) pre[i] = pre[i-1] + cardPoints[i];
        for(int i=cardPoints.size() - 1;i>=0;i--) post[i] = post[i+1] + cardPoints[i];
        ans = post[cardPoints.size() - k];
        for(int i=0;i<cardPoints.size();i++){
            if(i>=k) break;
            ans = max(ans, pre[i] + post[cardPoints.size() - k + i + 1]);
        }
        return ans;
    }
};
