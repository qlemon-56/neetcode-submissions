class Solution {
public:
    bool isPalindrome(string s) {
        
        string c = {}, d ={};

        for (int i =0; i<s.size(); i++) {
            if (static_cast<bool>(isalnum(s[i]))) c.push_back(std::tolower(s[i]));
        }

        d = {c};
        reverse(d.begin(), d.end());

        if ( d!= c) return false;
        return true;
    }
};
