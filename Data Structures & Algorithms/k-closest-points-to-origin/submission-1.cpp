class Comparator {
    public:
    int operator() (vector<int> pointA, vector<int> pointB) {
        return sqrt(pointA[0]*pointA[0]+pointA[1]*pointA[1]) > sqrt(pointB[0]*pointB[0]+pointB[1]*pointB[1]) ;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Comparator> magnitudes {};
        for (vector<int> x: points) {
            magnitudes.push(x);
        }
        vector<vector<int>> res {};
        for (int i = 0; i < k; i++) {
            res.push_back(magnitudes.top());
            magnitudes.pop();
        }

        return res;
        
    }
};
