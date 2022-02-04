// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        stack<int>st;
        vector<int>res(n,1);
        
        for(int i = 0;i<n;i++){
            bool fl=0;
            while(!st.empty() && price[st.top()]<=price[i])
                st.pop(),fl=1;
            if(!st.empty())
                res[i] = (i-st.top());
            else if(st.empty() && fl){
                res[i] = (i+1);
            }
            
            st.push(i);
        }
        
        return res;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends