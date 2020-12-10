class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool flag = false;
        if(arr.size() <= 2 || arr[0] >= arr[1]) return false;
        for(int i = 1;i<arr.size();i++){
            if(arr[i] == arr[i-1]) { flag = false; break; }
            if(arr[i] > arr[i-1]){
                if(flag == true)  { flag =  false; break; }
            }
            if(arr[i] < arr[i-1]) flag = true;
        }
        return flag;
    }
};
