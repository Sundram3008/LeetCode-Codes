class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        // idea is idk how to prove it just keep removing nodes with degree 1 untill atmost 2 remains
        List<Integer> res = new ArrayList<>();
        if(n==1){
            res.add(0);
            return res;
        }
        Queue<Integer> q = new LinkedList<>();
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i=0; i<n; i++){
            adj.add(new ArrayList<>());
        }
        int []deg = new int[n];
        for(int i=0; i<edges.length; i++){
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
            adj.get(edges[i][0]).add(edges[i][1]);
            adj.get(edges[i][1]).add(edges[i][0]);
        }
        for(int i=0; i<n; i++){
            if(deg[i]==1) q.add(i);
        }
        while(n>2){
            int size = q.size();
            n-= size;
            while(size-- >0){
                int node= q.poll();
                for(int i: adj.get(node)){
                    deg[i]--;
                    if(deg[i]==1) q.add(i);
                }
            }
        }
        res.addAll(q);
        return res;
    }
}