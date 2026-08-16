class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int lSeq = 1, maxSeq = 1;
        
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i - 1]) {
                if(nums[i] - nums[i - 1] == 1) {
                    lSeq++;
                    maxSeq = max(maxSeq, lSeq);
                } else {
                    lSeq = 1;
                }
            }
        }

        return maxSeq;
    }
};
