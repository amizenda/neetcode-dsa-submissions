class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> counts;
        int left = 0;
        int maxLen = 0;
        
        for(int right = 0; right < s.size(); right++) {
            counts[s[right]]++;

            while(counts[s[right]] > 1) {
                counts[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
