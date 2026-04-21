class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        vector<vector<int>> res;
        backtrack(candidates, target, 0, current, res);
        return res;
    }
private:
    void backtrack(vector<int>& nums, int remain, int start, vector<int>& current, vector<vector<int>>& res) {
        if(remain == 0) {
            res.push_back(current);
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            if(nums[i] > remain) break;

            if(i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            current.push_back(nums[i]);

            backtrack(nums, remain - nums[i], i + 1, current, res);

            current.pop_back();
        }
    }
};
