class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        String words1String = "", words2String = "";
        for(int i=0;i<word1.length;i++) {
            words1String += word1[i];
        }
        for(int i=0;i<word2.length;i++) {
            words2String += word2[i];
        }

        return words1String.equals(words2String);
    }
}
