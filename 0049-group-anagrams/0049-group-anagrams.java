class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ans = new ArrayList<>();
        HashMap<String, List<String>> mp = new HashMap<>();
        for(int i=0; i<strs.length; i++){
            int[] freq = new int[26];
            String str = new String();
            for(int j=0; j<strs[i].length(); j++){
                freq[strs[i].charAt(j)-'a']++;
            }
            for(int j=0; j<26; j++){
                str+= Integer.toString(freq[j])+",";
            }
            if(mp.get(str)==null) mp.put(str, new ArrayList<String>());
            mp.get(str).add(strs[i]);
           // mp.getOrDefault(str, new ArrayList<String>()).add(strs[i]);
        }
        for(Map.Entry<String, List<String>> x: mp.entrySet()){
            ans.add(x.getValue());
        }
        return ans;
    }
}