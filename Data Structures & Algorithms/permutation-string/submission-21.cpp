class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> count1;
        
        for(char c : s1) {
            count1[c]++;
        }

        int need = count1.size();
        for(int i = 0; i < s2.size() - s1.size() + 1; i++) {
            unordered_map<char, int> count2;

            int have = 0;
            for(int j = i; j < i + s1.size(); j++) {
                char c = s2[j];
                count2[c]++;

                if(count1[c] < count2[c]) break;
                if(count1[c] == count2[c]) have++;
                if(have == need) return true;
            }
        }

        return false;
    }
};
