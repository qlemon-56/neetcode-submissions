class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded {};
        for (string str: strs) {
            encoded += to_string(str.length()) + "#" + str;   
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded {};
        string temp {};
        int count = 0;        
        while (count < s.length()) {
            int tracker {count};
            while (s[tracker] != '#') {
                tracker++;
            } 
            int lenofstr = stoi(s.substr(count, tracker-count));
            decoded.push_back(s.substr(tracker + 1, lenofstr));
            count = tracker+lenofstr+1;
        }
        return decoded;
    }
};
