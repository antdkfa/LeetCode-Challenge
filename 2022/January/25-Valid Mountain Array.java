class Solution {
    public boolean validMountainArray(int[] arr) {
        boolean isIncreasing = true;
        if(arr.length < 3 || arr[1] < arr[0]) return false;
        for(int i=0;i<arr.length-1;i++) {
            if(arr[i] < arr[i+1]) {
                if(!isIncreasing) return false; 
            } else if(arr[i] > arr[i+1]) {
                isIncreasing = false;
            } else return false;
        }
        return !isIncreasing;
    }
}
