class Solution {
   public:
    vector<int> space{}, temp{};
    vector<vector<int>> res{};
    set<vector<int>> seen{};
    int limit{0};

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        space = nums;
        limit = nums.size();

        subset(0);
        return res;
    }

    void subset(int i) {
        if (i == limit) {
            if (seen.count(temp) == 0) {
                res.push_back(temp);
                seen.insert(temp);
            }
        } else {
            // call function
            subset(i + 1);
            // take action
            temp.push_back(space[i]);
            // call function
            subset(i + 1);
            // undo action
            temp.pop_back();
        }
    }
};
