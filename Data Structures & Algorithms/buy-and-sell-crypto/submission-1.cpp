class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int maxProfit = 0;

        while(right < prices.size()) {
            int price = prices[right];
            if(price > prices[left]) {
                maxProfit = max(maxProfit, price - prices[left]);
            } else {
                left = right;
            }
            right++;
        }

        return maxProfit;
    }
};
