class Solution {
public:
    int scoreOfString(string s) {
        int difx =0, i =0;

        while (i < s.size()-1) {
            difx += std::abs((s[i] - s[i+1]));
            i++;
        }

        return difx;
    }
};