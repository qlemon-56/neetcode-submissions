class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> b {};
            for (int c = 0; c < 9; c++) {
                if (board[i][c] != '.')
                    b.push_back(board[i][c]);
            }
            set<int> d(b.begin(), b.end());
            if (b.size() != d.size()) return false;
        }

        for (int i = 0; i < 9; i++) {
            vector<int> b {};
            for (int c = 0; c < 9; c++) {
                if (board[c][i] != '.')
                    b.push_back(board[c][i]);
            }
            set<int> d(b.begin(), b.end());
            if (b.size() != d.size()) return false;
        }

        for (int i = 0; i < 9; i+=3) {

            for (int j = 0; j < 9; j+=3) {

                vector<int> test{};

                for (int a = i; a < (i+3); a++) {
                    for (int b = j; b < (j+3); b++) {
                        if(board[a][b] != '.')
                            test.push_back(board[a][b]);
                    }
                }
                set<int> check(test.begin(), test.end());
                if (check.size() != test.size()) return false;
            }
        }

        return true;

    }
};
