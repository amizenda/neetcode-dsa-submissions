class Solution {
public:
    int trap(vector<int>& height) {
        int maxPos = -1;
        int maxHeight = 0;
        int sum = 0;
        int n = height.size();

        for(int i = 0; i < n; i++) {
            if(height[i] > maxHeight) {
                maxHeight = height[i];
                maxPos = i;
            }
        }

        int maxLeft = height[0];
        for(int i = 1; i < maxPos; i++) {
            if(height[i] > maxLeft) {
                maxLeft = height[i];
            } else {
                sum += maxLeft - height[i];
            }
        }

        int maxRight = height[n - 1];
        for(int i = n - 2; i > maxPos; i--) {
            if(height[i] > maxRight) {
                maxRight = height[i];
            } else {
                sum += maxRight - height[i];
            }
        }

        return sum;
    }
};
