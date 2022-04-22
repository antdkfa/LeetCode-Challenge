class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int num: nums) {
            map.put(num, map.getOrDefault(num, 0)+1);
        }
        
        PriorityQueue<Integer> pq = new PriorityQueue<>((n1, n2) -> map.get(n1) - map.get(n2));
        int[] ans = new int[k];
        for(Integer i: map.keySet()) {
            pq.add(i);
            if(pq.size() > k) pq.poll();
        }
        int idx = 0;
        while(!pq.isEmpty()) {
            ans[idx++] = pq.poll();
        }
        return ans;
    }
}
