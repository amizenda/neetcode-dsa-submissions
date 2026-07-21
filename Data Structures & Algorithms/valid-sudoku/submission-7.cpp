class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][10] = {false};
        int cols[9][10] = {false};
        int blocks[9][10] = {false};

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '0';
                int k = (i / 3) * 3 + (j /3);

                if(cols[i][num] || rows[j][num] || blocks[k][num]) return false;

                cols[i][num] = rows[j][num] = blocks[k][num] = true;
            }
        }

        return true;
    }
};
