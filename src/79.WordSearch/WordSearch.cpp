// Source: https://leetcode.com/problems/word-search/
// 2015/7/22

// Reference https://leetcode.com/discuss/27445/my-19ms-accepted-c-code
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board.front().size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (rsearch(board, word, 0, i, j))
                    return true;
        return false;
    }
private:
    int m, n;
    bool rsearch(vector<vector<char>>& board, const string& word, int ix, int x, int y) {
        if (x<0 || y<0 || x>=m || y>=n || || board[x][y] == '\0' || board[x][y] != word[ix]) return false;
        ++ix;
        if (ix == word.size()) return true;
        char t = board[x][y];
        board[x][y] = '\0';
        if (rsearch(board, word, ix, x-1, y) || rsearch(board, word, ix, x+1, y)
            || rsearch(board, word, ix, x, y-1) || rsearch(board, word, ix, x, y+1))
            return true;
        board[x][y] = t;
        return false;
    }
}; // 28ms