class Solution {
public:
    int min_coin(int coin[], int n,int sum){
        int t[n+1][sum+1];
        memset(t,-1,sizeof(t));
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0){
                    t[i][j] = INT_MAX-1;
                }
                else if(j==0 && i!=0){
                    t[i][j] = 0;
                }
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(coin[i-1] <= j)
                    t[i][j] = min(t[i][j-coin[i-1]]+1 , t[i-1][j]);
                else 
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][sum] == INT_MAX-1? -1:t[n][sum];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(); 
        int coin[n];
        for(int i=0;i<coins.size();i++){
            coin[i] = coins[i];
        }
        return min_coin(coin,n,amount);
    }
};