class Solution {
public:
    vector<vector<int>>dp;
    int helper(int sr,int sc,int er,int ec,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(sr>er || sc>ec) return 1e6;
        if (sr == er && sc == ec) return grid[sr][sc];
        if(dp[sr][sc]!=-1) return dp[sr][sc];
        return dp[sr][sc]=min(grid[sr][sc]+helper(sr+1,sc,er,ec,grid,dp),grid[sr][sc]+helper(sr,sc+1,er,ec,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 0, m - 1, n - 1, grid, dp);
    }
};