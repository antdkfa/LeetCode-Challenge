class Solution {
public:
    typedef pair<int,int> p;
    p tmp[1005];
    
    static int cmp(p a, p b){
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        for(int i=0;i<n;i++) tmp[i] = {boxTypes[i][0], boxTypes[i][1]};
        sort(tmp, tmp + n, cmp);
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += tmp[i].second * min(truckSize, tmp[i].first);
            truckSize -= min(truckSize, tmp[i].first);
            if(!truckSize) break;
        }
        return ans;
    }
};
