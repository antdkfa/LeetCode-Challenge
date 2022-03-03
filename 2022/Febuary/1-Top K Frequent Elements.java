class Solution {
    private class Pair implements Comparable<Pair> {
        int num;
        int cnt;
        public Pair(int num, int cnt) {
            this.num = num;
            this.cnt = cnt;
        }
        @Override
        public int compareTo(Pair p) {
            if(this.cnt < p.cnt) return 1;
            if(this.cnt > p.cnt) return -1;
            return 0;
        }
    }
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> m = new HashMap<>();
        for(int num:nums) {
            if(m.containsKey(num)) {
                m.put(num, m.get(num)+1);
            }
            else m.put(num,1);
        }
        
        int idx=0;
        Pair[] counter = new Pair[m.size()];
        for(Integer key:m.keySet()) {
            counter[idx++] = new Pair(key,m.get(key));
        }
        Arrays.sort(counter);
        
        int[] ans = new int[k];
        for(int i=0;i<ans.length;i++) {
            ans[i] = counter[i].num;
        }
        return ans;
    }
}
