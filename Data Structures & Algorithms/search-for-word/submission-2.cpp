class Solution {
   public:
    string temp{}, _word{};
    set<pair<int,int>> path {};
    bool exist(vector<vector<char>>& board, string word) {
        _word = word;
        for (int x = 0; x < board.size(); x++) {
            for (int y = 0; y < board[0].size(); y++) {
                if (word[0] != board[x][y]) continue;
                if (backtrack(board, x, y, 0)) return true;
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>> space, int r, int c, int idx) {
        // check for match
        if (idx == _word.size()) return true;
        // check if it is in bounds
        if (r < 0 || r >= space.size() || c < 0 || c >= space[0].size() ||
            space[r][c] != _word[idx] || path.contains({r, c}))
            return false;

        // take action
        path.insert({r,c});

        // call functions
        bool foundWord = backtrack(space, r+1, c, idx + 1) || backtrack(space, r, c+1, idx + 1) ||
                         backtrack(space, r-1, c, idx + 1) || backtrack(space, r, c-1, idx + 1);

        // undo action
        path.erase({r,c});
        return foundWord;
    }
};
