class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;

        backtrack(s, 0, current, res);

        return res;
    }
private:
    void backtrack(string s, int start, vector<string>& current, vector<vector<string>>& res) {
        if(start == s.length()) {
            res.push_back(current);
            return;
        }

        for(int i = start; i < s.length(); i++) {
            if(isPalindrome(s, start, i)) {
                current.push_back(s.substr(start, i - start + 1));

                backtrack(s, i + 1, current, res);

                current.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int low, int high) {
        while(low < high) {
            if(s[low++] != s[high--]) return false;
        }

        return true;
    }
};
