class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for(string x : strs) {
            encoded_string += to_string(x.size()) + '#' + x;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while(i < s.size()) {
            int j = i;
            while(s[j] != '#') j++;

            int l = stoi(s.substr(i, j - i));
            strs.push_back(s.substr(j + 1, l));
            i = j + 1 + l;
        }
        return strs;
    }
};
