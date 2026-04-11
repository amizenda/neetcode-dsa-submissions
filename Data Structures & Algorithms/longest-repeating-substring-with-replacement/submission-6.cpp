class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;

        for(int i = 0; i < s.size(); i++) {
            unordered_map<char, int> count;
            int maxFreq = 0;

            for(int j = i; j < s.size(); j++) {
                count[s[j]]++;
                maxFreq = max(maxFreq, count[s[j]]);

                if((j - i + 1) - maxFreq <= k) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};
