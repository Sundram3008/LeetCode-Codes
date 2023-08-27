//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Driver
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- >0)
        {
            String str = read.readLine();
            System.out.println(new Reverse().reverseWord(str));
        }
    }
}
// } Driver Code Ends


//User function Template for Java


class Reverse
{
    // Complete the function
    // str: input string
    public static String reverseWord(String s)
    {
        // Reverse the string str
        StringBuilder str= new StringBuilder(s);
        int l=0, r= str.length()-1;
        while(l<r){
            char ch= str.charAt(l);
            str.setCharAt(l, str.charAt(r));
            str.setCharAt(r, ch);
            l++;
            r--;
        }
        return str.toString();
    }
}