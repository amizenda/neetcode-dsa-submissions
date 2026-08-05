class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;
        int res = 0;

        int left = 0; int maxF = 0;

        for(int right = 0; right < s.size(); right++) {
            counts[s[right]]++;
            maxF = max(maxF, counts[s[right]]);

            while((right - left + 1) - maxF > k) {
                counts[s[left]]--;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};
