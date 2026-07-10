class Solution {
public:
    int missingNumber(vector<int>& nums) {

        set<int> myNums = {};
        for (int n = 0; n < nums.size()+1; n++) myNums.insert(n);
        for (int &x: nums) {
            if (myNums.contains(x)) myNums.erase(x);
        }
        return *myNums.begin();
    }
};
