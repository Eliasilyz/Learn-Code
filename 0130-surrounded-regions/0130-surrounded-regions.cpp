class Solution {
public:

    bool check(vector<vector<char>> &board, int x, int y)
    {
        return (x < 0 || x >= board.size() || y < 0 || y >= board[0].size());
    }
    void dfs2(vector<vector<char>> &board, int x, int y)
    {
        vector<int> arr = {-1, 0, 1, 0, -1};
        board[x][y] = 'X';
        for (int i = 0; i < arr.size() - 1; i++)
        {
            int _x = x + arr[i], _y = y + arr[i + 1];
            if(check(board, _x, _y))continue;
            if(board[_x][_y] == 'X')continue;
            dfs2(board, _x, _y);
        }
    }
    bool dfs(vector<vector<char>> &board, int x, int y, vector<vector<int>> &vis)
    {
        vector<int> arr = {-1, 0, 1, 0, -1};
        bool b1 = true;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            int _x = x + arr[i], _y = y + arr[i + 1];
            if (check(board, _x, _y))
            {
                b1 = false;
                continue;
            }
            if(vis[_x][_y])continue;
            if(board[_x][_y] == 'X')continue;
            vis[_x][_y] = 1;
            b1 = (b1 & dfs(board, _x, _y, vis));
        }
        return b1;
    }
    void solve(vector<vector<char>> &board)
    {
        vector<vector<int>> vis(board.size() + 1, vector<int>(board[0].size() + 1, 0));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'O')
                {
                    if (vis[i][j])
                        continue;
                    vis[i][j] = 1;
                    if(dfs(board, i, j, vis)){
                        dfs2(board, i, j);
                    }
                }
            }
        }
    }
};