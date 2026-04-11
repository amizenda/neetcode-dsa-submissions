class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        set<vector<int>> threeSum;
        for(int i = 0 ; i < n - 2; i++) {
            int target = nums[i] * (-1);
            int left = i + 1;
            int right = n - 1;

            while(left < right) {
                int sum = nums[left] + nums[right];
                if(target == sum) threeSum.insert({nums[i], nums[left], nums[right]});

                if(target < sum) {
                    right--;
                } else { 
                    left++;
                }
            }
        }

        for(auto x : threeSum) {
            res.push_back(x);
        }

        return res;
    }
};
