class Solution {
public:
    void dfs(int r, int c, int n_row, int n_col, vector<vector<char>>& grid){
        if (r < 0 || r > n_row - 1 || c < 0 || c > n_col - 1 || grid[r][c] == '0') {return;}
        grid[r][c] = '0';
        dfs(r-1, c, n_row, n_col, grid);
        dfs(r+1, c, n_row, n_col, grid);
        dfs(r, c-1, n_row, n_col, grid);
        dfs(r, c+1, n_row, n_col, grid);

    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n_row = grid.size();
        int n_col = grid[0].size();
        for (int i=0; i < n_row; i++){
            for (int j=0; j < n_col; j++){
                if (grid[i][j] == '1'){
                    cnt += 1;
                    dfs(i, j, n_row, n_col, grid);
                }
            }
        }
        return cnt;

    }
};
