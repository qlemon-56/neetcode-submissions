class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int pC = 0;
        for (auto &word :words) {
            if (word.find(pref) == 0) pC += 1;
        }
        return pC;
    }
};