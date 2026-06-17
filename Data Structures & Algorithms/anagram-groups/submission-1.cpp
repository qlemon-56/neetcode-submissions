class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> store;
        int x = 0;

        while (x < strs.size()) {
            string key = strs[x];
            sort(key.begin(), key.end());
            if (store.contains(key)) {
                store.at(key).push_back(strs[x]);
                x++;
                continue;
            }
            store.insert({key, {strs[x]}});
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
