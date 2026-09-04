class Solution {
   public:
    vector<string> res{};
    unordered_map<char, string> space = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                                         {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    int limit {0};
    string g_digits {};
    string temp {};
    vector<string> letterCombinations(string digits) { 
        limit = digits.length();
        g_digits = digits;
        
        backtrack(0);
        return res;
    }

    void backtrack(int i) {

        if (i == limit) {
            if (!temp.empty()) res.push_back(temp);
        }
        for (int x = 0; x < space[g_digits[i]].length(); x++) {
            
            // take action
            temp+= space[g_digits[i]][x];
            // call function
            backtrack(i+1);
            // undo action
            temp.pop_back();
        }
    }

};