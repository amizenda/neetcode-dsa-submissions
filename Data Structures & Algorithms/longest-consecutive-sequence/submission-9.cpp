class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxSeq = 1;
        int lSeq = 1;
        int i = 1;
        
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        while(i < nums.size()) {
            if(nums[i] != nums[i - 1]) {
                if((nums[i] - nums[i - 1]) == 1) {
                    lSeq += 1;
                    maxSeq = max(maxSeq, lSeq);
                } else {
                    lSeq = 1;
                }
            }

            i += 1;
        }

        return maxSeq;
    }
};
