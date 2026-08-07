class MedianFinder {
public:
    // Min heap stores the larger half of the numbers. - right side from median
    // The smallest number in the larger half is always on top.
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Max heap stores the smaller half of the numbers. - left side from median
    // The largest number in the smaller half is always on top.
    priority_queue<int> maxHeap;

    MedianFinder() {

    }

    void addNum(int num) {
        // If the min heap is empty OR
        // the new number belongs to the larger half,
        // put it into the min heap.
        if (minHeap.size() == 0 || minHeap.top() < num) {
            minHeap.push(num);
        }
        else {
            // Otherwise, it belongs to the smaller half.
            maxHeap.push(num);
        }

        // Balance the heaps.
        // Their sizes should never differ by more than 1.

        // If the left half has too many elements,
        // move its largest element to the right half.
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // If the right half has too many elements,
        // move its smallest element to the left half.
        else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        // If both heaps have the same number of elements,
        // the median is the average of the two middle numbers.
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        // Otherwise, the heap with more elements
        // contains the median.
        return maxHeap.size() > minHeap.size()
                ? maxHeap.top()
                : minHeap.top();
    }
};
