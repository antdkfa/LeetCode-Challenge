class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = -1e9, pre[20005] = {-1, }, post[20005] = {-1, };
        pre[0] = seats[0] ? 0 : -1;
        for(int i = 1;i<seats.size();i++){
            if(seats[i]) pre[i] = 0;
            else if(pre[i - 1] < 0) pre[i] = -1;
            else pre[i] = pre[i - 1] + 1;
        }
        post[seats.size() - 1] = seats[seats.size() - 1] ? 0 : -1;
        for(int i = seats.size() - 2;i>=0;i--){
            if(seats[i]) post[i] = 0;
            else if(post[i + 1] < 0) post[i] = -1;
            else post[i] = post[i+1] + 1;
        }
        for(int i = 0;i<seats.size();i++){
            if(pre[i] < 0) ans = max(ans, post[i]);
            else if(post[i] < 0) ans = max(ans, pre[i]);
            else ans = max(ans, min(pre[i], post[i]));
            printf("%d %d\n",pre[i], post[i]);
        }
        return ans;
    }
};
