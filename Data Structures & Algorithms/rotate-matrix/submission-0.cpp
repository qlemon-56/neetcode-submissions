class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // seems lika general method for rotation is to swap the row orders then swap diagonals
        for (size_t i = 0; i < matrix.size()/2; i++) {
            swap(matrix[i], matrix[matrix.size()-i-1]);
        }

        for (size_t x = 0; x < matrix.size(); x++) {
            for (size_t y = x; y < matrix.size(); y++) {
                cout << matrix[x][y]<< endl;
                swap(matrix[x][y], matrix[y][x]);
            }
        }
    }  
};
