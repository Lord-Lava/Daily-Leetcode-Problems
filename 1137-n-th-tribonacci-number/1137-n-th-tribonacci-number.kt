class Solution {
    fun tribonacci(n: Int): Int {
        var a = 0
        var b = 1
        var c = 1
        
        if(n==0) return 0
        
        for(i in 3..n){
            var d = a+b+c
            a = b
            b = c
            c = d
        }
        return c
    }
}