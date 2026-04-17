class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        vector<string> phone = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> res;
        string current = "";

        backtrack(digits, 0, current, res, phone);

        return res;
    }
private:
    void backtrack(string& digits, int index, string& current, vector<string>& res, vector<string> phone) {
        if(index == digits.length()) {
            res.push_back(current);
            return;
        }

        string letters = phone[digits[index] - '0'];

        for(char c : letters) {
            current.push_back(c);

            backtrack(digits, index + 1, current, res, phone);

            current.pop_back();
        } 
    }
};
