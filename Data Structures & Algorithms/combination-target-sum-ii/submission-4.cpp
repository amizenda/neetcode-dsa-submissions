class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> current;

        backtrack(candidates, target, 0, current, res);

        return res;
    }
private:
    void backtrack(vector<int>& candidates, int remain, int start, vector<int>& current, vector<vector<int>>& res) {
        if(remain == 0) {
            res.push_back(current);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {
            if(remain - candidates[i] < 0) return;

            if(i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            current.push_back(candidates[i]);
            
            backtrack(candidates, remain - candidates[i], i + 1, current, res);

            current.pop_back();
        }
    }
};
