class Solution {
    fun swap(arr:IntArray,index1:Int,index2:Int) : Unit {
        var temp = arr[index1]
        arr[index1] = arr[index2]
        arr[index2] = temp
    }
    
    fun sortColors(arr: IntArray): Unit {
        var low: Int = 0
        var mid: Int = 0
        var high: Int = arr.size-1
        
        while(mid<=high){
            when{
                arr[mid] == 0 ->
                {
                    swap(arr,mid,low)
                    mid++ 
                    low++
                }
                arr[mid] == 1 -> mid++
                else -> {
                    swap(arr,mid,high) 
                    high--
                }
            }
        }
    }
}