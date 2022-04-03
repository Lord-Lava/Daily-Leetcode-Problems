// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    int dp[1001][1001];
    int knapsack(int n,int w,int W[],int V[],int i){
    	if(w==0) return 0;
    	if(i==n){
    		return 0;
    	}
    	if(dp[i][w] != -1) return dp[i][w];
    	if(W[i]<=w){
    		return dp[i][w] = max(
    			V[i] + knapsack(n,w-W[i],W,V,i+1),
    			knapsack(n,w,W,V,i+1)
    		);
    	}
    	
    	return dp[i][w] = knapsack(n,w,W,V,i+1);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        memset(dp,-1,sizeof(dp));
       return knapsack(n,W,wt,val,0);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends