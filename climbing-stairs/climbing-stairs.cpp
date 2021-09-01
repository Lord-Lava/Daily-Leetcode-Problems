class Solution {
public:
    int t[46];
    
    int stairs(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        
        if(t[n]!=-1) return t[n];
        
        return t[n] = stairs(n-1) + stairs(n-2);
    }
    
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return stairs(n);
    }
};