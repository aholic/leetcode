//https://oj.leetcode.com/problems/sudoku-solver/

class Solution {
public:
    bool validLine(const vector<vector<char> > &board, int line) {
        bool ext[10];
        memset(ext, 0, sizeof(ext));
        for (int i = 0; i < 9; i++) {
            if (board[line][i] != '.' && ext[board[line][i] - '0']) return false;
            if (board[line][i] != '.') ext[board[line][i] - '0'] = true;
        }
        return true;
    }

    bool validRow(const vector<vector<char> > &board, int row) {
        bool ext[10];
        memset(ext, 0, sizeof(ext));
        for (int i = 0; i < 9; i++) {
            if (board[i][row] != '.' && ext[board[i][row] - '0']) return false;
            if (board[i][row] != '.') ext[board[i][row] - '0'] = true;
        }
        return true;
    }

    bool validBlock(const vector<vector<char> > &board, int ltx, int lty) {
        bool ext[10];
        memset(ext, 0, sizeof(ext));
        for (int i = ltx; i < ltx + 3; i++) {
            for (int j = lty; j < lty + 3; j++) {
                if (board[i][j] != '.' && ext[board[i][j] - '0']) return false;
                if (board[i][j] != '.') ext[board[i][j] - '0'] = true;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; i++) {
            if(!validLine(board, i)) return false;
        }
        for (int i = 0; i < 9; i++) {
            if(!validRow(board, i)) return false;
        }
        if (!validBlock(board, 0, 0)) return false;
        if (!validBlock(board, 0, 3)) return false;
        if (!validBlock(board, 0, 6)) return false;
        if (!validBlock(board, 3, 0)) return false;
        if (!validBlock(board, 3, 3)) return false;
        if (!validBlock(board, 3, 6)) return false;
        if (!validBlock(board, 6, 0)) return false;
        if (!validBlock(board, 6, 3)) return false;
        if (!validBlock(board, 6, 6)) return false;
        return true;
    }
    bool helper(vector<vector<char> > &board) {
        int i, j;
        for (i = 0; i < board.size(); i++) {
            for (j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') break;
            }
            if (j != board[0].size()) break;;
        }

        if (i == board.size() && j == board.size()) return true;

        for (int k = 1; k <= 9; k++) {
            board[i][j] = '0' + k;
            if (isValidSudoku(board) && helper(board)) return true;
            board[i][j] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char> > &board) {
        helper(board);
    }
};
