class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int maxProfit = 0;

        while(right < prices.size()) {
            int price = prices[right];

            if(price < prices[left]) {
                left = right;
            } else {
                maxProfit = max(maxProfit, price - prices[left]);
            }

            right++;
        }

        return maxProfit;
    }
};
