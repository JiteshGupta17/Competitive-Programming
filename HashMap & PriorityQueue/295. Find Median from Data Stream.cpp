class MedianFinder {
public:
    /** initialize your data structure here. */

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {

    }

    void addNum(int num) {

        if (left.empty()) {
            left.push(num);
            return;
        }

        if (num >= left.top()) // only greater than symbol will also work
        {
            right.push(num);
            if (right.size() > left.size())
            {
                left.push(right.top());
                right.pop();
            }
        }
        else {

            left.push(num);
            if (left.size() > 1 + right.size())
            {
                right.push(left.top());
                left.pop();
            }

        }

    }

    double findMedian() {

        if (left.size() == right.size())
        {
            double ans = (left.top() + right.top()) / 2.0;
            return ans;
        }

        return left.top();
    }
};
