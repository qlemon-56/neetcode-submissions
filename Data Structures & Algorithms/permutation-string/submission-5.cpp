class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if (s2.size() < s1.size()) return false;
        multiset<char> seen(s1.begin(), s1.end());

        for (int i = 0; i <= s2.size()-s1.size(); i++) {
            multiset<char> temp(s2.begin()+i, s2.begin()+i+(s1.size()));
            if (temp==seen) return true;
        }
        return false;
                
    }
};
