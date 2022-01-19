class Solution {
public:
    int mySqrt(int x) {
        int lo = 0;
        int hi = x;
        int ans = 1;
        
        while(lo<=hi){
            long long mid = lo + (hi-lo)/2;
            if(mid*mid < x){
                ans = mid;
                lo = mid+1;
            }else if(mid*mid > x){
                hi = mid-1;
            }else{
                return mid;
            }
        }
        return ans;
    }
};