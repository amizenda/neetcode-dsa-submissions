//brute force
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int n = s.size();
        for(int i = 0; i < s.size(); i++) {
            unordered_set<char> charSet;
            for(int j = i; j < s.size(); j++) {
                if(charSet.find(s[j]) != charSet.end()) {
                    break;
                }
                charSet.insert(s[j]);
            }
            maxLen = max(maxLen, (int)charSet.size());
        }

        return maxLen;
    }
};
