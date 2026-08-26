class Solution {
public:
  int helper(vector<vector<char>> &board, string &word, int x, int y, string &temp, vector<vector<int>> &visited, int ind)
    {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return false;
        if (visited[x][y] == 1)
            return false;
        if (board[x][y] != word[ind])
            return false;
        temp.push_back(board[x][y]);
        visited[x][y] = 1;
        if (temp == word)
            return true;

        bool b1 = helper(board, word, x - 1, y, temp, visited, ind + 1);
        bool b2 = helper(board, word, x + 1, y, temp, visited, ind + 1);
        bool b3 = helper(board, word, x, y - 1, temp, visited, ind + 1);
        bool b4 = helper(board, word, x, y + 1, temp, visited, ind + 1);
        if (b1 || b2 || b3 || b4)
            return true;
        visited[x][y] = 0;
        temp.pop_back();
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        string temp = "";
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vector<vector<int>> visited(n, vector<int>(m, 0));
                bool b1 = helper(board, word, i, j, temp, visited, 0);
                if (b1)
                    return true;
            }
        }
        return false;
    }
};