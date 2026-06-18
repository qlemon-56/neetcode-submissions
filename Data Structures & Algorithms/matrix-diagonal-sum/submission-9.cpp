class Solution {
   public:
    int diagonalSum(vector<vector<int>>& mat) {
        int matSize = mat.size();
        int sum = 0, counter = 0;

        if (matSize % 2 == 1) {
            while (counter < matSize) {
                if (counter == matSize - counter - 1) {
                    sum += mat[counter][counter];
                    counter++;
                    continue;
                }

                sum += mat[counter][counter];
                sum += mat[counter][matSize - counter - 1];
                counter++;
            }
        } else {
            while (counter < matSize) {
                sum += mat[counter][counter];
                sum += mat[counter][matSize - counter - 1];
                counter++;
            }
        }

        return sum;
    }
};