class Solution {
   public:
    set<int> seen{};
    bool isHappy(int n) {
        while (true) {
            int sum = 0;
            for (auto& x : digits(n)) sum += x * x;

            n = sum;
            if (sum == 1) return true;
            if (seen.count(sum) == 1) return false;
            seen.insert(sum);
        }

        return true;
    }

    vector<int> digits(int& n) {
        vector<int> res{};

        while (n >= 10) {
            res.push_back(n % 10);
            n = n / 10;
            cout << n << endl;
        }

        res.push_back(n);
        return res;
    }
};
