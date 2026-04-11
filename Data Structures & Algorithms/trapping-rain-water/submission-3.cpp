class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int prefix[n];
        int suffix[n];
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            prefix[i] = -1;
            suffix[i] = -1;
        }

        for(int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], height[i - 1]);
        }

        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], height[i + 1]);
        }

        for(int i = 0; i < n; i++) {
            if(prefix[i] != -1 && suffix[i] != -1 && prefix[i] > height[i] && suffix[i] > height[i]) {
                sum += min(prefix[i], suffix[i]) - height[i];
            }
        }

        return sum;
    }
};
