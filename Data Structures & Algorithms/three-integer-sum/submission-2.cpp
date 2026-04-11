class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> threeSum;
        for(int i = 0; i < n - 2; i++) {
            int target = nums[i] * (-1);
            int left = i + 1;
            int right = n - 1;
            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum == target) {
                    threeSum.insert({nums[i], nums[left], nums[right]});
                    // break;
                }
                if(sum > target) right--;
                else left++;
            }
        }
        vector<vector<int>> result;
        for(auto x : threeSum) {
            result.push_back(x);
        }
        return result;
    }
};
