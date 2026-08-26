class Solution {
public:
    int n, m, tot = 0;
    vector<int> arr = {-1, 0, 1, 0, -1};
    int helper(vector<vector<int>> &grid, vector<vector<int>> &vis, int x, int y, int cnt){
        if(grid[x][y] == 2){
            if(cnt == n * m - tot)return 1;
            else return 0;
        }
        vis[x][y] = 1;
        int ans = 0;
        for(int i = 0; i < 4; i ++){
            int _x = x + arr[i], _y = y + arr[i + 1];
            if(_x >=0 && _x < n && _y>=0 &&_y <m &&!vis[_x][_y] && grid[_x][_y] != -1){
                ans += helper(grid, vis, _x, _y, cnt + 1);
            }
        }
        vis[x][y] = 0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        tot = 0;
        for(int i= 0 ; i < n;i++)for(int j = 0; j < m;j++)if(grid[i][j] == -1)tot++;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j++){
                vector<vector<int>> vis(n, vector<int>(m, 0));
                if(grid[i][j] == 1){
                    return helper(grid, vis, i, j, 1);
                }
            }
        }
        return -1;
    }
};