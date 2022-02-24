class Solution {
    public boolean detectCapitalUse(String word) {
        int cnt = 0, idx = 0;
        for(int i=0;i<word.length();i++) {
            if('a' <= word.charAt(i) && word.charAt(i) <= 'z') cnt++;
            else {cnt--; idx = i;}
        }
        return Math.abs(cnt) == word.length() || idx == 0;
    }
}
