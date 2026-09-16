class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> count1;
        unordered_map<char, int> count2;

        for(int i = 0; i < s.size(); i++) {
            count1[s[i]]++;
            count2[t[i]]++;
        }

        return count1 == count2;
    }
};
