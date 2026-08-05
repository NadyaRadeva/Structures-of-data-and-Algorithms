class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] = length of the Longest Increasing Subsequence
        // that ends exactly at index i.
        vector<int> dp(nums.size());

        // Try each element as the end of an increasing subsequence.
        for (int i = 0; i < nums.size(); ++i) {
            // Every element by itself is an increasing subsequence of length 1.
            dp[i] = 1;

            // Check all previous elements.
            for (int j = 0; j < i; ++j) {
                // If nums[j] can come before nums[i] in an increasing subsequence...
                if (nums[j] < nums[i]) {
                    // ...extend the subsequence ending at j.
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        // The longest increasing subsequence can end at any index,
        // so return the largest value in dp.
        return *max_element(dp.begin(), dp.end());
    }
};
