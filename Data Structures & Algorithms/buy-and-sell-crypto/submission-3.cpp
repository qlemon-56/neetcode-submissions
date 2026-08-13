class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int start{0}, best{0};
        while (start < prices.size() - 1) {
            for (int end = start + 1; end < prices.size(); end++) {
                best = max(best, prices[end] - prices[start]);
            }
            start++;
        }

        return best;
    }
};
