class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int minimum {prices[0]}, best {0};
        
        for (int i = 0; i < prices.size(); i++) {
            best = max(best, prices[i] - minimum);
            minimum = min(minimum, prices[i]);
        }


        return best;
    }
};
