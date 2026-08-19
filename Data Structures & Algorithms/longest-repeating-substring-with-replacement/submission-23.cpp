class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int res = 0;
        int maxF = 0;
        unordered_map<char, int> counts;
        
        for(int right = 0; right < s.size(); right++) {
            counts[s[right]]++;
            maxF = max(maxF, counts[s[right]]);

            if((right - left + 1) - maxF > k) {
                counts[s[left]]--;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};
