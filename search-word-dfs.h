//https://oj.leetcode.com/problems/word-search/

class Solution {
public:
    vector<vector<bool> > vis;

    bool search(vector<vector<char> > &board, string word, int i, int j) {
        if (word.length() == 0) return true;
        if (word[0] != board[i][j]) return false;
        if (vis[i][j]) return false;

        if (word.length() == 1) return true;
        vis[i][j] = true;
        word = word.substr(1);

        if (i != 0 && !vis[i-1][j] && board[i-1][j] == word[0] && search(board, word, i-1, j)) {
            vis[i][j] = false;
            return true;
        }

        if (i != board.size()-1 && !vis[i+1][j] && board[i+1][j] == word[0] && search(board, word, i+1, j)) {
            vis[i][j] = false;
            return true;
        }

        if (j != 0 && !vis[i][j-1] && board[i][j-1] == word[0] && search(board, word, i, j-1)) {
            vis[i][j] = false;
            return true;
        }

        if (j != board[0].size() && !vis[i][j+1] && board[i][j+1] == word[0] && search(board, word, i, j+1)) {
            vis[i][j] = false;
            return true;
        }

        vis[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char> > &board, string word) {
        if (word.length() == 0) return false;

        vis.resize(board.size());
        for (int i = 0; i < vis.size(); i++) {
            vis[i].resize(board[0].size());
            for (int j = 0; j < vis[i].size(); j++) {
                vis[i][j] = false;
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (word[0] == board[i][j] && search(board, word, i, j)) return true;
            }
        }

        return false;
    }
};
