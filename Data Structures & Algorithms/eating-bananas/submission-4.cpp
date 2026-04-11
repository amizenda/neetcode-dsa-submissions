class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;

        for(int x : piles) {
            right = max(right, x);
        }

        int result = right;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            int totalHours = 0;
            for(int i = 0; i < piles.size(); i++) {
                totalHours += (piles[i] + mid - 1) / mid;
            }

            if(totalHours <= h) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};
