#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int>::iterator it1, it2;
        map<int, int> checked;

        for (int i = 0; i < nums.size(); i ++) {

            cout << nums[i] << i;
            if ( checked.count(target - nums[i]) != 0) {
                return { checked[ target - nums[i]], i};
            }
            checked.insert({ nums[i] , i});
            
        }


    }
};
