class Solution {
   public:
    vector<string> res{};
    string space = "()";
    string temp{};

    vector<string> generateParenthesis(int n) {
        backtrack(0, n * 2, 0);
        return res;
    }
    bool isNotEmpty() {
        int i = 0, count;
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

    void backtrack(int i, int limit, int bal) {
        if (i == limit) {
            // need to validate string
            if (bal != 0 || temp.back() == '(' || isNotEmpty()) return;
            res.push_back(temp);
            return;
        }

        for (int x = 0; x < 2; x++) {
            // take action
            bal += (space[x] == '(') ? 1 : -1;
            temp.push_back(space[x]);
            if (temp.front() == ')') return;

            // call function
            backtrack(i + 1, limit, bal);

            // undo action
            bal += (space[x] == '(') ? -1 : 1;
            temp.pop_back();
        }
    }
};
