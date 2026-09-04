class Solution {
   public:
    vector<string> res{};
    string space = "()";
    string temp{};

    vector<string> generateParenthesis(int n) {
        backtrack(0, n * 2);
        return res;
    }
    bool isNotEmpty() {
        int i{0}, count{0};
        while (i < temp.size()) {
            if (temp[i] == '(') {
                count++;
            } else {
                if (count == 0) {
                    return true;
                } else
                    count--;
            }
            i++;
        }
        // returns true if stack is not empty and false if empty
        return count != 0;
    }

    void backtrack(int i, int limit) {
        if (i == limit) {
            // need to validate string
            if (temp.back() == '(' || isNotEmpty()) return;
            res.push_back(temp);
            return;
        }

        for (int x = 0; x < 2; x++) {
            // take action
            temp.push_back(space[x]);
            // call function
            backtrack(i + 1, limit);
            // undo action
            temp.pop_back();
        }
    }
};
