class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int minSum = INT_MAX;
        bool found = false;

        for (int k = l; k <= r; ++k) {
          
            for (int i = 0; i + k <= n; ++i) {
                int sum = prefix[i + k] - prefix[i];
                if (sum > 0) {
                    minSum = min(minSum, sum);
                    found = true;
                }
            }
        }

        return found ? minSum : -1;
    }
};