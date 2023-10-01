//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t = Integer.parseInt(in.readLine().trim());
        
        while(t-- > 0)
        {
            String s[] = in.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int m = Integer.parseInt(s[1]);
            int a[][] = new int[n][m];
            s = in.readLine().trim().split(" ");
            int ind=0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = Integer.parseInt(s[ind++]);
                }
            }
            Solution ob = new Solution();
            ArrayList<Integer> ans = ob.boundaryTraversal(a, n, m);
            for (int i : ans) {
                out.print(i + " ");
            }
            out.println();
        }
        out.close();
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    static ArrayList<Integer> boundaryTraversal(int matrix[][], int n, int m)
    {
        // code here 
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i=0; i< m-1; i++){
            if(matrix[0][i] != -1) arr.add(matrix[0][i]);
            matrix[0][i]=-1;
        }
        for(int j=0; j< n-1; j++){
            if(matrix[j][m-1] != -1) arr.add(matrix[j][m-1]);
            matrix[j][m-1]=-1;
        }
        for(int k=m-1; k>=1; k--){
            if(matrix[n-1][k] != -1) arr.add(matrix[n-1][k]);
            matrix[n-1][k]=-1;
        }
        for(int l=n-1; l>=1; l--){
            if(matrix[l][0] != -1) arr.add(matrix[l][0]);
            matrix[l][0]=-1;
        }
        if(n==1 && m==1) arr.add(matrix[0][0]);
        return arr;
    }
}
