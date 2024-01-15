class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        HashMap<Integer, Integer> loseOrTaken= new HashMap<>();
        for(int i=0; i<matches.length; i++){
            loseOrTaken.put(matches[i][1], loseOrTaken.getOrDefault(matches[i][1], 0)+1);
        }
        List<List<Integer>> res = new ArrayList<>();
        res.add(new ArrayList<>());
        res.add(new ArrayList<>());
        for(int i=0; i<matches.length; i++){
            if(loseOrTaken.get(matches[i][1]) ==1) res.get(1).add(matches[i][1]);
            if(loseOrTaken.containsKey(matches[i][0])==false){
                res.get(0).add(matches[i][0]);
                loseOrTaken.put(matches[i][0], -1);
            }
        }
        Collections.sort(res.get(0));
        Collections.sort(res.get(1));
        return res;
    }
}