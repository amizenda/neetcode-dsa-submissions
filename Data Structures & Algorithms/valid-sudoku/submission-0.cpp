class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            bool check[10] = {false};
            for(int j = 0; j < 9; j++) {
                if(isdigit(board[i][j])) {
                    int num = board[i][j] - '0';
                    if(check[num]) return false;
                    check[num] = true;
                }
            }
        }
        for(int j =0; j < 9; j++) {
            bool check[10] = {false};
            for(int i = 0; i < 9; i++) {
                if(isdigit(board[i][j])) {
                    int num = board[i][j] - '0';
                    if(check[num]) return false;
                    check[num] = true;
                }
            }
        }
        for (int block = 0; block < 9; block++) {
            bool check[10] = {false};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (block / 3) * 3 + i;
                    int col = (block % 3) * 3 + j;
            
                    if (isdigit(board[row][col])) {
                    int num = board[row][col] - '0';
                    if (check[num]) return false;
                    check[num] = true;
                    }
                }
            }
        }
        return true;
    }
};
