class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.rbegin(), stones.rend());
        
        while (stones.size() != 1) {
            stones[0] = stones[0]-stones[1];
            stones[1] = 0;
            stones.erase(stones.begin() + 1);  
            sort(stones.rbegin(), stones.rend());
        }
        return stones[0];
    }
};
