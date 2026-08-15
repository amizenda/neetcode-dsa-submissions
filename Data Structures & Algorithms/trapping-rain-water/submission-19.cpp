class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxPos = -1;
        int maxHeight = 0;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            if(height[i] > maxHeight) {
                maxHeight = height[i];
                maxPos = i;
            }
        }

        int leftMax = height[0];
        for(int i = 1; i < maxPos; i++) {
            if(height[i] > leftMax) {
                leftMax = height[i];
            } else {
                sum += leftMax - height[i];
            }
        }

        int rightMax = height[n - 1];
        for(int i = n - 2; i > maxPos; i--) {
            if(height[i] > rightMax) {
                rightMax = height[i];
            } {
                sum += rightMax - height[i];
            }
        }

        return sum;
    }
};
