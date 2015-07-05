// Source: 
// 2015/7/5

// Reference https://leetcode.com/discuss/23901/my-short-solution-by-c-o-n2
// run time is short
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        char row[9][9] = {0}, col[9][9] = {0}, cel[9][9] = {0};
        for (size_t i = 0; i < board.size(); ++i)
            for (size_t j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0' - 1, k = i/3 * 3 + j/3;
                if (row[i][num] || col[j][num] || cel[k][num]) return false;
                else row[i][num] = col[j][num] = cel[k][num] = 1;
            }
        return true;
    }
}; // 12ms

// Reference https://github.com/pezy/LeetCode/tree/master/064.%20Valid%20Sudoku
// Easy to understand
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<size_t, std::unordered_set<char>> row_map, col_map, cel_map;
        for (size_t i = 0; i < board.size(); ++i)
            for (size_t j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') continue;
                if (!row_map[i].insert(board[i][j]).second) return false;
                if (!col_map[j].insert(board[i][j]).second) return false;
                if (!cel_map[i/3 * 3 + j/3].insert(board[i][j]).second) return false;
            }
        return true;
    }
}; // 28ms

