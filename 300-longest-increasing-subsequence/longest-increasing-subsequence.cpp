class Solution {
public:
   vector<vector<int>>dp;
   int solve(vector<int>& nums,int ind,int prev){
        int n = nums.size();
        if(ind < 0) return 0;
        
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int skip = solve(nums,ind-1,prev);
        int take = 0;

        if(prev == -1 || nums[ind] < nums[prev]){
             take = 1 + solve(nums,ind-1,ind);
        }
        return dp[ind][prev + 1] = max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n,vector<int>(n+1,-1));
        return solve(nums,n-1,-1);
    }
};