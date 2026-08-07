class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> found {};
        set<vector<int>> checker {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int target {-nums[i]};
            int j {i+1};
            int k {static_cast<int>(nums.size()-1)};

            while (j < k) {
                if ((nums[j] + nums[k] == target) && checker.count({nums[i],nums[j],nums[k]}) == 0) {
                    found.push_back({nums[i], nums[j], nums[k]});
                    checker.insert({nums[i],nums[j],nums[k]});
                    j++;
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
