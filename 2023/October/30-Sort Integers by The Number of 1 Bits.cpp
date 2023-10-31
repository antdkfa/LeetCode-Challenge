class Solution {
public:
    int getCnt(int a) {
        int cnt = 0;
        while(a) {
            if(a%2) cnt++;
            a /= 2;
        }

        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr) {
        typedef pair<int,int> p;
        vector<p> v;

        for(auto a: arr) {
            int cnt = getCnt(a);
            v.push_back({cnt, a}); 
        }

        sort(v.begin(), v.end());
        vector<int> ans;
        for(auto a: v) {
            ans.push_back(a.second);
        }

        return ans;
    }
};
