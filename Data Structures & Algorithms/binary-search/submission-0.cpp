class Solution {
public:
    int search(vector<int>& nums, int target) {
        int it1 = 0;
        int it2 = nums.size() - 1;

        while (it1 <= it2) {
            int mid = (it1 + it2)/2;

            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                it2 = mid-1;
            } else {
                it1 = mid+1;
            }
        }
        return -1;
    }
};
