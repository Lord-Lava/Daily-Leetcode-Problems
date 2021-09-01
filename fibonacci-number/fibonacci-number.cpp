class Solution {
public:
    int t[31];
    
    int fibo(int n){
        if(n==0 || n==1){
            return n;
        }
        if(t[n]!=-1) return t[n];
        return t[n] = fibo(n-1) + fibo(n-2);
    }
    
    int fib(int n) {
        memset(t,-1,sizeof(t));
        return fibo(n);
    }
};