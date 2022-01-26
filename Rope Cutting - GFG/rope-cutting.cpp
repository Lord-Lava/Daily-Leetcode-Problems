// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
        vector<int> RopeCutting(int arr[], int n)
    {
        sort(arr,arr+n);
        vector<int>res;
        int cut_length = arr[0];
        
        for(int i = 1; i<n;i++){
            if(arr[i] - cut_length > 0){
                res.push_back(n-i);
                cut_length = arr[i];
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{   
    int T;
    cin>> T;
    while(T--)
    {
       	int n;
       	cin>>n;
       	int arr[n+1];
       	for(int i=0;i<n;i++)
       	   cin>>arr[i];
        
        vector<int> v;
        Solution ob;
        v = ob.RopeCutting(arr, n);
        for(int i : v){
            cout << i << " ";
        }
        cout << endl;
        
        
    }
  return 0;
}  // } Driver Code Ends