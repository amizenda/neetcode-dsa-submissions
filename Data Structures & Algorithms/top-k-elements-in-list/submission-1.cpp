class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fre;
        for(int x : nums) {
            fre[x]++;
        }
        vector<pair<int, int>> topFre;
        for(auto& i : fre) {
            topFre.push_back({i.second, i.first});
        }
        sort(topFre.rbegin(), topFre.rend());
        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(topFre[i].second);
        }
        return result;
    }
};
