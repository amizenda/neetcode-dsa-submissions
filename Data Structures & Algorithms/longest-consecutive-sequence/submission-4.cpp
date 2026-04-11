class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxSeq = 1;

        if(nums.empty()) return 0;

        unordered_set<int> checker(nums.begin(), nums.end());

        for(auto num : checker) {
            if(checker.find(num - 1) != checker.end()) continue;

            int seq = 1;
            while(checker.find(num + 1) != checker.end()) {
                seq++;
                num++;
            }
            maxSeq = max(maxSeq, seq);
        }

        return maxSeq;
    }
};
