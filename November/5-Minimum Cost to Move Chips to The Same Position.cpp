class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int size = position.size(), o = 0, e = 0;
        for(int i = 0;i<size;i++) position[i] % 2 ? o++ : e++;
        return min(o, e);
    }
};
