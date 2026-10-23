class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }
        vector<string> ans(score.size());

        if (pq.size() > 0) {
            ans[pq.top().second] = "Gold Medal";
            pq.pop();
        }
        if (pq.size() > 0) {
            ans[pq.top().second] = "Silver Medal";
            pq.pop();
        }
        if (pq.size() > 0) {
            ans[pq.top().second] = "Bronze Medal";
            pq.pop();
        }

        for (int i = 4; pq.size() > 0; i++) {
            ans[pq.top().second] = to_string(i);
            pq.pop();
        }

        return ans;
    }
};