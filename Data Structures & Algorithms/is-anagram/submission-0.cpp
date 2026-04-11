class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> vs, vt;
        for(auto r : s) {
            vs[r]++;
        }
        for(auto r : t) {
            vt[r]++;
        }
        for(auto [key, val] : vs) {
            if(vt[key] != val) return false;
        }
        for(auto [key, val] : vt) {
            if(vs[key] != val) return false;
        }

        return true;
    }
};
