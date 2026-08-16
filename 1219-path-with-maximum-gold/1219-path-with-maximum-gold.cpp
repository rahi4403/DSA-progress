class Solution {
    private:
    bool isSafe(int x, int y, vector<vector<int>>& visited,
                vector<vector<int>>& grid) {
        if ((x >= 0 && x < grid.size()) && (y >= 0 && y < grid[0].size()) && visited[x][y] == 0 && grid[x][y]>0) { 
            return true;
        } else {
            return false;
        }
                }
                void Solve(vector<vector<int>>& grid, int& ans, int x, int y,vector<vector<int>>& visited, int gold) { 
        visited[x][y] = 1; 
        gold+=grid[x][y];
        ans=max(ans,gold);
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy, visited, grid)) { 
            Solve(grid, ans, newx, newy, visited, gold); 
        }
        newx = x;//moves left
        newy = y - 1;
        if (isSafe(newx, newy, visited, grid)) {
            Solve(grid, ans, newx, newy, visited, gold);
        }
        newx = x; //moves right
        newy = y + 1;
        if (isSafe(newx, newy, visited, grid)) {
            Solve(grid, ans, newx, newy, visited, gold);
        }
        newx = x - 1; //moves up
        newy = y;
        if (isSafe(newx, newy, visited, grid)) {
            Solve(grid, ans, newx, newy, visited, gold);
        }
        visited[x][y] = 0; 
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
       int ans = 0;
       vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
       for(int i=0;i<grid.size();i++){
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]>0) { 
        Solve(grid, ans, i,j, visited,0);
                }
            }
       }
        return ans; 
    }
};