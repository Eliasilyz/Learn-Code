int visited[15][15];
class Solution {
public:
    void helper(vector<vector<int>> &matrix, vector<int> &ans, int x, int y, int &D)
    {
        if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()) return;
        if (visited[x][y] == 1)
            return;
        ans.push_back(matrix[x][y]);
        visited[x][y] = 1;
        if (D == 0)
        {
            if (x == 0 || visited[x - 1][y] == 1)
            {
                y++;
                D = ++D % 4;
                helper(matrix, ans, x, y, D);
            }
            else
            {
                helper(matrix, ans, x - 1, y, D);
            }
        }
        else if (D == 1)
        {
            if (y == matrix[0].size() - 1 || visited[x][y + 1] == 1)
            {
                x++;
                D = ++D % 4;
                helper(matrix, ans, x, y, D);
            }
            else
            {
                helper(matrix, ans, x, y + 1, D);
            }
        }
        else if (D == 2)
        {
            if (x == matrix.size() - 1 || visited[x + 1][y] == 1)
            {
                y--;
                D = ++D % 4;
                helper(matrix, ans, x, y, D);
            }
            else
            {
                helper(matrix, ans, x + 1, y, D);
            }
        }
        else if (D == 3)
        {
            if (y == 0 || visited[x][y - 1] == 1)
            {
                x--;
                D = ++D % 4;
                helper(matrix, ans, x, y, D);
            }
            else
            {
                helper(matrix, ans, x, y - 1, D);
            }
        }
        return;
    }
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        memset(visited, 0, sizeof(visited));
        vector<int> ans;
        int D = 1;
        helper(matrix, ans, 0, 0, D);
        return ans;
    }
};