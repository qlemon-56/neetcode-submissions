class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());

        while (stones.size() > 1) {
            int a {stones.front()};
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();

            int b {stones.front()};
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            
            b = abs(a-b);
            
            if (b > 0) {
                stones.push_back(b);
                push_heap(stones.begin(), stones.end());
            }
        }
        if (stones.size() == 0) return 0;
        return stones.front();
    }
};

