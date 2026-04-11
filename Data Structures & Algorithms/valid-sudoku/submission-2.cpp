class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool cols[9][10] = {false};
        bool rows[9][10] = {false};
        bool blocks[9][10] = {false};

        for(int i = 0; i < 9; i ++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '0';
                int k = (i / 3) * 3 + (j / 3);

                if(rows[i][num] || cols[j][num] || blocks[k][num]) {
                    return false;
                }

                rows[i][num] = true;
                cols[j][num] = true;
                blocks[k][num] = true;
            }
        }
        return true;
    }
};
