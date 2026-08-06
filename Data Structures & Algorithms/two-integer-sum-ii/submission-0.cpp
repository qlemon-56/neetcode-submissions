class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // given an array sorted in non decreasing order --> ascending order
        // return the indices of 2 numbers such that they add up to a target
        // isnt this two sum? lmfao

        int a {0};
        int b = numbers.size()-1;
        while ((numbers[a] + numbers[b]) != target) {
            if ((numbers[a] + numbers[b]) < target) {
                a++;
            } else {
                b--;
            }
        }

        return {a+1, b+1};
    }   
};
