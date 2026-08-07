class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> found {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int target {-nums[i]};
            int j {i+1};
            int k {static_cast<int>(nums.size()-1)};
            if (i > 0 && nums[i] == nums[i-1]) continue;
            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    found.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (nums[j] == nums[j-1] && j < k) j++;
                } else if ((nums[j] + nums[k]) < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return found;
    }
};
