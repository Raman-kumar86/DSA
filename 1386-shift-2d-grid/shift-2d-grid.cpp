class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>ans(m, vector<int>(n,0));
        while(k--){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    int x = 0;
                    int y = 0;
                    if(j==n-1 && i==m-1){
                        y = 0;
                        x = 0;
                    }else if(j==n-1){
                        x = i+1;
                        y = 0;
                    }else{
                        x = i;
                        y = j+1;
                    }
                    ans[x][y] = grid[i][j];
                }
            }
            grid = ans;
        }
        return grid;
    }
};