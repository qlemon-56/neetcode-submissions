
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        if (nums.size() == 2) return {0, 1};
        std::unordered_map<int, int> checked;
        for (int i =0; i < nums.size(); i++) {
            if (checked.contains(target-nums[i])) {
                return {checked[target-nums[i]], i};
            }
            checked.insert({nums[i], i});
        }
        return {};
    }
};
