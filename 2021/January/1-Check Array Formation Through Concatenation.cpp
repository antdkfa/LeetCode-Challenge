class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int idx = 0;
        while(idx<arr.size()){
            bool flag = false;
            for(int i = 0;i<pieces.size();i++){
                if(arr[idx]==pieces[i][0]){
                    flag = true;
                    for(int j=0;j<pieces[i].size();j++){
                        if(arr[idx+j] != pieces[i][j]) return false;
                    }
                    idx+=pieces[i].size();
                    break;
                }
            }
            if(!flag) return flag;
        }
        return true;
    }
};
