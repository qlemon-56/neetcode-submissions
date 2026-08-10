class Solution {
public:
    int maxArea(vector<int>& heights) {
        // area = (pos l - pos r) * (min(l, r))
        int it1 {0}, it2 = heights.size()-1;
        int maxArea {};
        while (it1 < it2 && (it2 < heights.size())) {
            maxArea = max(maxArea, abs(it1-it2)*min(heights[it1],heights[it2]));

            if (heights[it1] < heights[it2]) {
                it1++;
            } else {
                it2--;
            }
        }

        return maxArea;
    }
};
