#include <algorithm>
class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> myMap = {};
        multimap<int, int> nextMap = {};
        for (auto x: nums) {
            if ( myMap.contains(x) ) {
                myMap[x]++;
            } else {
                myMap.insert({x, 1});
            }
        }
        for (auto y :myMap) {
            nextMap.insert({y.second, y.first});
        }

        auto it = prev(nextMap.end());
        vector<int> res = {};
        
        while (k!=0) {
            res.push_back((*it).second);
            k--;
            it--;
        }

        return res;        
    }
};
