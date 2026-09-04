class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxF = 0;
        int maxLen = 0;
        unordered_map<char, int> counts;

        for(int right = 0; right < s.size(); right++) {
            counts[s[right]]++;
            maxF = max(maxF, counts[s[right]]);

            if((right - left + 1) - maxF > k) {
                counts[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
