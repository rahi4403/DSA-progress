class Solution {
private:
    bool isSafe(int x, int y, vector<vector<int>>& visited,
                vector<vector<int>>& grid) {
        if ((x >= 0 && x < grid.size()) && (y >= 0 && y < grid[0].size()) &&
            visited[x][y] == 0 && grid[x][y] != -1) {
            return true;
        } else {
            return false;
        }
    }

private:
    void Solve(vector<vector<int>>& grid, int& ans, int x, int y,
               vector<vector<int>>& visited, int count) {
        count--;
        if (grid[x][y] == 2) {
            if (count == 0) {
                ans++;
            }
            return;
        }
        visited[x][y] = 1;
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy, visited, grid)) {
            Solve(grid, ans, newx, newy, visited, count);
        }

        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, visited, grid)) {
            Solve(grid, ans, newx, newy, visited, count);
        }
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, visited, grid)) {
            Solve(grid, ans, newx, newy, visited, count);
        }
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, visited, grid)) {
            Solve(grid, ans, newx, newy, visited, count);
        }
        visited[x][y] = 0;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0;
        int srcx, srcy;
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    srcx = i;
                    srcy = j;
                }
                if (grid[i][j] != -1) {
                    count++;
                }
            }
        }
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(), 0));
        Solve(grid, ans, srcx, srcy, visited, count);
        return ans;
    }
};