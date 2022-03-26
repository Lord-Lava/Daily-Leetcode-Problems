class Solution {
    fun search(nums: IntArray, target: Int): Int {
        var size: Int = nums.size
        var low: Int = 0
        var high: Int = size - 1
        while(low<=high){
            var mid: Int = low + (high - low)/2;
            when{
                nums[mid]<target -> low = mid+1
                nums[mid]>target -> high = mid-1
                else -> return mid
            }
        }
        return -1
    }
}