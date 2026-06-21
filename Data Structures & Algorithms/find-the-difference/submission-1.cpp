class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int c = 0; c <t.size(); c++) {
            if (s[c] == NULL) return t[c];
            if (s[c] != t[c]) {
                return t[c];
            }
        }
        return 'a';
    }
};