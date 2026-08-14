class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int numFleets {0};

        map<int,float> order {};
        for (int i = 0; i < position.size(); i++) 
            order.insert({position[i], (target-position[i])/static_cast<float>(speed[i])});

        stack<int> toPop {};
        for (auto x: order) {
            toPop.push(x.first);
        }

        float prevRec {0};
        while (toPop.size()!=0) {
            if (order[toPop.top()] <= prevRec) {
                toPop.pop();
            } else {
                numFleets++;
                prevRec = order[toPop.top()];
                toPop.pop();
            }
        }

        return numFleets;
    }
};
