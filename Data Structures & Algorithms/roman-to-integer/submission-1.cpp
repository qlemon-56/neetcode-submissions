class Solution {
public:
    int romanToInt(string s) {
        map<char, int> rNums = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int currentSum = 0;
      
        auto it = s.begin();
        for (int i = 0; i < s.size(); i++) {
            if (s[i+1] != NULL &&(rNums[s[i]] >= rNums[s[i+1]])) {
                currentSum += rNums[s[i]];
            } else if (s[i+1] != NULL &&(rNums[s[i]] < rNums[s[i+1]])){
                currentSum -= rNums[s[i]];
            } else currentSum += rNums[s[i]];
        }
        return currentSum;
    }
};