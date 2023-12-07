class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] cnt = new int[30];
        for(int i=0;i<chars.length();i++) {
            cnt[chars.charAt(i) - 'a']++;
        }

        int ans = 0;
        for(int i=0;i<words.length;i++) {
            int[] wordsCnt = new int[30]; 
            for(int j=0;j<words[i].length();j++) {
                wordsCnt[words[i].charAt(j) - 'a']++;
            }

            boolean flag = true;
            for(int j=0;j<30;j++) {
                if(cnt[j] < wordsCnt[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans += words[i].length();
        }

        return ans;
    }
}
