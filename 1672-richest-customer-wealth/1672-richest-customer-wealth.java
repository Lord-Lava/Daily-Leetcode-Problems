class Solution {
    public int maximumWealth(int[][] accounts) {
        int maxWealth = Integer.MIN_VALUE;
        int n=accounts.length;
        int m=accounts[0].length;
        for(int row=0;row<n;row++){
            int sum=0;
            for(int col=0;col<m;col++){
                sum+=accounts[row][col];
            }
            maxWealth = Math.max(maxWealth,sum);
        }
        return maxWealth;
    }
}