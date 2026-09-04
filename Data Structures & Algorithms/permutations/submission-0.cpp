class Solution {
   public:
    vector<vector<int>> res{};
    vector<int> temp{};
    vector<int> space{};
    vector<bool> chosen{};
    int lim{0};

    vector<vector<int>> permute(vector<int>& nums) {
        lim = nums.size();
        space = nums;
        chosen.resize(lim);

        permutation(0);
        return res;
    }

    void permutation(int i) {
        if (i == lim) {
            res.push_back(temp);
            return;
        }
        for (int x = 0; x < lim; x++) {
            if (chosen[x]) continue;
            // make a choice
            temp.push_back(space[x]);
            chosen[x] = true;
            // call function
            permutation(i+1);
            // undo the choice
            temp.pop_back();
            chosen[x] = false;
        }
    }
};
