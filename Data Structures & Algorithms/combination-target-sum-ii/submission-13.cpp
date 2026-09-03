class Solution {
   public:
    // helper variables
    int sum{0}, g_target{0};
    vector<int> cans{}, temp{};
    vector<bool> chosen{};
    vector<vector<int>> res{};

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        cans = candidates;
        g_target = target;
        chosen.resize(candidates.size());
        sort(cans.begin(), cans.end());
        backtrack();
        return res;
    }

    void backtrack() {
        if (sum == g_target) {
            res.push_back(temp);
        }
        for (int i = 0; i < cans.size(); i++) {
            if (chosen[i]) continue;
            if (cans[i] > g_target || cans[i]+sum > g_target) return;
            if (!temp.empty()) if (temp.back() < cans[i]) return;
            // take action
            temp.push_back(cans[i]);
            chosen[i] = true;
            sum += cans[i];
            // call func
            backtrack();
            // undo action
            temp.pop_back();
            chosen[i] = false;
            sum -= cans[i];
            while (i+1 < cans.size() && cans[i] == cans[i+1]) i++;

        }
    }
};
