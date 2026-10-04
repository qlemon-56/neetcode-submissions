class Solution {
public:
    struct mQ {
        int maxElement {INT_MIN};
        deque<int> elements {};
        int limit {};

        void insertElement(int newElement) {
            if (newElement >= maxElement) {
                maxElement = newElement;
            }

            elements.push_back(newElement);

            if (elements.size() > limit) {
                if (maxElement == elements.front()) {
                    elements.pop_front();
                    resetMax();
                } else {
                    elements.pop_front();
                }
            }
        }

        void resetMax() {
            maxElement = {*max_element(elements.begin(), elements.end())};
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        auto q = new mQ;
        q->limit = k;

        vector<int> res {};

        for (size_t i = 0; i < k; i++) {
            // say we have a monotonic queue
            q->insertElement(nums[i]);
        }

        for (size_t i = k; i < nums.size(); i++) {
            // say we have a monotonic queue
            res.push_back(q->maxElement);
            q->insertElement(nums[i]);
        }
        res.push_back(q->maxElement);
        

        return res;
    }
};
