class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // if we have two asteroids when does a collision happen?
        // we would need asteroids [ n, n +1 ] with n having a +ve val and n+1 having a -ve val

        // how can we solve this problem then
        // my intuition is we will need a while loop with some cutoff condition
        // we could potentially cycle within the while loop with a for loop

        // so in each lop check if we have condition for collision
        // ok what does a pass through look like?
        // we have a stack storing elements weve gone over
        // at each step check if stack.top() is +ve and if head of vector/container is -ve
        // if it fulfills this do the collision through addition and get a val
        // if val is 0 just pop top and pop front
        // if val is +ve just push unto the stack and delete front of vector/container
        // if val is -ve like [-7, 5] pop stack and push val into it also pop vector
        // so in all cases pop both elements and push val unto the stack
        if (asteroids.size() < 2) return asteroids;
        stack<int> myS{};
        auto it = prev(asteroids.end());
        while (it >= asteroids.begin()) {
            myS.push(*it);
            it--;
        }
        stack<int> myP{};
        vector<int> res{};

        while (myS.size() != 0) {
            if (myP.size() == 0 && myS.size() >= 1) {
                myP.push(myS.top());
                myS.pop();
            }
            if (myS.size()==0) break;
            // p on this side <--- s on this side --->
            if (myP.top() > 0 && myS.top() < 0) {
                int val = static_cast<int>(myP.top() + myS.top());
                if (val == 0) {
                    myP.pop();
                    myS.pop();
                } else if (val < 0) {
                    myP.pop();
                } else {
                    myS.pop();
                }
            } else {
                myP.push(myS.top());
                myS.pop();
            }
        }

        while (myP.size() != 0) {
            res.push_back(myP.top());
            myP.pop();
        }
        reverse(res.begin(), res.end());
        while (myS.size() != 0) {
            res.push_back(myS.top());
            myS.pop();
        }
        return res;
    }
};