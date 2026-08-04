class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) {
            return n;
        }

        static size_t dp[1000]{};

        if(dp[n] == 0) {
            dp[n] = fib(n - 1) + fib(n - 2);
        }

        return dp[n];
    }
};
