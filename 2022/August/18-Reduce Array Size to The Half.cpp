class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int cnt[100005] = {};
        for(int i=0;i<arr.size();i++) {
            cnt[arr[i]]++;
        }
        
        sort(cnt, cnt+100005);
        int erased = 0,ans=0;
        for(int i=100004;i>=0;i--) {
            erased+= cnt[i];
            if(arr.size() - erased <= arr.size() / 2) {
                ans = 100005 - i;
                break;
            }
        }
        return ans;
    }
};
