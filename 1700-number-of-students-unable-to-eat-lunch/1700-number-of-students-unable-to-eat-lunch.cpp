class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        queue<int> q;

        for (int i = 0; i < students.size(); i++) {

            q.push(students[i]);
        }
        int count = 0;

        int i = 0;

        while (!q.empty()) {

            if (q.front() == sandwiches[i]) {

                q.pop();
                i++;
                count = 0;

            }

            else {
                int student = q.front();
                q.pop();
                q.push(student);
                count++;
            }

            if (count == q.size()) {
                break;
            }
        }

        return q.size();
    }
};