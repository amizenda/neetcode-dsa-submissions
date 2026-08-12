class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for(char c : s1) {
            count1[c - 'a']++;
        }

        int left = 0;
        for(int right = 0; right < s2.size(); right++) {
            count2[s2[right] - 'a']++;

            if(right - left + 1 > s1.size()) {
                count2[s2[left] - 'a']--;
                left++;
            }

            if(count1 == count2) return true; 
        }

        return false;
    }
};
