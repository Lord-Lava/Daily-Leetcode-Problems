// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int binary_search(vector<int>&arr,int l,int r,int target){
        int lo = l;
        int hi = r;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid]<target){
                lo = mid+1;
            }else if(arr[mid]>target){
                hi = mid-1;
            }else{
                return mid;
            }
        }
        return -1;
    }

    bool find3Numbers(int A[], int M, int X)
    {
        vector<int>nums;
        for(int i = 0;i<M;i++)nums.push_back(A[i]);
        bool ans = false;
        sort(nums.begin(),nums.end());
        if(nums.size()<3)return ans;
        int n = nums.size();
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int req = X-(nums[i]+nums[j]);
                int k = -1;
                if(j+1<n)
                k = binary_search(nums,j+1,n-1,req);
                if(k!=-1){
                    ans = true;
                }
            }
        }
        return ans;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends