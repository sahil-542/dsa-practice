typedef long long ll;
class Solution {
public:
    long long solve(vector<int>& nums,int ind, bool flag,
                vector<vector<long long>>& dp){
        int n = nums.size();
         if(ind < 0) return 0;
         int val = nums[ind];

         if(flag == false){
            val = -val;
         }

         if(dp[ind][flag] != -1) return dp[ind][flag];

        ll skip = solve(nums,ind - 1,flag,dp);
        ll take = solve(nums,ind-1,!flag,dp) + val;

        return dp[ind][flag] = max(skip, take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>>dp(n,vector<ll>(2,-1));
        return solve(nums,n-1,true,dp);
    }
};