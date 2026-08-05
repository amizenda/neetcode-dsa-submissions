class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;
        int res = 0;

        int left = 0, maxLen = 0;

        for(int right = 0; right < s.size(); right++) {
            counts[s[right]]++;
            maxLen = max(maxLen, counts[s[right]]);

            while((right - left + 1) - maxLen > k) {
                counts[s[left]]--;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};
