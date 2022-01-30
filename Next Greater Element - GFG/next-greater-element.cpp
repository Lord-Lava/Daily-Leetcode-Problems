// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long>st;
        st.push(arr[0]);

        map<long long,long long>mp;
    
        for (int i = 1; i < n; i++)
        {
            long long next = arr[i];
    
            while(!st.empty() && st.top()<next){
                mp[st.top()] = next;
                st.pop();
            }
    
            st.push(next);
        }
    
        while(!st.empty()){
            mp[st.top()] = -1;
            st.pop();
        }
        
        vector<long long>ans;
        for(int i =0;i<n;i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends