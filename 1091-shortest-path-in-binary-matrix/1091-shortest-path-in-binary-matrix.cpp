class Solution {
public:
    vector<vector<int>> arr = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = 1;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        vis[0][0] = 1;
        queue<pair<int, int>> q;
        if(grid[0][0] == 0)q.push({0, 0});

        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                int x = q.front().first, y = q.front().second;
                q.pop();
                cout<<x<<" "<<y<<endl;
                for(int i = 0; i < 8; i ++){
                    int _x =  x + arr[i][0], _y = y + arr[i][1];
                    if(x == grid.size() - 1 && y == grid[0].size() - 1)return ans;
                    if(_x >=0 && _x < grid.size() && _y >=0 && _y < grid[0].size() && !vis[_x][_y] && grid[_x][_y] == 0){
                        vis[_x][_y] = 1;
                        q.push({_x, _y});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};