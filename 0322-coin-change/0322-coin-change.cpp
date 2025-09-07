class Solution {
public:
    int helper(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // Base cases
        if (amount == 0) return 0;            // no coins needed
        if (i >= coins.size() || amount < 0) return 1e9; // invalid (large number)

        if (dp[i][amount] != -1) return dp[i][amount];

        // Choice 1: take coin[i] (stay at i since unlimited supply)
        int take = 1 + helper(i, amount - coins[i], coins, dp);

        // Choice 2: skip coin[i]
        int skip = helper(i + 1, amount, coins, dp);

        return dp[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = helper(0, amount, coins, dp);

        return (ans >= 1e9 ? -1 : ans); // if impossible, return -1
    }
};
