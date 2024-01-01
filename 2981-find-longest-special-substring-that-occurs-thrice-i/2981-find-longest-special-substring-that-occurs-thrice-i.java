class Solution {
    public int maximumLength(String s) {
        Map<Character, Map<Integer, Integer>> mp= new HashMap<>();
        for(int i=0; i<s.length(); i++){
            char ch= s.charAt(i);
            int cnt=0;
            for(int j=i; j<s.length(); j++){
                if(ch==s.charAt(j)) cnt++;
                else break;
               // mp.put(ch, mp.getOrDefault(ch, new HashMap<>()).put(cnt, mp.get(ch).getOrDefault(cnt,0))+1);
                mp.computeIfAbsent(ch, k -> new HashMap<>()).merge(cnt, 1, Integer::sum);
            }
        }
        int ans=-1;
        for(Map.Entry<Character, Map<Integer, Integer>> x: mp.entrySet()){
            for(Map.Entry<Integer, Integer> y: x.getValue().entrySet()){
                if(y.getValue()>=3){
                    ans = Math.max(ans, y.getKey());
                }
            }
        }
        return ans;
        
    }
}