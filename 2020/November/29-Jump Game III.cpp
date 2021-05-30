class Solution {
public:
    int visited[50005];
    bool ans = false;
    void dfs(vector<int> arr, int now){
        if(!arr[now]) { ans = true; return; }
        if(arr[now] + now < arr.size() && !visited[arr[now] + now]) {
            visited[arr[now] + now] = 1;
            dfs(arr, arr[now] + now);
        }
        if(now - arr[now] >= 0 && !visited[now-arr[now]]) {
            visited[now-arr[now]] = 1;
            dfs(arr,now-arr[now]);
        }
    }
    
    bool canReach(vector<int>& arr, int start) {
        visited[start] = 1;
        dfs(arr,start);
        return ans;
    }
};
