class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> groups;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            int target = nums[i] * (-1);

            while(left < right) {
                int sum = nums[left] + nums[right];
                
                if(sum == target) groups.insert({nums[i], nums[left], nums[right]});

                if(sum > target) right--;
                else left++;
            }
        }

        vector<vector<int>> result;
        
        for(auto x : groups) {
            result.push_back(x);
        }

        return result;
    }
};
