// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:

	int NthRoot(long long n, long long m)
	{
	    long long lo = 1;
	    long long hi = m;
	    
	    while(lo<=hi){
	        long long mid = lo + (hi-lo)/2;
	        long long num = pow(mid,n);

	        if(num>m || num<0){
	            hi = mid-1;
	        }else if(num<m){
	            lo = mid+1;
	        }else if(num==m){
	            return mid;
	        }
	    }
	    
	    return -1;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends