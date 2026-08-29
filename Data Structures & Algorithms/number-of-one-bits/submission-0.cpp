class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> myS {n};
        return myS.count();
    }
};
