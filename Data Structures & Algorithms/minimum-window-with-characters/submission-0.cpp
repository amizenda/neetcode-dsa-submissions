class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        vector<int> targetCount(128, 0);
        vector<int> windowCount(128, 0);

        for (char c : t) targetCount[c]++;

        int need = 0;
        for (int i = 0; i < 128; i++) {
            if (targetCount[i] > 0) need++;
        }

        int have = 0;
        int left = 0;
        int minLen = INT_MAX;
        int startIdx = -1;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            windowCount[c]++;

            if (targetCount[c] > 0 && windowCount[c] == targetCount[c]) {
                have++;
            }

            while (have == need) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char leftChar = s[left];
                windowCount[leftChar]--;
                
                if (targetCount[leftChar] > 0 && windowCount[leftChar] < targetCount[leftChar]) {
                    have--;
                }
                left++;
            }
        }

        return (startIdx == -1) ? "" : s.substr(startIdx, minLen);
    }
};