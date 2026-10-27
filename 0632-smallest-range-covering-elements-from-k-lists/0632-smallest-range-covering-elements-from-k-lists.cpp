class Solution {
    class node {
    public:
        int data;
        int row;
        int col;
        node(int d, int r, int c) {
            data = d;
            row = r;
            col = c;
        }
    };

    class compare {
    public:
        bool operator()(node* a, node* b) { return a->data > b->data; }
    };

public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<node*, vector<node*>, compare> minheap;
        int k = nums.size();

        for (int i = 0; i < k; i++) {
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            minheap.push(new node(element, i, 0));
        }
        int start = mini, end = maxi;

        while (!minheap.empty()) {
            node* temp = minheap.top();
            minheap.pop();
            mini = temp->data;

            // range or answer updation
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }
            // next element exist
            if (temp->col + 1 < nums[temp->row].size()) {
                maxi = max(maxi, nums[temp->row][temp->col + 1]);
                minheap.push(new node(nums[temp->row][temp->col + 1], temp->row, temp->col + 1));

            } else {
                // next element does not exist
                break;
            }
        }
        vector<int> ans(2);
        ans[0] = start;
        ans[1] = end;
        return ans ;
    }
};