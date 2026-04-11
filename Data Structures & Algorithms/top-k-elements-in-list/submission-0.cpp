class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int,int> fre;
        sort(nums.begin(), nums.end());
        for(auto x : nums) {
            fre[x]++;
        }
        while(k--) {
            int maxN = -1;
            int maxPos = -1;
            for(auto [key, val] : fre) {
                if(val > maxN) {
                    maxPos = key;
                    maxN = val;
                }
            }
            fre[maxPos] = 0;
            result.push_back(maxPos);
        }
        sort(result.begin(), result.end());
        return result;
    }
};
