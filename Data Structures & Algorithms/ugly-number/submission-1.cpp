class Solution {
public:
    bool isUgly(int x) {
        if (x <= 0) return false;
        if (x == 1) return true;
        if (x % 2 == 0) {
            return isUgly(x / 2);
        } else if (x % 3 == 0) {
            return isUgly(x / 3);
        } else if (x % 5 == 0) {
            return isUgly(x / 5);
        } else {
            return false;
        }
    }
};