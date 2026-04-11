class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int pre[n];
        int suf[n];
        int sum = 0;

        for(int i = 0; i < n; i++) {
            pre[i] = -1;
            suf[i] = -1;
        }

        for(int i = 0; i < n; i++) {
            if(i != 0) {
                pre[i] = max(pre[i - 1] , height[i - 1]);
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            if(i != n - 1) {
                suf[i] = max(suf[i + 1], height[i + 1]);
            }
        }

        for(int i = 0; i < n; i++) {
            if(pre[i] != -1 && suf[i] != -1 && pre[i] > height[i] && suf[i] > height[i]) {
                sum += min(pre[i], suf[i]) - height[i];
            }
        }

        return sum;
    }
};
