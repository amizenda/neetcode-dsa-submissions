class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<char> countS1(26, 0);
        vector<char> countS2(26, 0);

        for(char c : s1) countS1[c - 'a']++;

        int left = 0;

        for(int right = 0; right < s2.size(); right++) {
            countS2[s2[right] - 'a']++;

            if(right - left + 1 > s1.size()) {
                countS2[s2[left] - 'a']--;
                left++;
            }

            if(countS1 == countS2) return true;

        }

        return false;
    }
};
