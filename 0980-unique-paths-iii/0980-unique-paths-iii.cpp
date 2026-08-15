class Solution {
private:
    bool isSafe(int x, int y, vector<vector<int>>& visited,
                vector<vector<int>>& grid) {
        if ((x >= 0 && x < grid.size()) && (y >= 0 && y < grid[0].size()) && visited[x][y] == 0 && grid[x][y] != -1) { //row cant be negative and should be within the size of the grid maze ,same with columns,and visited==0(0 means not visited)checks if we have already visited the cell,and -1 checks obstacle since we cannot go to the cell having value -1,we can only move in 0,1,2
            return true;
        } else {
            return false;
        }
    }

private:
    void Solve(vector<vector<int>>& grid, int& ans, int x, int y,vector<vector<int>>& visited, int count) { //grid is the original maze,ans is number of valid paths found,visited is all the paths we have visited,count shows how many cells are relevant to us
        count--; //reduces count for each cell we visit,so that we strike it from our count list. One cell visited,count--,so it is removed from the relevant cells list since already visited
        if (grid[x][y] == 2) { //2 is the destination so the moment after visiting all the relevant cells the cell drops to 2,and count drops to 0,i.e,we have reached the ending cell, then we have visited all the relevant cells,so ans++,we have our ans
            if (count == 0) {
                ans++;
            }
            return;//since we reached 2,stop exploring possible paths now
        }
        visited[x][y] = 1; //marks the current cell as visited( 0 is not visited,1 is visited)
        int newx = x + 1; //moves down,row changes but column doesnt 
        int newy = y;
        if (isSafe(newx, newy, visited, grid)) { //is the cell safe to visit
            Solve(grid, ans, newx, newy, visited, count); //recursive function to call Solve
        }
        newx = x;//moves left
        newy = y - 1;
        if (isSafe(newx, newy, visited, grid)) {
            Solve(grid, ans, newx, newy, visited, count);
        }
        newx = x; //moves right
        newy = y + 1;
        if (isSafe(newx, newy, visited, grid)) {
            Solve(grid, ans, newx, newy, visited, count);
        }
        newx = x - 1; //moves up
        newy = y;
        if (isSafe(newx, newy, visited, grid)) {
            Solve(grid, ans, newx, newy, visited, count);
        }
        visited[x][y] = 0; //backtracking. After visiting a cell,we revert it to not visited,so that it can be used for other possible paths as well
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0;
        int srcx, srcy;
        int count = 0;
        for (int i = 0; i < grid.size(); i++) { //for traversing through rows & columns
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) { //to find the starting point
                    srcx = i;//after finding the starting point,we store the coordinates
                    srcy = j;
                }
                if (grid[i][j] != -1) {//every cell which is not an obstacle(-1) has to be counted,since they serve as possible paths
                    count++;
                }
            }
        }
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0)); //to create a 2d array of same size as grid
        Solve(grid, ans, srcx, srcy, visited, count);//then it recursively calls again
        return ans;
    }
};