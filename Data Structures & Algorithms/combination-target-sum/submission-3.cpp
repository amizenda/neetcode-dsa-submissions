class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> current;

        backtrack(nums, target, 0, current, res);

        return res;
    }
private:
    void backtrack(vector<int>& nums, int remain, int start, vector<int>& current, vector<vector<int>>& res) {
        if(remain == 0) {
            res.push_back(current);
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            if(remain - nums[i] < 0) {
                continue;
            }

            current.push_back(nums[i]);

            backtrack(nums, remain - nums[i], i, current, res);

            current.pop_back();
        }
    }
};
