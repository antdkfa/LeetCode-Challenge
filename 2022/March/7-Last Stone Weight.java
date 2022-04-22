class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0;i<stones.length;i++) {
            pq.add(stones[i]);
        }
        while(!pq.isEmpty()) {
            int f = pq.poll();
            if(pq.isEmpty()) {
                return f;
            }
            int s = pq.poll();
            pq.add(f - s);
        }
        return 0;
    }
}
