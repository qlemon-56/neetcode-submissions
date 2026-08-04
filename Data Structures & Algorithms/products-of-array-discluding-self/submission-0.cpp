class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixSum {}, suffixSum {};
        int multF {1}, multB {1};
        
        for (int i = 0; i < nums.size(); i++) {
            prefixSum.push_back(multF);
            suffixSum.insert(suffixSum.begin(), multB);
            multF*= nums[i];
            multB*= nums[nums.size()-i-1];
        }
        
        vector<int> result{};
        for (int x = 0; x < nums.size(); x++) {
            result.push_back(prefixSum[x] * suffixSum[x]);
        }

        return result;
    }
};
