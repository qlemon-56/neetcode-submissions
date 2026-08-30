class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        auto it = prev(digits.end());
        int power{0}, num{0}, carry{0};
        do {
            int res = ++(*it);
            if (res == 10) {
                *it = 0;
                carry = 1;
            } else
                carry = 0;
            it--;
        } while (carry != 0 && it >= digits.begin());
        if (carry != 0) digits.insert(digits.begin(), 1);

        return digits;
    }
};
