class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;

        for(auto x : nums) {
            freq[x]++;
        }

        vector<pair<int, int>> topFreq;
        for(auto [key, val] : freq) {
            topFreq.push_back({val, key});
        }

        sort(topFreq.rbegin(), topFreq.rend());
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(topFreq[i].second);
        }

        return res;
    }
};
