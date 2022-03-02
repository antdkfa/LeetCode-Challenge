class Solution {
    public boolean isSubsequence(String s, String t) {
        int sIdx = 0;
        for(int i=0;i<t.length() && sIdx < s.length();i++) {
            if(t.charAt(i) == s.charAt(sIdx)) sIdx++;
        }
        
        return sIdx == s.length();
    }
}
