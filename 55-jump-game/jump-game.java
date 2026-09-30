class Solution {
    
    public boolean solve(int i, int[] nums, int n , int [] dp) {
        if (i == n - 1) return true;

        if(dp[i] != -1){
        
            return dp[i] == 1;
        
        } 
        boolean ans = false;

        for (int j = i + 1; j <= Math.min(n - 1, i + nums[i]); j++) {
            ans = ans || solve(j, nums, n , dp);
        }
        dp[i] = 0;
        return ans;
    }

    public boolean canJump(int[] nums) {
        int n = nums.length;
        int [] dp = new int[n];
        Arrays.fill(dp , -1);

        return solve(0, nums, n , dp);
    }
}