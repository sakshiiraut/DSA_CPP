class Solution {
public:
int helper(int i,vector<int>&nums,vector<int>&dp){
    if(i==nums.size()-1) return nums[i];
    if(i==nums.size()-2) return max(nums[i],nums[i+1]);
    if(dp[i]!=-1) return dp[i];
    return dp[i] = max(nums[i]+helper(i+2,nums,dp),helper(i+1,nums,dp));
}
    int rob(vector<int>& nums) {
         int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int>dp(n,-1);
        return helper(0,nums,dp);
    }
};