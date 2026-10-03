class Solution {
public:
    vector<int> pilez {};
    int minEatingSpeed(vector<int>& piles, int h) {
        pilez.insert(pilez.end(), piles.begin(), piles.end());
        // min hours needed is size of array -> max pile 
        // max hours is the given limit 
        int high = *max_element(piles.begin(), piles.end());
        int low = 1;
        int mid = (low+high)/2, prev = 0, best = 0;

        // high starts at 
        while (low <= high) {
            if (hoursTaken(mid) <= h) {
                high = mid;
                best = mid;
            } else {
                low = mid+1;
            }
            cout << mid << endl;
            // update mid
            mid = (low+high)/2;

            if (mid == prev) break;
            prev = mid;
        }
        return best;
    }

    int hoursTaken(int speed) {
        int time {0};
        for (size_t i = 0; i < pilez.size(); i++) {
            time += ceil((double)pilez[i]/speed);
        }
        return time;
    }
};
