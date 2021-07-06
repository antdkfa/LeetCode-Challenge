class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int appearance[100005] = { 0, };
        for(int i=0;i<arr.size();i++) {
            appearance[arr[i]]++;
        }
        
        vector<int> v;
        for(int i=1;i<100005;i++){
            if(appearance[i]) v.push_back({appearance[i]});
        }
        sort(v.begin(),v.end());
        
        int n = arr.size(), ans = 0;
        for(int i=v.size() - 1;i>=0;i--){
            n -= v[i];
            ans++;
            if(n <= arr.size() / 2) break;
        }
        
        return ans;
    }
};
