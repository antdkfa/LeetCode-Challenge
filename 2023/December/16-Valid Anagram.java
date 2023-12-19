class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) {
            return false;
        }

        int[] sCnt = new int[30];
        int[] tCnt = new int[30];
        for(int i=0;i<s.length();i++) {
            sCnt[s.charAt(i) - 'a']++;
            tCnt[t.charAt(i) - 'a']++;
        }

        for(int i=0;i<30;i++) {
            if(sCnt[i] != tCnt[i]) return false;
        }

        return true;
    }
}
