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

        vector<int> result;

        for(int i = 0; i < k; i++) {
            result.push_back(topFreq[i].second);
        }

        return result;
    }
};
