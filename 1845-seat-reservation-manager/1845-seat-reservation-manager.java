class SeatManager {
    PriorityQueue<Integer> pq= new PriorityQueue<>();
    int val=1;
    public SeatManager(int n) {
        
    }
    
    public int reserve() {
        if(!pq.isEmpty()){
            return pq.poll();
        }
        return val++;
    }
    
    public void unreserve(int seatNumber) {
        pq.add(seatNumber);
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager obj = new SeatManager(n);
 * int param_1 = obj.reserve();
 * obj.unreserve(seatNumber);
 */