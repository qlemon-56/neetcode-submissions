class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> found {};
        set<set<int>> knownIndexSets {};
        for (int i = 0; i < nums.size(); i++) {
            map<int, int> myIdx {};
            int target {0 - nums[i]};

            for (int j = 0; j < nums.size(); j++) {
                if (j == i) continue;
                if (myIdx.count(target - nums[j]) == 1) {
                    set<int> temp {nums[i], nums[j], nums[myIdx[target-nums[j]]]};
                    if (knownIndexSets.count(temp) == 0) {
                        knownIndexSets.insert(temp);
                        found.push_back({nums[i], nums[j], nums[myIdx[target-nums[j]]]});
                    }
                } else {
                    myIdx.insert({nums[j], j});
                }
            }
        }
        return found;
    }
};
