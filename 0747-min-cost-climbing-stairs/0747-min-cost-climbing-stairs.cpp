class Solution {
public:
int helper(vector<int>&dp,vector<int>&cost,int i,int n){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    int lcost=cost[i]+helper(dp,cost,i+1,n);
    int rcost=cost[i]+helper(dp,cost,i+2,n);
    dp[i]=min(lcost,rcost);
    return dp[i];
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(helper(dp, cost, 0, n), helper(dp, cost, 1, n));

    }
};