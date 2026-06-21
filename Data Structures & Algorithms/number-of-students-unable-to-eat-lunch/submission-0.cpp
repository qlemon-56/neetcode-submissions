class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> sands;
        queue<int> student;

        for (int i = 0; i < sandwiches.size(); i++) {
            sands.push(sandwiches[sandwiches.size()-1-i]);
        }        

        for (auto& studen: students) {
            student.push(studen);
        }
        int cycle = 0;

        while (sands.size() != 0) {
            int temp = student.front();
            if (student.front() == sands.top()) {
                student.pop();
                sands.pop();
                cycle = 0;
            } else {
                student.pop();
                student.push(temp);
                cycle+=1;
                if ( cycle == student.size()) break;
            }
        }


        return student.size();
        
    }
};