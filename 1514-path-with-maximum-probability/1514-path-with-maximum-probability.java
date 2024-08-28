class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start_node, int end_node) {
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        HashMap<String, Double> pvals = new HashMap<>();
        int j = 0;
        for (int k = 0; k < edges.length; k++) {
            int[] i = edges[k];
            graph.get(i[0]).add(i[1]);
            graph.get(i[1]).add(i[0]);
            pvals.put(i[0] + "," + i[1], succProb[j]);
            pvals.put(i[1] + "," + i[0], succProb[j++]);
        }

        PriorityQueue<Pair<Double, Integer>> q = new PriorityQueue<>((a, b) -> Double.compare(b.getKey(), a.getKey()));
        q.add(new Pair<>(1.0, start_node));
        double[] probs = new double[n];
        probs[start_node] = 1.0;

        while (!q.isEmpty()) {
            Pair<Double, Integer> top = q.poll();
            double prob = top.getKey();
            int x = top.getValue();

            if (x == end_node) return prob;

            for (int k = 0; k < graph.get(x).size(); k++) {
                int i = graph.get(x).get(k);
                String key = x + "," + i;
                double edgeProb = pvals.getOrDefault(key, 0.0);
                double newProb = prob * edgeProb;
                if (newProb > probs[i]) {
                    probs[i] = newProb;
                    q.add(new Pair<>(newProb, i));
                }
            }
        }
        return 0;
    }
}