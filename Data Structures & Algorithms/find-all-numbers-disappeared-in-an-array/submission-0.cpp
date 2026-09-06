class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res {};
        unordered_set<int> seen {};
        
        for (int i = 0; i < nums.size(); i++) {
            seen.insert(i+1);
        }


        for (auto& x : nums) {
            if (seen.count(x) != 0 && x <= nums.size()) seen.erase(x);
        }

        for (auto&c : seen) res.push_back(c);


        return res;
    }
};