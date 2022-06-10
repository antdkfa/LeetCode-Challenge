class Solution {
    public int lengthOfLongestSubstring(String s) {
        int sIdx = 0;
        int eIdx = 0;
        int[] visited = new int [30];
        int ans = 0;
        Map<Character, Integer> m = new HashMap<>();
        while(eIdx < s.length()) {
            char now = s.charAt(eIdx);
            if(m.containsKey(now) && m.get(now) == 1) {
                m.put(s.charAt(sIdx), 0);
                sIdx++;
            } else {
                m.put(now, 1); 
                eIdx++;
                ans = Math.max(ans, eIdx - sIdx);
            }
        }
        return ans;
    }
}
