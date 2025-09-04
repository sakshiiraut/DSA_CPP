class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int helper(int n, int k, int target) {
        if (n == 0 && target == 0) return 1;
        if (n == 0 || target < 0) return 0;

        if (dp[n][target] != -1) return dp[n][target];

        long long ways = 0;
        for (int face = 1; face <= k; face++) {
            ways = (ways + helper(n - 1, k, target - face)) % MOD;
        }

        return dp[n][target] = ways;
    }

    int numRollsToTarget(int n, int k, int target) {
        dp.assign(n + 1, vector<int>(target + 1, -1));
        return helper(n, k, target);
    }
};
