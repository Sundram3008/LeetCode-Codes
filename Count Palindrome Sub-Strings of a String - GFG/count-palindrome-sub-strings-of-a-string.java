//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;


class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int N=sc.nextInt();
                    String S=sc.next();
                        
                    Solution obj = new Solution();
                    
                    
                    System.out.println(obj.CountPS(S,N));
                    
                }
                
        }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    int totalPals(String s, int n, int l, int r){
        int pals=0;
        while(l>=0 && r<n && s.charAt(l)==s.charAt(r)){
            if(r-l+1 >1) pals++;
            l--;
            r++;
        }
        return pals;
    }
    public int CountPS(String S, int N)
    {
        int ans=0;
        for(int i=0; i<N; i++){
            ans+= totalPals(S, N, i, i);
            ans+= totalPals(S, N, i, i+1);
        }
        return ans;
    }
    
}