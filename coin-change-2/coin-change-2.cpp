class Solution {
public:
    int coin_change(int coin[],int n,int sum){
    int t[n+1][sum+1];
    memset(t,-1,sizeof(t));

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(i==0){
                t[i][j] = 0;
            }
            if(j==0){
                t[i][j] = 1;
            }
        }
        
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if(coin[i-1]<=j)
                t[i][j] = t[i][j-coin[i-1]] + t[i-1][j];
            else
                t[i][j] = t[i-1][j]; 
            }
        }

        return t[n][sum];
    
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int coin[n];
        for(int i=0;i<n;i++){
            coin[i] = coins[i];
        }
        return coin_change(coin,n,amount);
    }
};