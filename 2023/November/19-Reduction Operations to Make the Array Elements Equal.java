class Solution {
    public int reductionOperations(int[] nums) {
        Map<Integer,Integer> m = new HashMap<>();
        for(int num: nums) {
            if(m.containsKey(num)) {
                m.put(num, m.get(num) + 1);
            } else m.put(num, 1);
        }
        
        List<Integer> keySet = new ArrayList<>(m.keySet());
        keySet.sort((a,b) -> b.compareTo(a));
        
        int ans = 0;
        for(int i=0;i<keySet.size();i++) {
            int cnt = m.get(keySet.get(i));
            ans += cnt * (keySet.size() - i - 1);
        }
        return ans;
    }
}
