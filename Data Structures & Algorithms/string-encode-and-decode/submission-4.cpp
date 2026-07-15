class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString;
        for(int i = 0; i < strs.size(); i++) {
            encodedString += to_string(strs[i].size()) + '#' + strs[i];
        }

        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while(i < s.size()) {
            int j = i;

            while(s[j] != '#') {
                j++;
            }

            int l = stoi(s.substr(i, j - i));
            strs.push_back(s.substr(j + 1, l));
            i = j + l + 1;
        }

        return strs;
    }
};
