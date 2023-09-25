class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<pair<int,int>> storage;
        for(int i=0;i<ratings.size();i++){
            storage.push_back({ ratings[i], i });
        }
        sort(storage.begin(), storage.end());
        
        vector<int> ans;
        ans.resize(ratings.size());
        for(int i=0;i<storage.size();i++){
            int val = storage[i].first, idx = storage[i].second;
            int left = 1e9, right = 1e9, leftAns = 0, rightAns = 0;
            if(idx - 1 >= 0) left = ratings[idx - 1];
            if(idx + 1 < storage.size()) right = ratings[idx + 1];
            if(val <= left && val <= right) {
                ans[idx] = 1;
            }
            else {
                int tmp = 0;
                if(left < val) {
                    tmp = ans[idx - 1];
                }
                if(right < val) {
                    tmp = max(tmp, ans[idx + 1]);
                }
                ans[idx] = tmp + 1;
            }
        }
        
        int sum = 0;
        for(int i=0;i<ans.size();i++) {
            sum += ans[i];
        }
        return sum;
    }
};
