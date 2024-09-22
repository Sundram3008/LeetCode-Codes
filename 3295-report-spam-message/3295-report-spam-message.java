class Solution {
    public boolean reportSpam(String[] message, String[] bannedWords) {
        HashSet<String> st = new HashSet<>();
        for(int i=0; i<bannedWords.length; i++) st.add(bannedWords[i]);
        int cnt=0;
        for(int i=0; i<message.length && cnt<2; i++)
            if(st.contains(message[i])) cnt++;
        return (cnt>=2);
    }
}