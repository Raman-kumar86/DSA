class Solution {
public:
    int m,n;
    int solve(vector<vector<int>>& grid, int i, int j, int k,vector<vector<vector<int>>>&dp){
        if(i>=m || j>=n) return INT_MIN;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int cost = grid[i][j]==0?0:1;
        if(cost>k) return dp[i][j][k] = INT_MIN;
        if(i==m-1 && j==n-1) return dp[i][j][k] = grid[i][j];
        int right = solve(grid, i, j+1, k-cost, dp);
        int down = solve(grid, i+1, j, k-cost, dp);
        if(right == INT_MIN && down == INT_MIN) return dp[i][j][k] = INT_MIN;
        return dp[i][j][k] = grid[i][j] + max(right, down);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(k+1,-1)));
        int result = solve(grid, 0, 0, k, dp);
        return result==INT_MIN?-1:result;
    }
};