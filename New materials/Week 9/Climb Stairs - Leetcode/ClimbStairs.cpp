class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) {
            return n;
        }

        static int dp[46] = {0};

        if(dp[n] == 0) {
            dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
        }

        return dp[n];
    }
};
