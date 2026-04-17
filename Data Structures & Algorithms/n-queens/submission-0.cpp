class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        unordered_set<int> cols;
        unordered_set<int> diag1;
        unordered_set<int> diag2;

        backtrack(0, n, board, res, cols, diag1, diag2);

        return res;
    }
private:
    void backtrack(int r, int n, vector<string>& board, vector<vector<string>>& res, unordered_set<int>& cols, unordered_set<int>& diag1, unordered_set<int>& diag2) {
        if(r == n) {
            res.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++) {
            if(cols.count(c) || diag1.count(r + c) || diag2.count(r - c)) {
                continue;
            }

            board[r][c] = 'Q';
            cols.insert(c);
            diag1.insert(r + c);
            diag2.insert(r - c);

            backtrack(r + 1, n, board, res, cols, diag1, diag2);

            board[r][c] = '.';
            cols.erase(c);
            diag1.erase(r + c);
            diag2.erase(r - c);
        }
    }
};
