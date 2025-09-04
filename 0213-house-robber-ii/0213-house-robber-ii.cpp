class Solution {
public:
    int helper(int i, int end, vector<int>& nums, vector<int>& dp) {
        if (i == end) return nums[i];
        if (i == end - 1) return max(nums[i], nums[i + 1]);
        if (dp[i] != -1) return dp[i];

        return dp[i] = max(nums[i] + helper(i + 2, end, nums, dp), helper(i + 1, end, nums, dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp1(n, -1);
        int case1 = helper(0, n - 2, nums, dp1);
        vector<int> dp2(n, -1);
        int case2 = helper(1, n - 1, nums, dp2);

        return max(case1, case2);
    }
};
