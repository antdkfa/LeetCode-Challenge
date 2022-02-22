class Solution {
    class Seat {
        private int startIdx;
        private int distance;
        public Seat(int startIdx, int distance) {
            this.startIdx = startIdx;
            this.distance = distance;
        }
    }
    
    public int maxDistToClosest(int[] seats) {
        int startIdx = -1, distance = 0, ans = 0;
        ArrayList<Seat> list = new ArrayList<>();
        
        for(int i=0;i<seats.length;i++) {
            if(seats[i] == 1) {
                list.add(new Seat(startIdx, distance));
                startIdx = -1;
                distance = 0;
            } else {
                if(startIdx == -1) startIdx = i;
                distance++;
            }
        }
        list.add(new Seat(0, distance));
        for(Seat seat: list) {
            if(seat.startIdx == 0) ans = Math.max(seat.distance, ans);
            else ans = Math.max((seat.distance+1) / 2, ans);
        }
        return ans;
    }
}
