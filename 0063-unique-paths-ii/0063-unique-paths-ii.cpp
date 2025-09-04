class Solution {
public:
int helper(int sr,int sc,int er,int ec,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
    if(sr>er || sc>ec) return 0;
    if(obstacleGrid[sr][sc]==1) return 0;
     if(sr==er && sc==ec) return 1;
    if(dp[sr][sc]!=-1) return dp[sr][sc];
    return dp[sr][sc]=helper(sr+1,sc,er,ec,dp,obstacleGrid)+helper(sr,sc+1,er,ec,dp,obstacleGrid);
 }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(0,0,m-1,n-1,dp,obstacleGrid);
    }
};