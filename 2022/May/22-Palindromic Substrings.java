class Solution {
    private int ans = 0;
    
    private void find(int left, int right, String s) {       
        while(left >= 0 && right < s.length()) {
            if(s.charAt(left) == (s.charAt(right))) ans++;
            else break;
            left--;
            right++;
        }
    }
    
    public int countSubstrings(String s) {
        for(int i=0;i<s.length();i++) {
            find(i, i, s);
            find(i, i+1, s);
        }
        
        return ans;
    }
}
