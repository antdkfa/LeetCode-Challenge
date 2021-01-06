class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int visited[2005] = {0, }, ans;
        for(int i = 0;i<arr.size();i++) visited[arr[i]] = 1;
        for(int i = 1, cnt = 0;i<2005;i++) {
            if(!visited[i]) cnt++;
            if(cnt == k) {ans=i;break;}
        }
        return ans;
    }
};
