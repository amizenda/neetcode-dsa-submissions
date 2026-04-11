class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> fre;
        for(int x : nums) {
            fre[x]++;
        }

        vector<pair<int, int>> topFre;
        for(auto [key, val] : fre) {
            topFre.push_back({val, key});
        }

        sort(topFre.rbegin(), topFre.rend());
        
        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(topFre[i].second);
        }

        return result;
    }
};
