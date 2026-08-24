class Solution {
public:
vector<int> d4 = {-1, 0, 1, 0, -1};
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis,queue<pair<int, int>> &q, int x, int y){
        vis[x][y] = 1;
        q.push({x, y});
        for(int i = 0; i < 4; i ++){
            int _x = x + d4[i], _y = y + d4[i + 1];
            if(_x >=0 && _x< grid.size() && _y>=0 && _y< grid[0].size() && grid[_x][_y] == 1 && !vis[_x][_y]){
                dfs(grid, vis, q, _x, _y);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0)continue;
                queue<pair<int, int>> q;
                dfs(grid, vis, q, i, j);
                int level = 0;
                while(!q.empty()){
                    level++;
                    int sz = q.size();
                    for(int k = 0; k < sz; k++){
                        auto f = q.front();
                        q.pop();
                        for(int l = 0; l < 4; l++){
                            int _x = f.first + d4[l], _y = f.second + d4[l + 1];
                            if(_x >=0 && _x< grid.size() && _y>=0 && _y< grid[0].size()&& !vis[_x][_y]){
                                if(grid[_x][_y] == 1)return level - 1;
                                vis[_x][_y] = 1;
                                q.push({_x, _y});
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};