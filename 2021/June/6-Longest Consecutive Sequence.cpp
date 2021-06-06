class Solution {
public:
    
    map<int,int> uf, cnt;
    int ans = 0;
    int find(int now){
        if(uf[now] == now) return now;
        return uf[now] = find(uf[now]);
    }
    
    void merge(int a,int b){
        a = find(a);
        b = find(b);
        cnt[a] += cnt[b];
        uf[b] = a;
        ans = max(ans, abs(cnt[a]));
        return;
    }
    
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()) ans = 1;
        for(int i=0;i<nums.size();i++){
            int now = nums[i];
            if(!cnt[now]){
                cnt[now] = 1;
                uf[now] = now;
                int pre = now - 1;
                int post = now + 1;
                if(cnt[pre] > 0 && cnt[post] > 0){
                    pre = find(pre);
                    post = find(post);
                    merge(pre, post);
                    merge(pre, now);
                }
                else if(cnt[pre] > 0) {
                    pre = find(pre);
                    merge(pre, now);
                }
                else if(cnt[post] > 0) {
                    post = find(post);
                    merge(post, now);
                }
            }
        }
        return ans;
    }
};
