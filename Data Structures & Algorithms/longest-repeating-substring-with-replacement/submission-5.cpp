class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0;
        int maxFre = 0;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;

            maxFre = max(maxFre, count[s[right] - 'A'] );

            while((right - left + 1) - maxFre > k) {
                count[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
