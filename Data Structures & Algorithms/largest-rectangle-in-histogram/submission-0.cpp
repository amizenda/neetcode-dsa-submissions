class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        stack<int> heightIndex;
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            while (!heightIndex.empty() && heights[i] < heights[heightIndex.top()]) {
                int h = heights[heightIndex.top()];
                heightIndex.pop();
                int w;
                if(heightIndex.empty()) {
                    w = i;
                } else {
                    w = i - heightIndex.top() - 1;
                }
                
                maxArea = max(maxArea, h * w);
            }

            heightIndex.push(i);
        }

        return maxArea;
    }
};
