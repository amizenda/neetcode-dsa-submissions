class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for(auto x : strs) {
            string key = x;

            sort(key.begin(), key.end());
            groups[key].push_back(x);
        }

        vector<vector<string>> res;

        for(auto [key, val] : groups) {
            res.push_back(val);
        }

        return res;
    }
};
