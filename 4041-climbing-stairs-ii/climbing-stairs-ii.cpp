class Solution {
public:
    int solve(int ind, vector<int>& costs, vector<int>& dp) {
       
        if (ind == 0) return 0; 
        if (ind < 0) return 1e9;
        if (dp[ind] != -1) return dp[ind];

        int costStep = costs[ind - 1];

        int fs = costStep + 1 * 1 + solve(ind - 1, costs, dp);
        int ss = costStep + 2 * 2 + solve(ind - 2, costs, dp);
        int ts = costStep + 3 * 3 + solve(ind - 3, costs, dp);

        return dp[ind] = min(fs, min(ss, ts));
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1); 
        return solve(n, costs, dp); 
    }
};