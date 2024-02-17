class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int i=0;
        for(i=1; i<heights.length; i++){
            int diff=heights[i]-heights[i-1];
            if(diff>0){
                if(ladders>0){
                    pq.add(diff);
                    ladders--;
                }else{
                    if(pq.isEmpty()==false && pq.peek()<diff && pq.peek()<=bricks){
                        bricks-= pq.peek();
                        pq.poll();
                        pq.add(diff);
                    }
                    else if(bricks>= diff){
                        bricks-= diff;
                    }
                    else{
                        return i-1;
                    }
                }
            }
        }
        return i-1;
    }
}