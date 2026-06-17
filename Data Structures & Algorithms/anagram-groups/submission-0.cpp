class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> store;
        vector<string> sorted {strs};
        int x = 0;

        while (x < strs.size()) {

            sort(sorted[x].begin(), sorted[x].end());
            if (store.contains(sorted[x])) {
                store.at(sorted[x]).push_back(strs[x]);
                x++;
                continue;
            }
            store.insert({sorted[x], {strs[x]}});
            x++;
        }

        vector<vector<string>> res;
        unordered_map<string, vector<string>>::iterator it = store.begin();
        while (it != store.end()) {
            res.push_back((*it).second);
            it++;
        }

        return res;
    }
};
