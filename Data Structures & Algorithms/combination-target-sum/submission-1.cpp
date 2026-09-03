class Solution {
public:
    int sum {};

    vector<vector<int>> res {};
    set<vector<int>> seen {};
    vector<int> temp {}, arr {};
    int targ {};
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        arr = nums;
        targ = target;
        backtrack(0);

        return res;
    }


    void backtrack(int n ) {

        if (sum == targ) {
            if (seen.count(temp) == 0) {
                res.push_back(temp);
            } 
        }

        for (int i = 0; i < arr.size(); i++) {
            
            // base condition for exit
            if (sum > targ) continue;
            if (temp.size()!=0) {
                if (temp.back() < arr[i]) continue;
            }
            // take action
            sum += arr[i];
            temp.push_back(arr[i]);
            // call with updated arg
            backtrack(n+1);
            // undo action
            sum -= arr[i];
            temp.pop_back();
        }


    }
};
