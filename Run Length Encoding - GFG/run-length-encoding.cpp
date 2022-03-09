// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string s)
{ 
    s+=' ';
    int n = s.size();
    int cnt = 1;
    string ans;
    for(int i =1;i<n;i++){
        if(s[i]!=s[i-1]){
            ans+=s[i-1];
            ans+=to_string(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
    }
    return ans;
}     
 
