class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        // int itrw1=0, itrw2=0, lw1= word1.length(), lw2= word2.length();
        // while(itrw1< lw1 && itrw2< lw2){
        //     ans.push_back(word1[itrw1]);
        //     ans.push_back(word2[itrw2]);
        //     itrw1++;
        //     itrw2++;
        // }
        // ans+= word1.substr(itrw1);
        // ans+= word2.substr(itrw2);
        // return ans;
        
        int i=0, j=0, n= word1.length(), m= word2.length();
        while(i<n || j<m){
            if(i<n) ans.push_back(word1[i++]);
            if(j<m) ans.push_back(word2[j++]);
        }
        return ans;
    }
};