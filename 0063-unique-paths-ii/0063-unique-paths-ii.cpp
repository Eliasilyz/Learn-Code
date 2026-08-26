int dp[101][101];
class Solution {
public:
    int helper(vector<vector<int>>& obstacleGrid, int x,int y){
        if(x >= obstacleGrid.size() || y >= obstacleGrid[0].size()){
            return 0;
        }
        if(obstacleGrid[x][y] == 1) return 0;
        if(x == obstacleGrid.size() - 1 && y == obstacleGrid[0].size() - 1){
            return 1;
        }
        if(dp[x][y] != -1)return dp[x][y];
        return dp[x][y] = helper(obstacleGrid,x + 1, y) + helper(obstacleGrid, x, y + 1);

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof dp);
        return helper(obstacleGrid, 0, 0);
    }
};