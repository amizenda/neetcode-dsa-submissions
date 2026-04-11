class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxSeq = 1;
        int seq = 1;
        int i = 1;

        if(nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());

        while(i < nums.size()) {
            if(nums[i] != nums[i - 1]) {
                if(nums[i] == nums[i - 1] + 1) {
                    seq++;
                } else {
                    seq = 1;
                }

                maxSeq = max(maxSeq, seq);
            }
            i++;
        }

        return maxSeq;
    }
};
