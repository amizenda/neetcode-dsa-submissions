class Solution {
public:
    int trap(vector<int>& height) {
        int maxPos = -1;
        int maxHeight = 0;
        int sum = 0;

        if (height.empty()) return 0;

        for(int i = 0; i < height.size(); i++) {
            if(height[i] > maxHeight) {
                maxPos = i;
                maxHeight = height[i];
            }
        }
        int leftMax = height[0];
        for(int i = 1; i < maxPos; i++) {
            if(height[i] >= leftMax) {
                leftMax = height[i];
            } else {
                sum += leftMax - height[i];
            }
        }

        int rightMax = height[height.size() - 1];
        for(int i = height.size() - 2; i > maxPos; i--) {
            if(height[i] >= rightMax) {
                rightMax = height[i];
            } else {
                sum += rightMax - height[i];
            }
        }

        return sum;
    }
};
