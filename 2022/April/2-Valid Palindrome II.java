class Solution {
    private boolean isPalindrome(String s, int sIdx, int eIdx) {
        for(int i=sIdx, j=0;i<=(sIdx+eIdx)/2;i++,j++) {
            if(s.charAt(i) != s.charAt(eIdx-j)) return false; 
        }
        return true;
    }
    public boolean validPalindrome(String s) {
        int sIdx = 0, eIdx = s.length()-1;
        while(sIdx<=eIdx) {
            if(s.charAt(sIdx) != s.charAt(eIdx)) {
                return isPalindrome(s, sIdx, eIdx-1) || isPalindrome(s, sIdx+1, eIdx);
            }
            sIdx++;
            eIdx--;
        }
        return true;
    }
}
