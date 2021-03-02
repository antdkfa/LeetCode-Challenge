class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int>m;
        int cnt=0, sz=candyType.size();
        for(int i=0;i<sz;i++){
            if(!m[candyType[i]]) {
                m[candyType[i]]=1;
                cnt++;
            } 
        }
        return min(cnt, sz/2);
    }
};
