class Solution {
public:
    int partition(vector<vector<int>>& intervals, int left, int right) {
        int pivot = intervals[(left + right) / 2][1];

        int i = left;
        int j = right;

        while (true) {
            while (intervals[i][1] < pivot) {
                i++;
            }

            while (intervals[j][1] > pivot) {
                j--;
            }

            if (i >= j) {
                return j;
            }

            swap(intervals[i], intervals[j]);
            i++;
            j--;
        }
    }

    void quickSort(vector<vector<int>>& intervals, int left, int right) {
        if (left >= right) {
            return;
        }

        int pIndex = partition(intervals, left, right);

        quickSort(intervals, left, pIndex);
        quickSort(intervals, pIndex + 1, right);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        quickSort(intervals, 0, intervals.size() - 1);

        int removed = 0;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                removed++;
            } else {
                end = intervals[i][1];
            }
        }

        return removed;
    }
};
