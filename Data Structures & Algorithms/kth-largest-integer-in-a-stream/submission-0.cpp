class KthLargest {
public:
    vector<int> myHeap {};
    int c {};
    KthLargest(int k, vector<int>& nums) {
        myHeap.insert(myHeap.end(),nums.begin(), nums.end());
        make_heap(myHeap.begin(), myHeap.end());
        c = k;
    }
    
    int add(int val) {
        myHeap.push_back(val);
        make_heap(myHeap.begin(), myHeap.end());

        sort_heap(myHeap.begin(), myHeap.end());
        auto it1 = myHeap.end();
        for (int a = 0; a < c; a++) {
            it1--;
        }
        return *it1;        
    }
};
