class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int isUsed[100005] = {}, usedCnt[100005] = {};
        int n=fruits.size(), s = 0, e = 0, nowCnt = 0, ans = 0;
        while(e < n) {
            int front = fruits[s], now = fruits[e];
            //e를 넣어도 된다면 넣음
            if(isUsed[now]) {
                usedCnt[now]++;
                e++;
            } else {
                if(nowCnt < 2) {
                    nowCnt++;
                    isUsed[now] = 1;
                    usedCnt[now]++;
                    e++;
                } else {
                //넣으면 안된다면 s에서 뺌
                    usedCnt[front]--;
                    if(!usedCnt[front]) isUsed[front] = 0, nowCnt--;
                    s++;
                }
            }
            ans = max(ans, e - s);
        }
        return ans; 
    }
};
