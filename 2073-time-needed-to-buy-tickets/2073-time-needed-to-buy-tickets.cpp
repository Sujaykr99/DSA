class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        queue<pair<int, int>> q;

        for (int i = 0; i < tickets.size(); i++) {
            q.push({tickets[i], i});
        }

        int count = 0;
        while (!q.empty()) {

            auto i = q.front();

            if (i.second == k && i.first == 1) {

                count++;
                break;

            } else if (i.first == 1) {
                q.pop();
                count++ ;
            } else {
                q.pop();
                q.push({i.first - 1, i.second});
                count++;
            }
        }
        return count;
    }
};