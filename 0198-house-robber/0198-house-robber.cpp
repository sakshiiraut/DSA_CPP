class Solution {
public:
    int helper(vector<int>&dp,int i,int n,vector<int>&nums){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        dp[i]=max(nums[i]+helper(dp,i+2,n,nums),helper(dp,i+1,n,nums));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return helper(dp,0,n,nums);
    }
};