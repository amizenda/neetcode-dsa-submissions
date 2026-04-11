class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> checker(nums.begin(), nums.end());
        int maxSeq = 0;
        int seq = 1;
        int tmp;
        for(auto num : checker) {
            if(checker.find(num - 1) != checker.end()) continue;

            seq = 1;
            tmp = num;
            while(checker.find(num + 1) != checker.end()) {
                seq++;
                num++;
            }
            maxSeq = max(maxSeq, seq);
        }
        return maxSeq;
    }
};
