class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> mp = new HashMap<>();
        HashMap<Character, Character> mp1 = new HashMap<>();
        for(int i=0;i<s.length(); i++){
            mp.put(s.charAt(i), t.charAt(i));
            mp1.put(t.charAt(i), s.charAt(i));
        }
        for(int i=0; i<s.length(); i++){
            if(mp.get(s.charAt(i))!=t.charAt(i)) return false;
            if(mp1.get(t.charAt(i))!= s.charAt(i)) return false;
        }
        return true;
    }
    
}