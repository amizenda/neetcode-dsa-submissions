class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int res = 0;
        unordered_map<char, int> counts;

        for(int right = 0; right < s.size(); right++) {
            counts[s[right]]++;

            while(counts[s[right]] > 1) {
                counts[s[left]]--;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};
