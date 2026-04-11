class Solution {
public:
    int maxArea(vector<int>& heights) {
        vector<int> heightSort = heights;
        int maxArea = -1;
        for(int i = heightSort.size() - 1; i >= 0; i--) {
            int left = 0;
            int right = heights.size() - 1;
            
            while(left < heights.size() &&  heights[left] < heightSort[i]) {
                left++;
            }

            while(left <= right && heights[right] < heightSort[i]) {
                right--;
            }

            if(left < right) {
                maxArea = max(maxArea, heights[i] * (right - left));
            }
        }
        return maxArea;
    }
};
