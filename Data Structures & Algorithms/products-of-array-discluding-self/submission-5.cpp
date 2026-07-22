class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int suffix[n], prefix[n];

        for(int i = 0; i < nums.size(); i++) {
            suffix[i] = prefix[i] = 1;
        }

        for(int i = 1; i < n; i++) {
            suffix[i] = suffix[i - 1] * nums[i - 1];
        }

        for(int i = n - 2; i >= 0; i--) {
            prefix[i] = prefix[i + 1] * nums[i + 1];
        }

        vector<int> result;
        for(int i = 0; i < n; i++) {
            result.push_back(suffix[i] * prefix[i]);
        }

        return result;
    }
};
