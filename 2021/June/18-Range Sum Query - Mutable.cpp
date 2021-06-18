class NumArray {
public:
    
    int H = 1;
    vector<int> seg;
    NumArray(vector<int>& nums) {
        while(H < nums.size()) {
            H = H * 2;
        }
        seg.resize(H * 2 + 1);
        for(int i=0;i<nums.size();i++) update(i,nums[i]);
    }
    
    void update(int index, int val) {
        index += H;
        seg[index] = val;
            index /= 2;
        while(index) {
            seg[index] = seg[index * 2] + seg[index * 2 + 1];
            index /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 1, 0, H - 1);
    }
    
    int query(int l, int r, int nodeNum, int nodeL, int nodeR) {
        if(nodeR < l || r < nodeL) return 0;
        else if(l <= nodeL && nodeR <= r) return seg[nodeNum];
        else {
            int mid = (nodeL + nodeR) / 2;
            return query(l, r, nodeNum * 2, nodeL, mid) + query(l, r, nodeNum * 2 + 1, mid + 1, nodeR);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
