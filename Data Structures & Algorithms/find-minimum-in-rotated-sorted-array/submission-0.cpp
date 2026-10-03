class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        return *min_element(nums.begin(), nums.end());
    }
};
