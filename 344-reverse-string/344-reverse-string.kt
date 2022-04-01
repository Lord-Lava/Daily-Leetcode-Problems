class Solution {
    fun reverseString(s: CharArray): Unit {
        val n = s.count()
        for(i in 0..(n/2).minus(1)){
            var temp = s[i]
            s[i] = s[n-i-1]
            s[n-i-1] = temp
        }
    }
}