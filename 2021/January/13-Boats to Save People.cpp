class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        set<pair<int,int>>s;
        int ans = 0;
        for(int i=0;i<people.size();i++)s.insert({-people[i],i});
        while(s.size()){
            auto it = s.begin();
            int lb = -limit-(*it).first;
            s.erase(it);
            auto tmp = s.lower_bound({lb,0});
            if(tmp != s.end()){
                s.erase(tmp);
            }
            ans++;
        }
        return ans;
    }
};
