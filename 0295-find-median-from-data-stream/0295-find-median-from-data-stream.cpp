class MedianFinder {
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    double median = 0;

public:
    MedianFinder() {}

    int signum(int a, int b) {
        if (a == b)
            return 0;
        else if (a > b)
            return 1;
        else
            return -1;
    }

    void addNum(int num) {
        switch (signum(maxheap.size(), minheap.size())) {
            case 0:
                if (num > median) {
                    minheap.push(num);
                    median = minheap.top();
                } else {
                    maxheap.push(num);
                    median = maxheap.top();
                }
                break;

            case 1:
                if (num > median) {
                    minheap.push(num);
                } else {
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(num);
                }
                median = (maxheap.top() + minheap.top()) / 2.0;
                break;

            case -1:
                if (num > median) {
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push(num);
                } else {
                    maxheap.push(num);
                }
                median = (maxheap.top() + minheap.top()) / 2.0;
                break;
        }
    }

    double findMedian() {
        return median;
    }
};