class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int pivot = left;

        auto start = nums.begin();
        auto end = nums.end();
        
        if (target >= nums[pivot] && target <= nums[nums.size() - 1]) {
            start = nums.begin() + pivot;
        } else {
            end = nums.begin() + pivot;
        }

        auto it = lower_bound(start, end, target);

        if (it != end && *it == target) {
            return distance(nums.begin(), it);
        }

        return -1; 
    }
};
