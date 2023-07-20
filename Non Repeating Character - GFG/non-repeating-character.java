//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Driverclass
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            String st = sc.next();
            
            char ans=new Solution().nonrepeatingCharacter(st);
            
            if(ans!='$')
            System.out.println(ans);
            else
            System.out.println(-1);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    //Function to find the first non-repeating character in a string.
    static char nonrepeatingCharacter(String S)
    {
        //Your code here
        int []freq = new int[26];
        for(int i=0; i<S.length(); i++){
            int idx = S.charAt(i)-'a';
            if(freq[idx]>0){
                freq[idx]*=-1;
            }else if(freq[idx]==0){
                freq[idx]= i+1;
            }
        }
        int minIdx=S.length()+1;
        for(int i=0; i<26; i++){
            if(freq[i]>0){
                minIdx= Math.min(minIdx, freq[i]);
            }
            //System.out.print(freq[i]+" ");
        }
        if(minIdx ==S.length()+1) return '$';
        return S.charAt(minIdx-1);
    }
}

