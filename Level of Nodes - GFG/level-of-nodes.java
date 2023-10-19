//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class DriverClass
{
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            int V = sc.nextInt();
            int E = sc.nextInt();
            for(int i = 0; i < V+1; i++)
                list.add(i, new ArrayList<Integer>());
            for(int i = 0; i < E; i++)
            {
                int u = sc.nextInt();
                int v = sc.nextInt();
                list.get(u).add(v);
                list.get(v).add(u);
            }
            int X = sc.nextInt();
            
            Solution ob = new Solution();
            
            System.out.println(ob.nodeLevel(V,list,X));
        }
    }
}
// } Driver Code Ends


/*Complete the function below*/

class Solution
{
    //Function to find the level of node X.
    int nodeLevel(int V, ArrayList<ArrayList<Integer>> adj, int X)
    {
        // code here
        boolean vis[] = new boolean[V];
        vis[0]=true;
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        int lvl=0;
        while(!q.isEmpty()){
            int n= q.size();
            for(int i=1; i<=n; i++){
                int temp= q.poll();
                if(temp==X) return lvl;
                for(int j=0; j< adj.get(temp).size(); j++){
                    int val= adj.get(temp).get(j);
                    if(vis[val]==false){
                        vis[val]=true;
                        q.add(val);
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
}