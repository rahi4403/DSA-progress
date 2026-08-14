class Solution {
private:
    bool isSafe(int x, int y, int rows, int cols,
                vector<vector<char>>& board,
                vector<vector<int>>& visited,
                char target) {

        if(x >= 0 && x < rows &&
           y >= 0 && y < cols &&
           visited[x][y] == 0 &&
           board[x][y] == target) {
            return true;
        }

        return false;
    }

    bool Solve(vector<vector<char>>& board, string word,
               int index, int x, int y,
               vector<vector<int>>& visited) {

        // We have matched the entire word
        if(index == word.length()) {
            return true;
        }

        int rows = board.size();
        int cols = board[0].size();

        visited[x][y] = 1;

        // Down
        int newx = x + 1;
        int newy = y;

        if(isSafe(newx, newy, rows, cols, board, visited, word[index])) {
            if(Solve(board, word, index + 1, newx, newy, visited))
                return true;
        }

        // Left
        newx = x;
        newy = y - 1;

        if(isSafe(newx, newy, rows, cols, board, visited, word[index])) {
            if(Solve(board, word, index + 1, newx, newy, visited))
                return true;
        }

        // Right
        newx = x;
        newy = y + 1;

        if(isSafe(newx, newy, rows, cols, board, visited, word[index])) {
            if(Solve(board, word, index + 1, newx, newy, visited))
                return true;
        }

        // Up
        newx = x - 1;
        newy = y;

        if(isSafe(newx, newy, rows, cols, board, visited, word[index])) {
            if(Solve(board, word, index + 1, newx, newy, visited))
                return true;
        }

        // Backtrack
        visited[x][y] = 0;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        // Try starting from every cell
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(board[i][j] == word[0]) {

                    if(Solve(board, word, 1, i, j, visited))
                        return true;
                }
            }
        }

        return false;
    }
};