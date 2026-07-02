class Solution {
   public:
    int maxDifference(string s) {
        vector<int> freqs(26);

        for (auto x : s) {
            freqs[x - 'a'] += 1;
        }
        sort(freqs.begin(), freqs.end());
        int max_element = 0, min_element = 101;
        for (int c = 25; c >= 0; c--) {
            if (freqs[c] % 2 == 1) {
                max_element = max(max_element, freqs[c]);
            } else {
                if (freqs[c] != 0) {
                    min_element = min(min_element, freqs[c]);
                }
            }
        }

        return max_element - min_element;
    }
};