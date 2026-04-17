struct TrieNode {
    TrieNode* children[26] = {nullptr};
    string* word = nullptr; // Lưu con trỏ tới từ hoàn chỉnh để lấy kết quả nhanh
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            TrieNode* curr = root;
            for (char c : w) {
                if (!curr->children[c - 'a']) curr->children[c - 'a'] = new TrieNode();
                curr = curr->children[c - 'a'];
            }
            curr->word = &w; 
        }

        vector<string> result;
        int rows = board.size(), cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root, result);
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& result) {
        char ch = board[r][c];
        if (ch == '#' || !node->children[ch - 'a']) return;

        node = node->children[ch - 'a'];
        if (node->word != nullptr) {
            result.push_back(*node->word);
            node->word = nullptr; 
        }

        board[r][c] = '#';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size()) {
                dfs(board, nr, nc, node, result);
            }
        }

        board[r][c] = ch;
    }
};