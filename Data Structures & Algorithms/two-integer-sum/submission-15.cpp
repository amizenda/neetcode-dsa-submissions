class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); i++) {
            int implement = target - nums[i];

            if(m.find(implement) != m.end()) {
                return {m[implement], i};
            } 

            m[nums[i]] = i;
        }

        return {};
    }
};
