class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        do {
            if (n%2==1) count++;
        } while (n >>= 1);

        return count;
    }
};
