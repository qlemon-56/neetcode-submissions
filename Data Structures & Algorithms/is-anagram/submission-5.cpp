#include <algorithm>

class Solution {
public:
    bool isAnagram(string s, string t) {

        int v = static_cast<int>(s.size()) ;
        if (v != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s!=t) return false;

        return true;
    }
};
