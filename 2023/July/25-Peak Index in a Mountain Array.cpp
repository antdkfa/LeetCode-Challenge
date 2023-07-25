class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0, e = arr.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            int left = mid-1,right=mid+1;
            if(left<0||right>=arr.size()) break;
            if(arr[left]<arr[mid] && arr[mid] <arr[right]) {
                s=mid+1;
            } else if(arr[left]>arr[mid]&&arr[mid]>arr[right]) {
                e=mid-1;
            } else return mid;
        }
        return e;
    }
};
