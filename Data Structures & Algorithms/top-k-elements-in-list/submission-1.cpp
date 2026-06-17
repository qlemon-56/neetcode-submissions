#include <algorithm>
class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        multimap<int, int> store;
        unordered_map<int, int> temp;

        for (int& num : nums) {
            if (temp.contains(num)) {
                temp[num] += 1;
            }
            temp.insert({num, 1});
        }
        for (auto x: temp) {
            store.insert({x.second, x.first});
        }

        vector <int> res;
        auto v = store.rbegin();
        while (k != 0) {
            k--;
            res.push_back((*v).second);
            v++;
            
        }
        return res;        
    }
};
