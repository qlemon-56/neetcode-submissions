class Solution {
public:
    int maxDepth(string s) {
        int nestingDepth = 0, maxDepth = 0;
        for (auto &x : s) {
            if ( x == '(') {
                nestingDepth++;
                maxDepth = max(maxDepth, nestingDepth);
            } else if ( x == ')') {
                nestingDepth--;
            }
        }

        return maxDepth;
    }
};