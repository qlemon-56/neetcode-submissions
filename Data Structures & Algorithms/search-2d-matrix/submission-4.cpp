class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int arrL = 0, arrH = matrix.size() - 1;

        while (arrL <= arrH) {
            int mid = (arrL + arrH)/2;
            int singL = 0, singH = matrix[mid].size() - 1;

            if (target < *(matrix[mid].begin())) {
                arrH = mid - 1;
            } else if (target > *prev(matrix[mid].end())) {
                arrL = mid + 1;
            } else {
                while (singL <= singH) {
                    int singMid = (singL + singH) / 2;

                    if (matrix[mid][singMid] == target) {
                        return true;
                    } else if (target < matrix[mid][singMid]) {
                        singH = singMid - 1;
                    } else {
                        singL = singMid + 1;
                    }
                }
                return false;
            }
        }

        return false;
    }
};
