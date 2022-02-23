class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] split = s.split(" ");
        String[] used = new String[30];
        if(split.length != pattern.length()) return false;
        for(int i=0;i<pattern.length();i++) {
            char p = pattern.charAt(i);
            String now = split[i];
            
            if(used[p-'a'] != null) {
                if(used[p-'a'].equals(now)) continue;
                else return false;
            }
            
            for(int j=0;j<30;j++) {
                if(used[j] != null && used[j].equals(now)) return false; 
            }
            used[p-'a']=now;
        }
        return true;
    }
}
