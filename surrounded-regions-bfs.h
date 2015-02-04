//https://oj.leetcode.com/problems/surrounded-regions/

class Solution {
public:
    void pushQ(int x, int y, queue<pair<int, int>>& q, vector<vector<char>> &board, vector<vector<bool>>& vis) {
        if (board[x][y] == 'O' && !vis[x][y]) {
            q.push(make_pair(x, y));
            vis[x][y] = true;
        }
    }
    void bfs(int x, int y, vector<vector<char>> &board, vector<vector<bool>>& vis) {
        vis[x][y] = true;
        if (board.size() == 1 && board[0].size() == 1) return;
        if (board.size() == 1) {
            if (y == 0) {
                while (y < board[x].size() && board[x][y] == 'O') {
                    vis[x][y++] = true;
                }
            } else {
                while (y >= 0 && board[x][y] == 'O') {
                    vis[x][y--] = true;
                }
            }
            return;
        }
        if (board[x].size() == 1) {
            if (x == 0) {
                while (x < board.size() && board[x][y] == 'O') {
                    vis[x++][y] = true;
                }
            } else {
                while (x >= 0 && board[x][y] == 'O') {
                    vis[x--][y] = true;
                }
            }
            return;
        }

        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        while (!q.empty()) {
            int tmpx = q.front().first;
            int tmpy = q.front().second;
            q.pop();

            if (tmpx == 0 && tmpy == 0) {
                pushQ(tmpx, tmpy+1, q, board, vis);
                pushQ(tmpx+1, tmpy, q, board, vis);
            } else if (tmpx == 0 && tmpy == board[tmpx].size()-1) {
                pushQ(tmpx, tmpy-1, q, board, vis);
                pushQ(tmpx+1, tmpy, q, board, vis);
            } else if (tmpx == board.size()-1 && tmpy == 0) {
                pushQ(tmpx, tmpy+1, q, board, vis);
                pushQ(tmpx-1, tmpy, q, board, vis);
            } else if (tmpx == board.size()-1 && tmpy == board[tmpx].size()-1) {
                pushQ(tmpx, tmpy-1, q, board, vis);
                pushQ(tmpx-1, tmpy, q, board, vis);
            } else if (tmpx == 0) {
                pushQ(tmpx, tmpy-1, q, board, vis);
                pushQ(tmpx, tmpy+1, q, board, vis);
                pushQ(tmpx+1, tmpy, q, board, vis);
            } else if (tmpy == 0) {
                pushQ(tmpx-1, tmpy, q, board, vis);
                pushQ(tmpx, tmpy+1, q, board, vis);
                pushQ(tmpx+1, tmpy, q, board, vis);
            } else if (tmpx == board.size()-1) {
                pushQ(tmpx, tmpy-1, q, board, vis);
                pushQ(tmpx-1, tmpy, q, board, vis);
                pushQ(tmpx, tmpy+1, q, board, vis);
            } else if (tmpy == board[tmpx].size()-1) {
                pushQ(tmpx, tmpy-1, q, board, vis);
                pushQ(tmpx-1, tmpy, q, board, vis);
                pushQ(tmpx+1, tmpy, q, board, vis);
            } else {
                pushQ(tmpx, tmpy-1, q, board, vis);
                pushQ(tmpx-1, tmpy, q, board, vis);
                pushQ(tmpx, tmpy+1, q, board, vis);
                pushQ(tmpx+1, tmpy, q, board, vis);
            }
        }
    }

    void solve(vector<vector<char>> &board) {
        if (board.size() == 0) return;

        vector<vector<bool>> vis(board.size());
        for (int i = 0; i < board.size(); i++) {
            vis[i].resize(board[i].size());
            for (int j = 0; j < board[i].size(); j++) {
                vis[i][j] = false;
            }
        }

        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 'O' && !vis[0][i]) {
                bfs(0, i, board, vis);
            }
        }

        for (int i = 1; i < board.size() - 1; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                bfs(i, 0, board, vis);
            }
            if (board[i][board[i].size()-1] == 'O' && !vis[i][board[i].size()-1]) {
                bfs(i, board[i].size()-1, board, vis);
            }
        }

        for (int i = 0; i < board[board.size()-1].size(); i++) {
            if (board[board.size()-1][i] == 'O' && !vis[board.size()-1][i]) {
                bfs(board.size()-1, i, board, vis);
            }
        }

        for (int i = 0; i < vis.size(); i++) {
            for (int j = 0; j < vis[i].size(); j++) {
                board[i][j] = vis[i][j] ? 'O' : 'X';
            }
        }
    }
};
