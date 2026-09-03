class Solution {
public:

    vector<vector<int>> res {};
    vector<int> temp {};
    vector<int> arr {};

    vector<vector<int>> subsets(vector<int>& nums) {
        arr = nums;
        subset(0);
        return res;   
    }

    void subset(int n) {
        if (n == arr.size()) {
            res.push_back(temp);
        } else {
            subset(n+1);
            temp.push_back(arr[n]);
            subset(n+1);
            temp.pop_back();
        }
    }

};
