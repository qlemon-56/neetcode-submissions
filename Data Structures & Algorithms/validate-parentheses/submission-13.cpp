class Solution {
public:
    bool isValid(string s) {
        if (s.size() < 2) return s.size() != 1;
        stack<char> test {};
        int i {0};
        while (i < s.size()) {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                test.push(s[i]);
            } else if (test.size() != 0 && ((s[i] == ')' && test.top() == '(') || (s[i] == ']' && test.top() == '[') || (s[i] == '}' && test.top() == '{'))) {
                test.pop();
            } else {
                return false;
            }
            i++;
        }
        if (test.size() == 0) return true;
        return false;
    }
};
