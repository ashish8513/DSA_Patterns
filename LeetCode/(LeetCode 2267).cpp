// 2267. Check if There Is a Valid Parentheses String Path

// A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

// It is ().
// It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
// It can be written as (A), where A is a valid parentheses string.
// You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:

// The path starts from the upper left cell (0, 0).
// The path ends at the bottom-right cell (m - 1, n - 1).
// The path only ever moves down or right.
// The resulting parentheses string formed by the path is valid.
// Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.


class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }
        bool vis[m][n][m + n];
        memset(vis, false, sizeof(vis));
        int dirs[3] = {1, 0, 1};
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> bool {
            if (vis[i][j][k]) {
                return false;
            }
            vis[i][j][k] = true;
            k += grid[i][j] == '(' ? 1 : -1;
            if (k < 0 || k > m - i + n - j) {
                return false;
            }
            if (i == m - 1 && j == n - 1) {
                return k == 0;
            }
            for (int d = 0; d < 2; ++d) {
                int x = i + dirs[d], y = j + dirs[d + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && dfs(x, y, k)) {
                    return true;
                }
            }
            return false;
        };
        return dfs(0, 0, 0);
    }
};