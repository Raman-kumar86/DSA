class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        int i = 0;
        while(i<m){
            bool flag = true;
            for(int j=0;j<n-1;j++){
                if(boxGrid[i][j]!='#') continue;
                if(boxGrid[i][j+1]=='.'){
                    boxGrid[i][j] = '.';
                    boxGrid[i][j+1] = '#';
                    flag = false;
                }
            }
            if(flag){
                i++;
            }
        }
        vector<vector<char>>ans(n,vector<char>(m));
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                ans[col][row] = boxGrid[row][col];
            }
        }
        for(int row=0;row<n;row++){
            reverse(ans[row].begin(), ans[row].end());
        }
        return ans;
    }
};