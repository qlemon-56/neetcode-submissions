class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count {1}, record {0}, prevNum {};
        if (nums.size() < 2) return nums.size();

        set <int> mySet(nums.begin(), nums.end());
        auto it = mySet.begin();
        while (it!=prev(mySet.end())) {
            prevNum = (*it);
            it++;
            if ((*it - prevNum) == 1) {
                count++;
            } else {
                record = max(record, count); 
                count = 1;
            }
        }
        record = max(record, count);
        return record;
    }        
};
