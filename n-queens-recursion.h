//https://oj.leetcode.com/problems/n-queens/

class Solution {
public:
    vector<string> board;
    vector<vector<bool> > assist;
    vector<vector<string> > ret;

    void setBoard(int x, int y) {
        board[x][y] = 'Q';
        assist[0][x] = true;
        assist[1][y] = true;

        int n = assist[0].size();
        assist[2][y-x+n-1] = true;
        assist[3][x+y] = true;
    }

    void resetBoard(int x, int y) {
        board[x][y] = '.';
        assist[0][x] = false;
        assist[1][y] = false;

        int n = assist[0].size();
        assist[2][y-x+n-1] = false;
        assist[3][x+y] = false;
    }

    void initBoard(int n) {
        assist.resize(4);
        assist[0].resize(n);//vertical
        assist[1].resize(n);//horizontal
        assist[2].resize(2*n-1);//lb2rt
        assist[3].resize(2*n-1);//lt2rb

        board.resize(n);
        for (int i = 0; i < n; i++) {
            board[i].resize(n);
            for (int j = 0; j < n; j++) {
                resetBoard(i, j);
            }
        }
    }

    bool isValid(int x, int y) {
        if (assist[0][x]) return false;
        if (assist[1][y]) return false;

        int n = assist[0].size();
        if (assist[2][y-x+n-1]) return false;
        if (assist[3][x+y]) return false;

        return true;
    }

    void helper(int n, int left, int start) {
        if (left == 0) {
            ret.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (board[start][i] == '.' && isValid(start, i)) {
                setBoard(start, i);
                helper(n, left-1, start+1);
                resetBoard(start, i);
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        if (n == 0) return ret;

        initBoard(n);
        helper(n, n, 0);

        return ret;
    }
};
