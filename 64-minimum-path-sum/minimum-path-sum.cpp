class Solution {
public:
    int m,n;
    int arr[201][201];
    int minPath(int i, int j, vector<vector<int>>& grid){
        if(i>=m || j>=n) return INT_MAX;
        if(i==m-1 && j==n-1) return grid[i][j];
        if(arr[i][j]!=-1) return arr[i][j];
        int left = minPath(i, j+1, grid);
        int right = minPath(i+1, j, grid);
        return arr[i][j] = grid[i][j] + min(left, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(arr, -1, sizeof(arr));
        m = grid.size();
        n = grid[0].size();
        return minPath(0, 0, grid);
    }
};