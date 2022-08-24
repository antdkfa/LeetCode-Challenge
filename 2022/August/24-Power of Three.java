class Solution {
    public boolean isPowerOfThree(int n) {
        if(n==1) return false;
        if(n==0) return false;
        while(n!=1){
            if(n%3!=0)return false;
            n/=3;
        }
        if(n==0) return false;
        return true;
    }
}
